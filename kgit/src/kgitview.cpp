#include "kgitview.h"

#include <stdio.h>

#include <iostream.h>

#include <qpainter.h>
#include <qlayout.h>
#include <qlineedit.h>

#include <kurl.h>

#include <ktrader.h>
#include <klibloader.h>
#include <kmessagebox.h>
#include <krun.h>
#include <klocale.h>
#include <ktextedit.h>
#include <kinputdialog.h>


#include <qbuttongroup.h>
#include <qcombobox.h>
#include <qlistview.h>
#include <qvaluelist.h>
#include <qmessagebox.h>
#include <qinputdialog.h>
#include <qcheckbox.h>
#include <qcursor.h>

kgitView::kgitView(QWidget *parent)
    : kgitViewbase(parent),
    DCOPObject("kgitIface")
{
  // setup our layout manager to automatically add our widgets
  QHBoxLayout *top_layout = new QHBoxLayout(this);
  top_layout->setAutoAdd(true);

  // we want to look for all components that satisfy our needs.  the
  // trader will actually search through *all* registered KDE
  // applications and components -- not just KParts.  So we have to
  // specify two things: a service type and a constraint
  //
  // the service type is like a mime type.  we say that we want all
  // applications and components that can handle HTML -- 'text/html'
  //
  // however, by itself, this will return such things as Netscape..
  // not what we wanted.  so we constrain it by saying that the
  // string 'KParts/ReadOnlyPart' must be found in the ServiceTypes
  // field.  with this, only components of the type we want will be
  // returned.
  KTrader::OfferList offers = KTrader::self()->query("text/plain", "'KParts/ReadWritePart' in ServiceTypes");

  KLibFactory *factory = 0;
  // in theory, we only care about the first one.. but let's try all
  // offers just in case the first can't be loaded for some reason
  KTrader::OfferList::Iterator it(offers.begin());
  for( ; it != offers.end(); ++it)
  {
    KService::Ptr ptr = (*it);

    // we now know that our offer can handle HTML and is a part.
    // since it is a part, it must also have a library... let's try to
    // load that now
    factory = KLibLoader::self()->factory( ptr->library() );
    if (factory)
    {
      m_html = static_cast<KParts::ReadWritePart *>(factory->create(this/*(QWidget *)layout4->parent()*/, ptr->name(), "KParts::ReadWritePart"));
      break;
    }
  }

  // if our factory is invalid, then we never found our component
  // and we might as well just exit now
  if (!factory)
  {
    KMessageBox::error(this, i18n("Could not find a suitable HTML component"));
    return;
  }

  //layout4->addWidget(m_html->widget());
  m_html->widget()->hide();
  connect(m_html, SIGNAL(setWindowCaption(const QString&)),
          this,   SLOT(slotSetTitle(const QString&)));
  connect(m_html, SIGNAL(setStatusBarText(const QString&)),
          this,   SLOT(slotOnURL(const QString&)));

	gitProc = new KProcIO;

	connect((QObject *)CommitButton,SIGNAL(clicked()),this,SLOT(slotCommitCurrent()));	
	connect((QObject *)DiscardChangesButton,SIGNAL(clicked()),this,SLOT(slotDiscardChanges()));	
	connect((QObject *)UndoCommitButton,SIGNAL(clicked()),this,SLOT(slotUndoLastCommit()));	
	connect((QObject *)RevertCommitButton,SIGNAL(clicked()),this,SLOT(slotRevertCommit()));	
	connect((QObject *)CherryPickFromOtherButton,SIGNAL(clicked()),this,SLOT(slotCherryPickFromOther()));	
	connect((QObject *)SendPatchButton,SIGNAL(clicked()),this,SLOT(slotSendPatch()));	
	
	connect(comboBoxBranches, SIGNAL(activated(const QString&)),this,SLOT(slotGitChangeBranch(const QString&)));

	connect(ShortLogList, SIGNAL(doubleClicked( QListViewItem *, const QPoint &, int ) ),this,SLOT(slotGitShowCommitDiff()));
	ShortLogList->setSorting(-1);

	connect(RepoTreeList, SIGNAL(selectionChanged()),this,SLOT(slotUpdateFilesToCommit()));
	connect(FileListFilterText, SIGNAL(textChanged ( const QString & )),this,SLOT(slotFileFilter(const QString &)));
	
	commit_files = new QStringList;
	branches = new QStringList;

	busyWaiting=0;
}

kgitView::~kgitView()
{}

