# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/follinge/projects/kscope-kde4/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/follinge/projects/kscope-kde4/src/build

# Include any dependencies generated for this target.
include CMakeFiles/editor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/editor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/editor.dir/flags.make

CMakeFiles/editor.dir/editor_automoc.o: CMakeFiles/editor.dir/flags.make
CMakeFiles/editor.dir/editor_automoc.o: editor_automoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/follinge/projects/kscope-kde4/src/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/editor.dir/editor_automoc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/editor.dir/editor_automoc.o -c /home/follinge/projects/kscope-kde4/src/build/editor_automoc.cpp

CMakeFiles/editor.dir/editor_automoc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/editor.dir/editor_automoc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/follinge/projects/kscope-kde4/src/build/editor_automoc.cpp > CMakeFiles/editor.dir/editor_automoc.i

CMakeFiles/editor.dir/editor_automoc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/editor.dir/editor_automoc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/follinge/projects/kscope-kde4/src/build/editor_automoc.cpp -o CMakeFiles/editor.dir/editor_automoc.s

CMakeFiles/editor.dir/editor_automoc.o.requires:
.PHONY : CMakeFiles/editor.dir/editor_automoc.o.requires

CMakeFiles/editor.dir/editor_automoc.o.provides: CMakeFiles/editor.dir/editor_automoc.o.requires
	$(MAKE) -f CMakeFiles/editor.dir/build.make CMakeFiles/editor.dir/editor_automoc.o.provides.build
.PHONY : CMakeFiles/editor.dir/editor_automoc.o.provides

CMakeFiles/editor.dir/editor_automoc.o.provides.build: CMakeFiles/editor.dir/editor_automoc.o
.PHONY : CMakeFiles/editor.dir/editor_automoc.o.provides.build

CMakeFiles/editor.dir/main.o: CMakeFiles/editor.dir/flags.make
CMakeFiles/editor.dir/main.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/follinge/projects/kscope-kde4/src/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/editor.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/editor.dir/main.o -c /home/follinge/projects/kscope-kde4/src/main.cpp

CMakeFiles/editor.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/editor.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/follinge/projects/kscope-kde4/src/main.cpp > CMakeFiles/editor.dir/main.i

CMakeFiles/editor.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/editor.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/follinge/projects/kscope-kde4/src/main.cpp -o CMakeFiles/editor.dir/main.s

CMakeFiles/editor.dir/main.o.requires:
.PHONY : CMakeFiles/editor.dir/main.o.requires

CMakeFiles/editor.dir/main.o.provides: CMakeFiles/editor.dir/main.o.requires
	$(MAKE) -f CMakeFiles/editor.dir/build.make CMakeFiles/editor.dir/main.o.provides.build
.PHONY : CMakeFiles/editor.dir/main.o.provides

CMakeFiles/editor.dir/main.o.provides.build: CMakeFiles/editor.dir/main.o
.PHONY : CMakeFiles/editor.dir/main.o.provides.build

CMakeFiles/editor.dir/kscope.o: CMakeFiles/editor.dir/flags.make
CMakeFiles/editor.dir/kscope.o: ../kscope.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/follinge/projects/kscope-kde4/src/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/editor.dir/kscope.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/editor.dir/kscope.o -c /home/follinge/projects/kscope-kde4/src/kscope.cpp

CMakeFiles/editor.dir/kscope.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/editor.dir/kscope.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/follinge/projects/kscope-kde4/src/kscope.cpp > CMakeFiles/editor.dir/kscope.i

CMakeFiles/editor.dir/kscope.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/editor.dir/kscope.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/follinge/projects/kscope-kde4/src/kscope.cpp -o CMakeFiles/editor.dir/kscope.s

CMakeFiles/editor.dir/kscope.o.requires:
.PHONY : CMakeFiles/editor.dir/kscope.o.requires

CMakeFiles/editor.dir/kscope.o.provides: CMakeFiles/editor.dir/kscope.o.requires
	$(MAKE) -f CMakeFiles/editor.dir/build.make CMakeFiles/editor.dir/kscope.o.provides.build
.PHONY : CMakeFiles/editor.dir/kscope.o.provides

CMakeFiles/editor.dir/kscope.o.provides.build: CMakeFiles/editor.dir/kscope.o
.PHONY : CMakeFiles/editor.dir/kscope.o.provides.build

# Object files for target editor
editor_OBJECTS = \
"CMakeFiles/editor.dir/editor_automoc.o" \
"CMakeFiles/editor.dir/main.o" \
"CMakeFiles/editor.dir/kscope.o"

# External object files for target editor
editor_EXTERNAL_OBJECTS =

editor: CMakeFiles/editor.dir/editor_automoc.o
editor: CMakeFiles/editor.dir/main.o
editor: CMakeFiles/editor.dir/kscope.o
editor: /usr/lib/libkdeui.so.5.5.0
editor: /usr/lib/libkio.so.5.5.0
editor: /usr/lib/libktexteditor.so.4.5.0
editor: /usr/lib/libkparts.so.4.5.0
editor: /usr/lib/libkio.so.5.5.0
editor: /usr/lib/libQtNetwork.so
editor: /usr/lib/libQtXml.so
editor: /usr/lib/libnepomuk.so.4.5.0
editor: /usr/lib/libkdeui.so.5.5.0
editor: /usr/lib/libQtSvg.so
editor: /usr/lib/libQtGui.so
editor: /usr/lib/libkdecore.so.5.5.0
editor: /usr/lib/libQtDBus.so
editor: /usr/lib/libQtCore.so
editor: /usr/lib/libsoprano.so
editor: CMakeFiles/editor.dir/build.make
editor: CMakeFiles/editor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable editor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/editor.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D_filename=/home/follinge/projects/kscope-kde4/src/build/editor.shell -D_library_path_variable=LD_LIBRARY_PATH -D_ld_library_path="/home/follinge/projects/kscope-kde4/src/build/lib/./:/usr/local/lib:/usr/lib:/usr/lib" -D_executable=/home/follinge/projects/kscope-kde4/src/build/editor -P /usr/share/kde4/apps/cmake/modules/kde4_exec_via_sh.cmake

# Rule to build all files generated by this target.
CMakeFiles/editor.dir/build: editor
.PHONY : CMakeFiles/editor.dir/build

CMakeFiles/editor.dir/requires: CMakeFiles/editor.dir/editor_automoc.o.requires
CMakeFiles/editor.dir/requires: CMakeFiles/editor.dir/main.o.requires
CMakeFiles/editor.dir/requires: CMakeFiles/editor.dir/kscope.o.requires
.PHONY : CMakeFiles/editor.dir/requires

CMakeFiles/editor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/editor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/editor.dir/clean

CMakeFiles/editor.dir/depend:
	cd /home/follinge/projects/kscope-kde4/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/follinge/projects/kscope-kde4/src /home/follinge/projects/kscope-kde4/src /home/follinge/projects/kscope-kde4/src/build /home/follinge/projects/kscope-kde4/src/build /home/follinge/projects/kscope-kde4/src/build/CMakeFiles/editor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/editor.dir/depend

