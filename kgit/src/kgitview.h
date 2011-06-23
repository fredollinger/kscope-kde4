 

#ifndef _KGITVIEW_H_
#define _KGITVIEW_H_

#include <qwidget.h>
#include <qdialog.h>
#include <qtimer.h>
#include <qlayout.h>
#include <qlabel.h>

#include <kparts/part.h>
#include <kprocio.h>

#include <kgitiface.h>
#include "kgitview_custom.h"

class QPainter;
class KURL;
class WaitDialog;

/**
 * This is the main view class for kgit.  Most of the non-menu,
 * non-toolbar, and non-statusbar (e.g., non frame) GUI code should go
 * here.
 *
 * @short Main view
 * @author Abhijit Bhopatkar <bainonline@gmail.com>
 * @version 0.1
 */
class kgitView : public kgitViewbase, public kgitIface
{
    Q_OBJECT
public:
	/**
	 * Default constructor
	 */
    kgitView(QWidget *parent);

	/**
	 * Destructor
	 */
    virtual ~kgitView();

    /**
     * Random 'get' function
     */
    QString currentURL();

    /**
     * Random 'set' function accessed by DCOP
     */
    virtual void openURL(QString url);

    /**
     * Random 'set' function
     */
    virtual void openURL(const KURL& url);

    /**
     * Print this view to any medium -- paper or not
     */
    void print(QPainter *, int height, int width);
    

signals:
    /**
     * Use this signal to change the content of the statusbar
     */
    void signalChangeStatusbar(const QString& text);

    /**
     * Use this signal to change the content of the caption
     */
    void signalChangeCaption(const QString& text);
private:
    KURL c_url;

private slots:
    void slotOnURL(const QString& url);
    void slotSetTitle(const QString& title);

private:
    KParts::ReadOnlyPart *m_html;
    KProcIO *gitProc;
    QStringList *commit_files;
    QStringList *branches;

public slots:
    void slotRefreshGitRepo();
    void slotGotGitTree(KProcess *);
    void slotGotGitDiff(KProcess *);
    void slotCommitCurrent();
    void slotGotGitBranches(KProcess *);
    void slotGitChangeBranch(const QString&);
    void slotGitBranchChanged(KProcess *);	
    void slotGitGotLogSummary(KProcIO *);
    void slotGitError(KProcess *,char *,int);
    void slotGitShowCommitDiff();
    void slotUpdateFilesToCommit();
    void slotUndoLastCommit();
    void slotRevertCommit();
    void slotCherryPickFromOther();
    void slotGitGotCheryPick(KProcess *);
    void slotGotGitCheryPickCommits(KProcess *);
    void slotDiscardChanges();
    void slotFileFilter(const QString &);
    void slotUndoFinished(KProcess *);
    void slotGitProcFinished(KProcess *);
    void slotSendPatch();
private:
    void debugBox(QString s);
    WaitDialog *wd;

    int busyWaiting;
    void setBusy();
    void busyDone();
};


class WaitDialog : public QDialog {
public:
  WaitDialog(int nwaiting, QWidget *p=0) : QDialog(p)
  {
    QVBoxLayout *l = new QVBoxLayout(this);
    QLabel *lab = new QLabel(this);
    lab->setText("Please Wait ... ");
    l->addWidget(lab);
    n_waiting=nwaiting;
  }

int exec()
{
  return QDialog::exec();
}

void addWait()
{
    n_waiting++;
}
void  doneWait() 
{
  n_waiting--;
  if(!n_waiting)
  	accept();
}

private:
  int n_waiting;
};

#endif // _KGITVIEW_H_
