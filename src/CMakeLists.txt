project(kscope)

find_package(KDE4 REQUIRED)
include_directories(${KDE4_INCLUDES})

#frontend.cpp
#ctagsfrontend.cpp
#ctagslist.cpp
#k3wrap.cpp
#kscopeconfig.cpp
#editormanager.cpp
#editorpage4.cpp
set(kscope_SRCS
kscope4.cpp
main.cpp
)

kde4_add_executable(kscope ${kscope_SRCS})

target_link_libraries(kscope ${KDE4_KDEUI_LIBS}
${KDE4_KIO_LIBS}
${KDE4_KDE3SUPPORT_LIBS}
${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS kscope DESTINATION ${BIN_INSTALL_DIR})
install(FILES kscopeui.rc DESTINATION ${DATA_INSTALL_DIR}/kscope)
