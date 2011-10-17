#ifndef VCS_COMMIT_DLG_H
#define VCS_COMMIT_DLG_H

#include <QDialog>

#include "vcsCommitLayout.h"
#include "vcsFrontEnd.h"
 
namespace kscope4{
class vcsCommitDlg : public QDialog, public Ui::vcsCommitLayout
{
	Q_OBJECT

public:
	vcsCommitDlg(QWidget* pParent = 0, const char* szName = 0);
	~vcsCommitDlg();
	
private:
	vcsFrontEnd *m_pVcsProcess;

private slots:
	void slotCommit(void);
	
};
} // namespace kscope4
#endif

// Sat Oct 15 17:22:42 PDT 2011