void kgitView::print(QPainter *p, int height, int width)
{
  // do the actual printing, here	
  // p->drawText(etc..)
}

QString kgitView::currentURL()
{
  return c_url.url();//m_html->url().url();
}

void kgitView::openURL(QString url)
{
  openURL(KURL(url));
}

void kgitView::openURL(const KURL& url)
{
  c_url = url;
  slotRefreshGitRepo();
}

void kgitView::slotOnURL(const QString& url)
{
  emit signalChangeStatusbar(url);
}

void kgitView::slotSetTitle(const QString& title)
{
  emit signalChangeCaption(title);
}
#include "kgitview.moc"

/*!
    \fn kgitView::slotRefreshGitRepo()
 */
void kgitView::slotRefreshGitRepo()
{
    KProcIO *newProc = new KProcIO;
    *newProc << "git-diff-files";
    *newProc << "--name-only";
    newProc->setWorkingDirectory(c_url.path());
    connect(newProc,SIGNAL( processExited(KProcess *)),this,SLOT(slotGotGitTree(KProcess *)));
    newProc->start();
    MainDoc->clear();
    KProcIO *newProc2 = new KProcIO;
    *newProc2 << "git";
    *newProc2 << "diff";
    newProc2->setWorkingDirectory(c_url.path());
    connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotGotGitDiff(KProcess *)));
    newProc2->start();

    KProcIO *newProc3 = new KProcIO;
    *newProc3 << "git";
    *newProc3 << "branch";
    newProc3->setWorkingDirectory(c_url.path());
    connect(newProc3,SIGNAL( processExited(KProcess *)),this,SLOT(slotGotGitBranches(KProcess *)));
    newProc3->start();

    ShortLogList->clear();
    KProcIO *newProc4 = new KProcIO;
    *newProc4 << "git";
    *newProc4 << "log";
    newProc4->setWorkingDirectory(c_url.path());
    connect(newProc4,SIGNAL( readReady(KProcIO *)),this,SLOT(slotGitGotLogSummary(KProcIO *)));
    newProc4->start();	
    setBusy();
}



/*!
    \fn kgitView::slotGotGitDiff()
 */
void kgitView::slotGotGitDiff(KProcess *proc)
{	
   QString line;
   MainDoc->clear();
   while(((KProcIO *)proc)->readln(line) != -1) {
	if(line.startsWith("diff")) {
		MainDoc->setColor(QColor("blue"));
	} else if(line.startsWith("+")) {
		MainDoc->setColor(QColor("darkgreen"));
	} else if(line.startsWith("-")) {
		MainDoc->setColor(QColor("red"));
	} else {
		MainDoc->setColor(QColor("black"));
	}
	MainDoc->append(line);
   }
   delete (KProcIO *)proc;	
}



/*!
    \fn kgitView::slotGotGitTree()
 */
void kgitView::slotGotGitTree(KProcess *process)
{
   QString line;
   RepoTreeList->clear();
   while(((KProcIO *)process)->readln(line) != -1) {
	QListViewItem *item = new QListViewItem(RepoTreeList,line);
	RepoTreeList->insertItem(item);
   }
	delete (KProcIO *)process;
}


/*!
    \fn kgitView::slotCommitCurrent()
 */
void kgitView::slotCommitCurrent()
{
    QString Message;
   
    Message += "Committing Following files\n";
    for ( QStringList::Iterator it = commit_files->begin(); it != commit_files->end(); ++it ) {				Message += "\n\t";
		Message += *it;
    }
 
    Message += "\n\nContinue ?";
    

    QMessageBox mb( "kgit",
	Message,
        QMessageBox::Information,
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::Cancel | QMessageBox::Escape,
	0);
    mb.setButtonText( QMessageBox::Yes, "Commit" );
    mb.setButtonText( QMessageBox::No, "Cancel" );
    switch( mb.exec() ) {
	case QMessageBox::Yes:
		{
			bool ok;	
			QString log = KInputDialog::getMultiLineText("KGit", "Please enter commit log message:",QString::null, &ok, this );
			if (ok && !log.isEmpty() ) {
				
				KProcIO *newProc = new KProcIO;
				*newProc << "git-commit";
				
				*newProc << "-m" <<  log;
				
				for ( QStringList::Iterator it = commit_files->begin(); it != commit_files->end(); ++it ) {
						*newProc << *it;
				}
				
				newProc->setWorkingDirectory(c_url.path());
				connect(newProc,SIGNAL( processExited(KProcess *)),this,SLOT(slotRefreshGitRepo()));
				newProc->start();
			} else {
					// user entered nothing or pressed Cancel
			}
		}
		break;
	case QMessageBox::Cancel:
		break;
    }
}


