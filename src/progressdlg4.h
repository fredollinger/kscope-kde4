#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <qwidget.h>
#include <qtimer.h>
#include <kprogressdialog.h>

namespace kscope4{
/**
 * An improved progress dialog.
 * This variation of the standard KDE progress dialog displays a busy
 * indicator while waiting for the first value greater than 0.
 * @author Elad Lahav
 */

class ProgressDlg : public KProgressDialog
{
   Q_OBJECT

public: 
	ProgressDlg(const QString&, const QString&, QWidget* pParent = 0, const
		char* szName = 0);
	~ProgressDlg();

	void setValue(int);
	void setIdle();
	
private:
	/** When the value is 0, this timer initiates value changes that cause
		the progress-bar to move. */
	QTimer* m_pIdleTimer;

	/** A dummy value used to move the progress-bar while the value is 0. */
	int m_nIdleValue;

private slots:
	void slotShowBusy();
};
} // namespace kscope4

#endif
