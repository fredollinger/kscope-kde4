#include <qcheckbox.h>
#include <qtextedit.h>
#include <kurlrequester.h>
#include <klineedit.h>
#include <kstandarddirs.h>
#include <klocale.h>
#include "preffrontend4.h"
#include "kscopeconfig.h"

PrefFrontend::~PrefFrontend()
{
}

/**
 * Reads the current settings from the configuration object, and applies them
 * the the page's widget.
 */
void PrefFrontend::load()
{
	return;
}

/**
 * Commits settings changes to the configuration object.
 */
void PrefFrontend::apply()
{
	return;
}

/**
 * Emits the modified() signal whenever any of the paths edit widgets changes
 * its contents.
 * This slot is connected to the textChanged() signal of each of the path
 * edit widgets. By emitting the modified() signal, the widget notifies the
 * parent dialog it should enable the "Apply" button.
 */
void PrefFrontend::slotChanged(const QString&)
{
	emit modified();
}

/**
 * Checks the user's PATH environment variable for a Cscope and Ctags
 * executables.
 * This is done by running the kscope_config script.
 */
void PrefFrontend::slotGuessPaths()
{
	return;
}

/**
 * Shows the test being executed by the script in the text widget.
 * This slot is connected to the test() signal of the ConfigFrontend object.
 * @param	nType	The type of test being executed
 */
void PrefFrontend::slotAutoConfigTest(uint nType)
{
	return;
}

/**
 * Shows the result of a test executed by the configuration script, and
 * adjusts the configuration widgets accordingly.
 * @param	nType	The type of test that was executed
 * @param	sResult	The test's result
 */
void PrefFrontend::slotAutoConfigResult(uint nType, const QString& sResult)
{
	return;
}