/*!
    \fn kgitView::slotGotGitBranches(KProcess *proc)
 */
void kgitView::slotGotGitBranches(KProcess *proc)
{
   QString line;
   int current_branch=0,i=0;
   comboBoxBranches->clear();
   branches->clear();
   while(((KProcIO *)proc)->readln(line) != -1) {
	comboBoxBranches->insertItem(line);
	if(((const char *)line)[0] == '*') {
		current_branch=i;
	}
	branches->append(line);
	i++;
   }
   comboBoxBranches->setCurrentItem(current_branch);
   delete (KProcIO *)proc;	
}



/*!
    \fn kgitView::slotGitChangeBranch()
 */
void kgitView::slotGitChangeBranch(const QString& branch)
{
    QString s = branch;
    s.stripWhiteSpace ();
    KProcIO *newProc = new KProcIO;
    *newProc <<  "git-checkout";
    *newProc << &(((const char *)s)[2]);

    typedef QValueList<QCString> clist;
    clist list;
    list = newProc->args();
    clist::iterator it;
    for ( it = list.begin(); it != list.end(); ++it )
        cout << *it;

    newProc->setWorkingDirectory(c_url.path());
    connect(newProc,SIGNAL( processExited(KProcess *)),this,SLOT(slotGitBranchChanged(KProcess *)));
    newProc->start(KProcess::NotifyOnExit,true);
	setBusy();
}



/*!
    \fn kgitView::slotGitBranchChanged()
 */	
void kgitView::slotGitBranchChanged(KProcess *proc)
{
	QString line;
	while(((KProcIO *)proc)->readln(line) != -1) {
		//debugBox(line);
	}
	slotRefreshGitRepo();
	busyDone();
	delete (KProcIO *)proc;
}




/*!
    \fn kgitView::slotGitGotLogSummary()
 */

#define MAX_MESSAGES 100
void kgitView::slotGitGotLogSummary(KProcIO *proc)
{
   QString line;
   QStringList itemStrings;
   static QListViewItem *item;
   QString commit,author,date,shortlog;   
   static bool take_log=false;
   static int total_messages=0;

   if(ShortLogList->lastItem()==0) {
  	total_messages=0;
	take_log = false;
	item=0;
   }	
   while(((KProcIO *)proc)->readln(line) != -1) {
	if(total_messages > MAX_MESSAGES)
		break;
	if(line.startsWith("commit")) {
		total_messages++;
		item = new QListViewItem(ShortLogList);
		line.remove(0,7); // 7 == "commit "
		commit=line;
		take_log=true;
		shortlog = "";
		item->setText(3,commit);
	} else if (line.find(QString("Author:")) == 0) {
		line.remove(0,8); // 7 == "Author: "
		author=line;
		if(item)
			item->setText(1,author);
	} else if (line.find(QString("Date: ")) == 0) {
		line.remove(0,6); //6 == "Date: "
		date=line;
		if(item)
			item->setText(2,date);
	} else {
		if(take_log) {
			if(line.length() > 1) {
				shortlog = line;
				take_log=false;
			}
			if(item)
				item->setText(0,shortlog);
		}
	}
  	
   }

   if(total_messages > MAX_MESSAGES) {
	proc->kill();
	delete proc;
   } 

   if(!((KProcIO *)proc)->isRunning()) {
	busyDone();
   }
   return;
}


/*!
    \fn kgitView::slotGitError(KProcess *,char *,int)
 */
void kgitView::slotGitError(KProcess *proc,char *buf,int length)
{
   debugBox("Error: " + QString(buf));
}


/*!
    \fn kgitView::slotShowCommitDiff()
 */
void kgitView::slotGitShowCommitDiff()
{
    QListViewItem *item = ShortLogList->selectedItem();
    QString commit_id;
    commit_id = item->text(3);


    KProcIO *newProc2 = new KProcIO;
    *newProc2 << "git";
    *newProc2 << "show";
    *newProc2 << commit_id;
    newProc2->setWorkingDirectory(c_url.path());
    connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotGotGitDiff(KProcess *)));
    newProc2->start();

}


/*!
    \fn kgitView::slotUpdateFilesToCommit()
 */
