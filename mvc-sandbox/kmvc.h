#ifndef KMVC_H
#define KMVC_H
#include <KParts/MainWindow>
#include <QtGui/QKeyEvent>
#include <qtimer.h>
#include <kcmdlineargs.h>
#include <kparts/part.h>
#include <QStringList>
#include <QStringListModel>

namespace kmvc{
class kmvc : public KParts::MainWindow
{
Q_OBJECT

public:
	kmvc(QWidget *parent=0);
	// ~kmvc();
	void openProject(const QString&);
	// ~kmvc();
	void open(const QString&);
	void save();
	bool close(bool bForce = false);
	void verifyCscope();

private:
	void initCscope();
	void initMainWindow();
	void setupActions();
	bool openCscopeOut(const QString&);

   	QStringListModel *m_view;

private slots:

};
} // namespace kmvc

#endif // KMVC
