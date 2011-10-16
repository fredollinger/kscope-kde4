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
}

vcsCommitDlg::~vcsCommitDlg() 
{
}
} // namespace kscope4

// Sat Oct 15 17:20:27 PDT 2011
