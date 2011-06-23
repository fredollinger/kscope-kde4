

#ifndef _KGIT_H_
#define _KGIT_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kapplication.h>
#include <kmainwindow.h>

#include "kgitview.h"
#include "kgitview_custom.h"

class KPrinter;
class KURL;

/**
 * This class serves as the main window for kgit.  It handles the
 * menus, toolbars, and status bars.
 *
 * @short Main window class
 * @author Abhijit Bhopatkar <bainonline@gmail.com>
 * @version 0.1
 */
class kgit : public KMainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    kgit();

    /**
     * Default Destructor
     */
    virtual ~kgit();

    /**
     * Use this method to load whatever file/URL you have
     */
    void load(const KURL& url);

protected:
    /**
     * Overridden virtuals for Qt drag 'n drop (XDND)
     */
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);

protected:
    /**
     * This function is called when it is time for the app to save its
     * properties for session management purposes.
     */
    void saveProperties(KConfig *);

    /**
     * This function is called when this app is restored.  The KConfig
     * object points to the session management config file that was saved
     * with @ref saveProperties
     */
    void readProperties(KConfig *);


private slots:
    void fileNew();
    void fileOpen();
    void fileSave();
    void fileSaveAs();
    void filePrint();
    void optionsPreferences();

    void changeStatusbar(const QString& text);
    void changeCaption(const QString& text);

private:
    void setupAccel();
    void setupActions();

private:
    kgitView *m_view;

    KPrinter   *m_printer;

    KConfig *config2;

};

#endif // _KGIT_H_

