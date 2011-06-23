## Makefile.am for kgit

# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = kgit kgit_client

# set the include path for X, qt and KDE
INCLUDES         = $(all_includes)

# the library search path. 
kgit_LDFLAGS = $(KDE_RPATH) $(all_libraries)

# the libraries to link against.
kgit_LDADD   = $(LIB_KFILE) $(LIB_KDEPRINT)

# which sources should be compiled for kgit
kgit_SOURCES = kgit.cpp kgitiface.skel kgitview.cpp kgitview_custom.ui main.cpp \
	pref.cpp

# these are the headers for your project
noinst_HEADERS = kgit.h kgitview.h pref.h 

# client stuff
kgit_client_LDFLAGS = $(KDE_RPATH) $(all_libraries)
kgit_client_LDADD   = $(LIB_KDECORE)
kgit_client_SOURCES = kgit_client.cpp

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(EXTRACTRC) `find . -name \*.ui -o -name \*.rc` > rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/kgit.pot

KDE_ICON = AUTO

# this is where the kdelnk file will go 
kdelnkdir   = $(kde_appsdir)/Utilities
kdelnk_DATA = kgit.desktop

# this is where the XML-GUI resource file goes
rcdir = $(kde_datadir)/kgit
rc_DATA = kgitui.rc
