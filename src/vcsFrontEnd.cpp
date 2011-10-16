#include <qdebug.h>

#include <qstringlist.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include "frontend4.h"

#include "vcsFrontEnd.h"

namespace kscope4{
vcsFrontEnd::vcsFrontEnd(bool bAutoDelete) : 
	Frontend(CSCOPE_RECORD_SIZE, bAutoDelete),
	m_state(vcsUnknown),
	m_sErrMsg(""),
	m_bRebuildOnExit(false)
{
}

vcsFrontEnd::~vcsFrontEnd() 
{
}
} // namespace kscope4

// Sat Oct 15 17:51:14 PDT 2011
