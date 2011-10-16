#include <QDialog>

#include "vcsCommitDlg.h"
#include "vcsCommitLayout.h"

#include "qdebug.h"

namespace kscope4{
vcsCommitDlg::vcsCommitDlg(QWidget* pParent, const char* szName) : 
	 Ui::vcsCommitLayout() 
{
	qDebug() << "vcsCommitDlg() constructor \n";

	setupUi(this);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(slotCommit()));
// /home/follinge/projects/kscope-kde4/src/vcsCommitDlg.cpp :18:77: error: no matching function for call to ‘kscope4::vcsCommitDlg::connect(QDialogButtonBox::StandardButton, const char [11], kscope4::vcsCommitDlg* const, const char [14])’
// /usr/include/qt4/QtCore/qobject.h:198:17: note: candidates are: static bool QObject::connect(const QObject*, const char*, const QObject*, const char*, Qt::ConnectionType)
	// connect(QDialogButtonBox::Ok, SIGNAL(clicked()), this, SLOT(slotCommit() ) );
}

vcsCommitDlg::~vcsCommitDlg() 
{
}

void vcsCommitDlg::slotCommit(){
	qDebug() << "slotcommit";
}

} // namespace kscope4
// Sat Oct 15 17:20:27 PDT 2011
