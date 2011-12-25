cmake_minimum_required(VERSION 2.8)
project(kscope4)

find_package(KDE4 REQUIRED)
include_directories(${KDE4_INCLUDES})

kde4_add_ui_files(kscope_SRCS 
preffrontendlayout4.ui
autocompletionlayout4.ui
newprojectlayout4.ui
vcsCommitLayout.ui
)

kde4_add_kcfg_files(kscope4_SRCS KSGlobalConfig.kcfgc)
install(FILES KSGlobalConfig.kcfg DESTINATION ${KCFG_INSTALL_DIR})


set(kscope_SRCS
KSGlobalConfig.cpp
ksconfig4.cpp
project4.cpp
buildFrontEnd.cpp
vcsFrontEnd.cpp
vcsCommitDlg.cpp
querywidget4.cpp
querypagebase4.cpp
querypage4.cpp
queryview4.cpp
grepdlg.cpp
grepfrontend.cpp
qlistviewitem4.cpp
encoder4.cpp
kdockwidget4.cpp
tabwidget4.cpp
progressdlg4.cpp
symboldlg4.cpp
symbolcompletion4.cpp
openprojectdlg4.cpp
kscope4.cpp
kscopepixmaps4.cpp
searchlist4.cpp
projectbase4.cpp
projectmanager4.cpp
newprojectdlg4.cpp
kscopeconfig4.cpp
configfrontend4.cpp
preffrontend4.cpp
frontend4.cpp
cscopefrontend4.cpp
main.cpp
)

kde4_add_executable(kscope4 ${kscope_SRCS})

target_link_libraries(kscope4 ${KDE4_KDEUI_LIBS}
${KDE4_KIO_LIBS}
${KDE4_KDE3SUPPORT_LIBS}
${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS kscope4  DESTINATION ${BIN_INSTALL_DIR})
install(FILES kscope-kde4.rc DESTINATION ${DATA_INSTALL_DIR}/kscope-kde4)
install(FILES kscope4_config DESTINATION ${BIN_INSTALL_DIR})
