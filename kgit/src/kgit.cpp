

#include "kgit.h"
#include "pref.h"

#include <stdio.h>

#include <qdragobject.h>
#include <kprinter.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>

#include <kglobal.h>
#include <klocale.h>
#include <kiconloader.h>
#include <kdeversion.h>
#include <kstatusbar.h>
#include <kaccel.h>
#include <kio/netaccess.h>
#include <kfiledialog.h>
#include <kconfig.h>
#include <kurl.h>
#include <kurldrag.h>
#include <kurlrequesterdlg.h>
#include <kdirselectdialog.h>

#include <kstdaccel.h>
#include <kaction.h>
#include <kstdaction.h>
#include <kmenubar.h>

kgit::kgit()
    : KMainWindow( 0, "kgit" ),
      m_view(new kgitView(this)),
      m_printer(0)
{
    // accept dnd
    setAcceptDrops(true);

    // tell the KMainWindow that this is indeed the main widget
    setCentralWidget(m_view);

    // then, setup our actions
    setupActions();

    // and a status bar
    statusBar()->show();

    // Apply the create the main window and ask the mainwindow to
		// automatically save settings if changed: window size, toolbar
    // position, icon size, etc.  Also to add actions for the statusbar
		// toolbar, and keybindings if necessary.
    setupGUI();

    menuBar()->hide();
    toolBar()->hide();
	
    // allow the view to change the statusbar and caption
    connect(m_view, SIGNAL(signalChangeStatusbar(const QString&)),
            this,   SLOT(changeStatusbar(const QString&)));
    connect(m_view, SIGNAL(signalChangeCaption(const QString&)),
            this,   SLOT(changeCaption(const QString&)));

   QString path=QDir::homeDirPath () + "/.kgit";
   printf("\nThe config file path is %s\n",(const char *)path);
   config2 = new KConfig(path);
   QString url = config2->readPathEntry("lastURL2");

   if (!url.isEmpty())
        m_view->openURL(KURL(url));

}

kgit::~kgit()
{
    config2->writePathEntry("lastURL2", m_view->currentURL());
    delete config2;
}

void kgit::load(const KURL& url)
{
    QString target;
    // the below code is what you should normally do.  in this
    // example case, we want the url to our own.  you probably
    // want to use this code instead for your app

    #if 0
    // download the contents
    if (KIO::NetAccess::download(url, target))
    {
        // set our caption
        setCaption(url);

        // load in the file (target is always local)
        loadFile(target);

        // and remove the temp file
        KIO::NetAccess::removeTempFile(target);
    }
    #endif

    setCaption(url.prettyURL());
    m_view->openURL(url);
    m_view->slotRefreshGitRepo();
	
}

void kgit::setupActions()
{
    KStdAction::openNew(this, SLOT(fileNew()), actionCollection());
    KStdAction::open(this, SLOT(fileOpen()), actionCollection());
    KStdAction::save(this, SLOT(fileSave()), actionCollection());
    KStdAction::saveAs(this, SLOT(fileSaveAs()), actionCollection());
    KStdAction::print(this, SLOT(filePrint()), actionCollection());
    KStdAction::quit(kapp, SLOT(quit()), actionCollection());

    KStdAction::preferences(this, SLOT(optionsPreferences()), actionCollection());

    // this doesn't do anything useful.  it's just here to illustrate
    // how to insert a custom menu and menu item
    KAction *custom = new KAction(i18n("Cus&tom Menuitem"), 0,
                                  this, SLOT(optionsPreferences()),
                                  actionCollection(), "custom_action");
}

void kgit::saveProperties(KConfig *config)
{
    // the 'config' object points to the session managed
    // config file.  anything you write here will be available
    // later when this app is restored

    if (!m_view->currentURL().isEmpty()) {
#if KDE_IS_VERSION(3,1,3)
        config->writePathEntry("lastURL", m_view->currentURL());
#else
        config->writeEntry("lastURL", m_view->currentURL());
#endif
    }
}

void kgit::readProperties(KConfig *config)
{
    // the 'config' object points to the session managed
    // config file.  this function is automatically called whenever
    // the app is being restored.  read in here whatever you wrote
    // in 'saveProperties'

    QString url = config->readPathEntry("lastURL");

    if (!url.isEmpty())
        m_view->openURL(KURL(url));
}

void kgit::dragEnterEvent(QDragEnterEvent *event)
{
    // accept uri drops only
    event->accept(KURLDrag::canDecode(event));
}

void kgit::dropEvent(QDropEvent *event)
{
    // this is a very simplistic implementation of a drop event.  we
    // will only accept a dropped URL.  the Qt dnd code can do *much*
    // much more, so please read the docs there
    KURL::List urls;

    // see if we can decode a URI.. if not, just ignore it
    if (KURLDrag::decode(event, urls) && !urls.isEmpty())
    {
        // okay, we have a URI.. process it
        const KURL &url = urls.first();

        // load in the file
        load(url);
    }
}

void kgit::fileNew()
{
    // this slot is called whenever the File->New menu is selected,
    // the New shortcut is pressed (usually CTRL+N) or the New toolbar
    // button is clicked

    // create a new window
    (new kgit)->show();
}

void kgit::fileOpen()
{
    // this slot is called whenever the File->Open menu is selected,
    // the Open shortcut is pressed (usually CTRL+O) or the Open toolbar
    // button is clicked
/*
    // this brings up the generic open dialog
    KURL url = KURLRequesterDlg::getURL(QString::null, this, i18n("Open Location") );
*/
    // standard filedialog
    KURL url = KDirSelectDialog::selectDirectory(QString::null, true,this, i18n("Open Location"));
    if (!url.isEmpty())
        m_view->openURL(url);
}

void kgit::fileSave()
{
    // this slot is called whenever the File->Save menu is selected,
    // the Save shortcut is pressed (usually CTRL+S) or the Save toolbar
    // button is clicked

    // save the current file
}

void kgit::fileSaveAs()
{
    // this slot is called whenever the File->Save As menu is selected,
    KURL file_url = KFileDialog::getSaveURL();
    if (!file_url.isEmpty() && file_url.isValid())
    {
        // save your info, here
    }
}

void kgit::filePrint()
{
    // this slot is called whenever the File->Print menu is selected,
    // the Print shortcut is pressed (usually CTRL+P) or the Print toolbar
    // button is clicked
    if (!m_printer) m_printer = new KPrinter;
    if (m_printer->setup(this))
    {
        // setup the printer.  with Qt, you always "print" to a
        // QPainter.. whether the output medium is a pixmap, a screen,
        // or paper
        QPainter p;
        p.begin(m_printer);

        // we let our view do the actual printing
        QPaintDeviceMetrics metrics(m_printer);
        m_view->print(&p, metrics.height(), metrics.width());

        // and send the result to the printer
        p.end();
    }
}

void kgit::optionsPreferences()
{
    // popup some sort of preference dialog, here
    kgitPreferences dlg;
    if (dlg.exec())
    {
        // redo your settings
    }
}

void kgit::changeStatusbar(const QString& text)
{
    // display the text on the statusbar
    statusBar()->message(text);
}

void kgit::changeCaption(const QString& text)
{
    // display the text on the caption
    setCaption(text);
}
#include "kgit.moc"