void kgitView::slotUpdateFilesToCommit()
{
	QListViewItem *item = RepoTreeList->currentItem();
	if(RepoTreeList->isSelected(item)) {
			commit_files->append(item->text(0));
	} else { 
		
		for ( QStringList::Iterator it = commit_files->begin(); it != commit_files->end(); ++it ) {		
        		if(*it == item->text(0)) {
				commit_files->remove(it);
				break;
			}
		}
	}
	
	KProcIO *newProc2 = new KProcIO;
	*newProc2 << "git-diff";
	for ( QStringList::Iterator it = commit_files->begin(); it != commit_files->end(); ++it ) {
		*newProc2 << *it;
        } 
	newProc2->setWorkingDirectory(c_url.path());
	connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotGotGitDiff(KProcess *)));

	newProc2->start();

}


/*!
    \fn kgitView::slotUndoLastCommit()
 */
void kgitView::slotUndoLastCommit()
{
	 QMessageBox mb( "kgit",
	"This will undo the last commit, Are you sure?",
        QMessageBox::Information,
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::Cancel | QMessageBox::Escape,
	0);
	mb.setButtonText( QMessageBox::Yes, "Undo" );
	mb.setButtonText( QMessageBox::No, "Cancel" );
	switch( mb.exec() ) {
		case QMessageBox::Yes:
			{
				KProcIO *newProc2 = new KProcIO;
				*newProc2 << "git-reset";
				*newProc2 << "HEAD^";
				newProc2->setWorkingDirectory(c_url.path());
				connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotUndoFinished(KProcess *)));
				newProc2->start();
			}
			break;
		case QMessageBox::Cancel:
			break;
	}

}


/*!
    \fn kgitView::slotUndoFinished(KProcess *)
 */
void kgitView::slotUndoFinished(KProcess *proc)
{
    delete (KProcIO *)proc;
    slotRefreshGitRepo();

}


/*!
    \fn kgitView::debugBox(QString s)
 */
void kgitView::debugBox(QString s)
{
	 QMessageBox mb( "kgit",
			s,
			QMessageBox::Information,
			QMessageBox::Yes | QMessageBox::Default,
			0,0);
	mb.setButtonText( QMessageBox::Yes, "OK" );
	mb.exec();
}


/*!
    \fn kgitView::slotRevertCommit()
 */
void kgitView::slotRevertCommit()
{
	QListViewItem *item = ShortLogList->currentItem();
	QString commit = item->text(3);
	QString log = item->text(0);
	
	QString message;
	message += " This will revert the following commit \n\t";
	message +=  commit + "\n\t";
	message +=  log + "\n";
	message +=  "Are You sure?";
	
	QMessageBox mb( "kgit",
	message,
        QMessageBox::Information,
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::Cancel | QMessageBox::Escape,
	0);
	mb.setButtonText( QMessageBox::Yes, "Revert" );
	mb.setButtonText( QMessageBox::No, "Cancel" );
	switch( mb.exec() ) {
		case QMessageBox::Yes:
			{
				KProcIO *newProc2 = new KProcIO;
				*newProc2 << "git-revert";
				*newProc2 << item->text(3);
				newProc2->setWorkingDirectory(c_url.path());
				connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotRefreshGitRepo()));
				newProc2->start();
			}
			break;
		case QMessageBox::Cancel:
			break;
	}



}


/*!
    \fn kgitView::slotCherryPickFromOther()
 */
void kgitView::slotCherryPickFromOther()
{	
    bool ok;
    QString branch = QInputDialog::getItem(
            "KGit", "Select a branch to cherry pick from:", *branches, 1, TRUE, &ok,
            this );
    if ( ok ) {
	KProcIO *newProc2 = new KProcIO;
	*newProc2 << "git-cherry";
	*newProc2 << "-v";
	*newProc2 << "HEAD";
	*newProc2 << branch.stripWhiteSpace();
	newProc2->setWorkingDirectory(c_url.path());
	connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotGotGitCheryPickCommits(KProcess *)));
	
	connect(newProc2,SIGNAL(receivedStderr(KProcess *, char *,int)),this,SLOT(slotGitError(KProcess *,char *,int)));	

	newProc2->start();
	
   }
}


/*!
    \fn kgitView::slotGotGitCheryPickCommits(KProcess *)
 */
