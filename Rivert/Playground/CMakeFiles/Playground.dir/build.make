# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert"

# Include any dependencies generated for this target.
include Playground/CMakeFiles/Playground.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Playground/CMakeFiles/Playground.dir/compiler_depend.make

# Include the progress variables for this target.
include Playground/CMakeFiles/Playground.dir/progress.make

# Include the compile flags for this target's objects.
include Playground/CMakeFiles/Playground.dir/flags.make

Playground/CMakeFiles/Playground.dir/src/main.cpp.o: Playground/CMakeFiles/Playground.dir/flags.make
Playground/CMakeFiles/Playground.dir/src/main.cpp.o: /home/michael/ownCloud\ -\ Michael\ Zimmerli\ (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Playground/src/main.cpp
Playground/CMakeFiles/Playground.dir/src/main.cpp.o: Playground/CMakeFiles/Playground.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Playground/CMakeFiles/Playground.dir/src/main.cpp.o"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Playground/CMakeFiles/Playground.dir/src/main.cpp.o -MF CMakeFiles/Playground.dir/src/main.cpp.o.d -o CMakeFiles/Playground.dir/src/main.cpp.o -c "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Playground/src/main.cpp"

Playground/CMakeFiles/Playground.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Playground.dir/src/main.cpp.i"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Playground/src/main.cpp" > CMakeFiles/Playground.dir/src/main.cpp.i

Playground/CMakeFiles/Playground.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Playground.dir/src/main.cpp.s"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Playground/src/main.cpp" -o CMakeFiles/Playground.dir/src/main.cpp.s

# Object files for target Playground
Playground_OBJECTS = \
"CMakeFiles/Playground.dir/src/main.cpp.o"

# External object files for target Playground
Playground_EXTERNAL_OBJECTS =

Playground/Playground: Playground/CMakeFiles/Playground.dir/src/main.cpp.o
Playground/Playground: Playground/CMakeFiles/Playground.dir/build.make
Playground/Playground: Rivert/libRivert.a
Playground/Playground: Playground/CMakeFiles/Playground.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Playground"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Playground.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Playground/CMakeFiles/Playground.dir/build: Playground/Playground
.PHONY : Playground/CMakeFiles/Playground.dir/build

Playground/CMakeFiles/Playground.dir/clean:
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground" && $(CMAKE_COMMAND) -P CMakeFiles/Playground.dir/cmake_clean.cmake
.PHONY : Playground/CMakeFiles/Playground.dir/clean

Playground/CMakeFiles/Playground.dir/depend:
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Playground" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Playground/CMakeFiles/Playground.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : Playground/CMakeFiles/Playground.dir/depend
