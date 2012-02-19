#ifndef KSCOPECONFIG_H
#define KSCOPECONFIG_H

#include <KParts/MainWindow>
#include <qobject.h>
#include <qstringlist.h>
#include <qcolor.h>
#include "KSGlobalConfig.h"

// typedef QList<int> SPLIT_SIZES;

/**
 * Loads and stores global configuration parameters.
 * @author Elad Lahav
 */

namespace kscope4{
class KScopeConfig : public KSGlobalConfig
{
	Q_OBJECT
	
public:
	KScopeConfig();
	~KScopeConfig();

	/** GUI elements whose colours can be set. */
	enum ColorElement { FileListFore = 0, FileListBack, TagListFore, 
		TagListBack, QueryWindowFore, QueryWindowBack, GraphBack,
		GraphNode, GraphText, GraphMultiCall, LAST_COLOR = GraphMultiCall };
	
	/** GUI elements whose fonts can be set. */
	enum FontElement { FileList = 0, TagList, QueryWindow, Graph,
		LAST_FONT = Graph };
	
	/** Sort order values for the tags list. */
	enum CtagSort { NameAsc = 0, NameDes, LineAsc, LineDes, TypeAsc,
		TypeDes };
	
	/** Types of systems that determine certain aspects in KScope's
		behaviour. 
		For fast systems, certain time-consuming operations, such as
		rebuilding the database, may be performed automatically. Such
		behaviour, however, is not desired on slow systems, in which the user
		should handle such operations manually. */
	enum SysProfile { Fast, Slow };	
		
	/** The different options for a popup menu to be installed in the editor
		parts. */
	enum EditorPopup { Embedded, KScopeOnly };	
	
	void addOpenedFile(const QString&);
	void removeOpenedFile(const QString&);

	void load();
	void loadDefault();
	void loadWorkspace(KParts::MainWindow*);
	void store();
	void storeWorkspace(KParts::MainWindow*);
	bool isFirstTime();
	bool showWelcomeDlg();

	const QString& getCurrentProject();
	void setCurrentProject(const QString& sProjPath);
	void setVcs(const int i);
	
	const QString& getCscopePath() const;
	void setCscopePath(const QString&);
	const QString& getCtagsPath() const;
	void setCtagsPath(const QString&);
	const QString& getDotPath() const;
	void setDotPath(const QString&);
	const QStringList& getRecentProjects() const;
	void addRecentProject(const QString&);
	void removeProject(const QString&);


	bool getShowTagList() const;
	void setShowTagList(bool);
	// const SPLIT_SIZES& getEditorSizes() const;
	// void setEditorSizes(const SPLIT_SIZES&);
	const QColor& getColor(ColorElement) const;
	QString getColorName(ColorElement) const;
	void setColor(ColorElement, const QColor&);
	const QFont& getFont(FontElement) const;
	QString getFontName(FontElement) const;
	void setFont(FontElement, const QFont&);
	CtagSort getCtagSortOrder();
	void setCtagSortOrder(CtagSort);
	bool getReadOnlyMode();
	void setReadOnlyMode(bool);
	bool getLoadLastProj();
	void setLoadLastProj(bool);
	bool getAutoTagHl();
	void setAutoTagHl(bool);
	bool getUseBriefQueryCaptions();
	void setUseBriefQueryCaptions(bool);
	bool getWarnModifiedOnDisk();
	void setWarnModifiedOnDisk(bool);
	bool getAutoSortFiles();
	void setAutoSortFiles(bool);
	const QString& getExtEditor();
	void setExtEditor(const QString&);
	bool useExtEditor();
	SysProfile getSysProfile() const;
	void setSysProfile(SysProfile);
	EditorPopup getEditorPopup() const;
	QString getEditorPopupName() const;
	void setEditorPopup(EditorPopup);
	QString getGraphOrientation() const;
	void setGraphOrientation(const QString&);
	int getGraphMaxNodeDegree() const;
	void setGraphMaxNodeDegree(int);
	int getDefGraphView() const;
	void setDefGraphView(int);
	
private:
	/** A list of previously loaded projects. */
	// FIXME: replace with mRecentProjects
	// QStringList m_slProjects;

	/** Defines the list of all configurable parameters in KScope.
		The use of a structure helps define default values (@see s_cpDef) */
	
	struct ConfParams {
		/** The full path of the Cscope executable. */
		QString sCscopePath;
		
		/** The full path of the Ctags executable. */
		QString sCtagsPath;
		
		/** The full path of the Dot executable. */
		QString sDotPath;
		
		/** Whether the tag list should be visible. */
		bool bShowTagList;
		
		/** The widths of the tag list and editor panes inside an editor
			page. */
		// SPLIT_SIZES siEditor;
		
		/** Colours for GUI elements. */
		QColor clrs[LAST_COLOR + 1];
		
		/** Fonts for GUI elements. */
		// QFont fonts[LAST_FONT + 1];
		
		/** Sort order of the tag lists. */
		CtagSort ctagSortOrder;
		
		/** Whether KScope should operate in code read-only mode. */
		bool bReadOnlyMode;
		
		/** Whether the last open project should be reloaded on start-up. */
		bool bLoadLastProj;
		
		/** Whether tags should be highlighted based on the current cursor
			position. */
		bool bAutoTagHl;
		
		/** Whether query page captions should use mnemonics for query types,
			instead of the full description. */
		bool bBriefQueryCaptions;
		
		/** Whether the warning should be displayed when file is modified on 
			disk by external process. */
		bool bWarnModifiedOnDisk;
		
		/** Should files be sorted automatically when a project is loaded. */
		bool bAutoSortFiles;
		
		/** A command line pattern for an external editor (in read-only
			mode.)*/
		QString sExtEditor;
		
		/** How KScope should treat time-consuming operations. */
		SysProfile profile;
		
		/** The type of popup menu to use in the embedded editor. */
		EditorPopup popup;
		
		/** The default orientation of call graphs. */
		QString sGraphOrient;
		
		/** Maximal number of called/calling functions per call graph node. */
		int nGraphMaxNodeDegree;
		
		/** Default view for the call graph dialogue. */
		int nDefGraphView;
	};

	/** The current configuration parameters */
	ConfParams m_cp;

	/** Holds default values for the configuration parameters */
	static ConfParams s_cpDef;
	
	/** Write font preferences only if modified by the user (keep default
		setting otherwise) */
	bool m_bFontsChanged;
};

extern KScopeConfig& Config();

} // namespace kscope4
#endif
