cmake_minimum_required(VERSION 2.8)
project(kmvc)

find_package(KDE4 REQUIRED)
include_directories(${KDE4_INCLUDES})

kde4_add_ui_files(kmvc_SRCS 
preffrontendlayout4.ui
autocompletionlayout4.ui
newprojectlayout4.ui
)

set(kmvc_SRCS
symbolcompletion4.cpp
main.cpp
)

kde4_add_executable(kmvc ${kmvc_SRCS})

target_link_libraries(kmvc ${KDE4_KDEUI_LIBS}
${KDE4_KIO_LIBS}
${KDE4_KDE3SUPPORT_LIBS}
${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS kmvc DESTINATION ${BIN_INSTALL_DIR})
install(FILES kmvc-kde4.rc DESTINATION ${DATA_INSTALL_DIR}/kmvc-kde4)