void kgitView::slotGotGitCheryPickCommits(KProcess *proc)
{
	QString line;
	QStringList commits; 
	bool ok=false;

	while((((KProcIO *)proc)->readln(line)) != -1) {
	    if(line.startsWith("+"))
	    	commits << line.section(" ",1);
	} 
	
        QString commit = QInputDialog::getItem(
            "KGit", "Select a commit to cherry pick", commits, 1, TRUE, &ok,
            this );
	if(ok) {
		KProcIO *newProc2 = new KProcIO;
		*newProc2 << "git-cherry-pick";
		*newProc2 << commit.section(" ",0,0);
		newProc2->setWorkingDirectory(c_url.path());
		connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotGitGotCheryPick(KProcess *)));
		connect(newProc2,SIGNAL(receivedStderr(KProcess *, char *,int)),this,SLOT(slotGitError(KProcess *,char *,int)));	
	
		newProc2->start();
		}
	delete (KProcIO *)proc;
}


/*!
    \fn kgitView::slotGitGotCheryPick(KProcess *)
 */
void kgitView::slotGitGotCheryPick(KProcess *proc)
{
  delete (KProcIO *)proc;
  slotRefreshGitRepo();
}


/*!
    \fn kgitView::slotDiscardChanges()
 */
void kgitView::slotDiscardChanges()
{
	QMessageBox mb( "kgit",
	"This will discard all changes you made to files IRRICOVERABLY, are you sure?",
        QMessageBox::Information,
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::Cancel | QMessageBox::Escape,0);
	mb.setButtonText( QMessageBox::Yes, "Discard" );
	mb.setButtonText( QMessageBox::No, "Cancel" );
	switch( mb.exec() ) {
		case QMessageBox::Yes:
			{
				KProcIO *newProc2 = new KProcIO;
				*newProc2 << "git-reset";
				*newProc2 << "--hard";
				*newProc2 << "HEAD";
				newProc2->setWorkingDirectory(c_url.path());
				connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotRefreshGitRepo()));
				
				connect(newProc2,SIGNAL(receivedStderr(KProcess *, char *,int)),this,SLOT(slotGitError(KProcess *,char *,int)));	
				
				newProc2->start();
			}
			break;
		case QMessageBox::Cancel:
			break;
	}

}


/*!
    \fn kgitView::slotFileFilter(const QString &)
 */
void kgitView::slotFileFilter(const QString &)
{
	 QListViewItemIterator it( RepoTreeList );
	if(FilterMode->isChecked()) {
		for ( ; it.current(); ++it ) {
			if ( it.current()->text(0).contains(FileListFilterText->text())) {
				it.current()->setVisible(false);
			} else {
				it.current()->setVisible(true);	
			}
		}
	} else {
		for ( ; it.current(); ++it ) {
			if ( it.current()->text(0).contains(FileListFilterText->text())) {
				it.current()->setVisible(true);
			} else {
				it.current()->setVisible(false);
			}
		}
	}
}


/*!
    \fn kgitView::slotSendPatch()
 */
void kgitView::slotSendPatch()
{
        QListViewItem *item = ShortLogList->currentItem();
	QString commit = item->text(3);
	QString log = item->text(0);
	
	QString message;
	message += " This will send follwing commit using kmail \n\t";
	message +=  commit + "\n\t";
	message +=  log + "\n";
	message +=  "Are You sure?";
	
	QMessageBox mb( "kgit",
	message,
        QMessageBox::Information,
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::Cancel | QMessageBox::Escape,
	0);
	mb.setButtonText( QMessageBox::Yes, "Send" );
	mb.setButtonText( QMessageBox::No, "Cancel" );
	switch( mb.exec() ) {
		case QMessageBox::Yes:
			{
				KProcIO *newProc2 = new KProcIO;
				*newProc2 << "git-show";
				*newProc2 << item->text(3);
				newProc2->setWorkingDirectory(c_url.path());
				connect(newProc2,SIGNAL( processExited(KProcess *)),this,SLOT(slotGitSendCommitDiff(KProcess *)));
				newProc2->start();
				setBusy();
			}
			break;
		case QMessageBox::Cancel:
			break;
	}

}


/*!
    \fn kgitView::slotGitProcFinished(KProcess *)
 */
void kgitView::slotGitProcFinished(KProcess *process)
{
    KProcIO *procio = (KProcIO *)process;
    delete procio;
}


void kgitView::setBusy()
{  
    if(!busyWaiting) {
	QApplication::setOverrideCursor( QCursor(Qt::WaitCursor) );
    	setDisabled(true);
    }
    busyWaiting++;
}


void kgitView::busyDone()
{
	if(busyWaiting)
		busyWaiting--;
	if(!busyWaiting) {
		QApplication::restoreOverrideCursor();
		setDisabled(false);
	}
}