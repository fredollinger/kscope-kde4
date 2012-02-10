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

	// create persistent version control process
	m_pVcs = new vcsFrontEnd(pParent);

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(slotCommit()));
}

vcsCommitDlg::~vcsCommitDlg() 
{
}

void vcsCommitDlg::slotCommit(){
	qDebug() << "slotcommit: "<< textCommitMsg->toPlainText();

	m_pVcs->commit(m_sSourceRoot, textCommitMsg->toPlainText() );
	close();
}

void vcsCommitDlg::setSourceRoot(QString qs){
	m_sSourceRoot=qs;
}

} // namespace kscope4
// Sat Oct 15 17:20:27 PDT 2011
