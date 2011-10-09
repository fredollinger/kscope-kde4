cmake_minimum_required(VERSION 2.8)
project(kscope)

find_package(KDE4 REQUIRED)
include_directories(${KDE4_INCLUDES})

kde4_add_ui_files(kscope_SRCS 
preffrontendlayout4.ui
autocompletionlayout4.ui
newprojectlayout4.ui
)


set(kscope_SRCS
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
fileview4.cpp
searchlist4.cpp
filelist4.cpp
projectbase4.cpp
projectmanager4.cpp
project4.cpp
newprojectdlg4.cpp
kscopeconfig4.cpp
configfrontend4.cpp
preffrontend4.cpp
frontend4.cpp
cscopefrontend4.cpp
main.cpp
)

kde4_add_executable(kscope ${kscope_SRCS})

target_link_libraries(kscope ${KDE4_KDEUI_LIBS}
${KDE4_KIO_LIBS}
${KDE4_KDE3SUPPORT_LIBS}
${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS kscope  DESTINATION ${BIN_INSTALL_DIR})
install(FILES kscope-kde4.rc DESTINATION ${DATA_INSTALL_DIR}/kscope-kde4)
install(FILES kscope_config DESTINATION ${BIN_INSTALL_DIR})
