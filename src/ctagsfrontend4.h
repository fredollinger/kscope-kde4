#ifndef CTAGSFRONTEND_H
#define CTAGSFRONTEND_H

#include "frontend4.h"

namespace kscope4{
#define CTAGS_RECORD_SIZE 3

/**
 * Controls a Ctags process for an file in an EditorPage window.
 * A new Ctags process is run each time the file in the editor window is
 * loaded (including the initial load, and any subsequent ones which follow a
 * 'save' operation.)
 * The output of the process is parsed into a set of records, each composed of
 * the following fields:
 * - Tag type
 * - Tag name
 * - Line number
 * The records are then displayed in the CtagsList widget that is attached to
 * each EditorPage window.
 * @author Elad Lahav
 */

class CtagsFrontend : public Frontend
{
   Q_OBJECT

public:
	CtagsFrontend();
	~CtagsFrontend();

	bool run(const QString&);
	
	static bool verify(const QString&);
	static void setExtraArgs(const QString&);
	
protected:
	virtual ParseResult parseStdout(QString&, ParserDelim);

private:
	/** State values for the parser state machine. */
	enum ParserState { Name = 0, File, Line, Type, Other };

	/** The current state of the parser state machine. */
	ParserState m_state;
	
	/** Additional ommand-line arguments (per-project). */
	static QStringList s_slExtraArgs;
};
}// namespace kscope4
#endif
// Thu Nov 24 15:41:39 PST 2011
