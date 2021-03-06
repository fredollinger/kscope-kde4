#ifndef KS_POPUP_H
#define KS_POPUP_H

#include <QMenu>

namespace kscope4{
class KSPopup : public QMenu
{
   Q_OBJECT

public: 
	KSPopup(QWidget* pParent = 0, const char* szName = 0);
	~KSPopup();
	void clear(void);
	void insertItem(QString, int);
	void popup(QPoint);
	void removeItem(int);
signals:
	void activated(int);
};
} // namespace kscope4
#endif // KS_POPUP_H
// Mon Feb 20 09:00:41 PST 2012
