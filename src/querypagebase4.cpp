#include <qfile.h>
#include "querypagebase4.h"
#include "kscopeconfig4.h"

namespace kscope4{
#define FILE_VERSION	"VERSION=4"

/**
 * Class constructor.
 * @param	pParent	The parent widget
 * @param	szName	The widget's name
 */
QueryPageBase::QueryPageBase(QWidget* pParent, const char* szName) :
	QWidget(pParent),
	m_bLocked(false)
{
}

/**
 * Class destructor.
 */
QueryPageBase::~QueryPageBase()
{
}

} // namespace kscope4
// Sun Oct  9 16:29:55 PDT 2011
