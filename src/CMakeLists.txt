project(editor)

find_package(KDE4 REQUIRED)
include_directories(${KDE4_INCLUDES})

set(editor_SRCS
main.cpp
mainwindow.cpp
)

kde4_add_executable(editor ${editor_SRCS})

target_link_libraries(editor ${KDE4_KDEUI_LIBS}
${KDE4_KIO_LIBS}
${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS editor DESTINATION ${BIN_INSTALL_DIR})
install(FILES editorui.rc DESTINATION ${DATA_INSTALL_DIR}/editor)
