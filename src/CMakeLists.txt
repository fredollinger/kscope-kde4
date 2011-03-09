project(kscope)

find_package(KDE4 REQUIRED)
include_directories(${KDE4_INCLUDES})


set(kscope_SRCS
frontend.cpp
ctagsfrontend.cpp
ctagslist.cpp
editorpage.cpp
editormanager.cpp
kscope4.cpp
main.cpp
k3wrap.cpp
kscopeconfig.cpp
)

kde4_add_executable(kscope ${kscope_SRCS})

target_link_libraries(kscope ${KDE4_KDEUI_LIBS}
${KDE4_KIO_LIBS}
${KDE4_KDE3SUPPORT_LIBS}
${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS kscope DESTINATION ${BIN_INSTALL_DIR})
install(FILES kscopeui.rc DESTINATION ${DATA_INSTALL_DIR}/kscope)
