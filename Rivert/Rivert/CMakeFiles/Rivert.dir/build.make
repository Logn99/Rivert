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
include Rivert/CMakeFiles/Rivert.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Rivert/CMakeFiles/Rivert.dir/compiler_depend.make

# Include the progress variables for this target.
include Rivert/CMakeFiles/Rivert.dir/progress.make

# Include the compile flags for this target's objects.
include Rivert/CMakeFiles/Rivert.dir/flags.make

Rivert/CMakeFiles/Rivert.dir/src/test.cpp.o: Rivert/CMakeFiles/Rivert.dir/flags.make
Rivert/CMakeFiles/Rivert.dir/src/test.cpp.o: src/test.cpp
Rivert/CMakeFiles/Rivert.dir/src/test.cpp.o: Rivert/CMakeFiles/Rivert.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Rivert/CMakeFiles/Rivert.dir/src/test.cpp.o"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Rivert/CMakeFiles/Rivert.dir/src/test.cpp.o -MF CMakeFiles/Rivert.dir/src/test.cpp.o.d -o CMakeFiles/Rivert.dir/src/test.cpp.o -c "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/src/test.cpp"

Rivert/CMakeFiles/Rivert.dir/src/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Rivert.dir/src/test.cpp.i"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/src/test.cpp" > CMakeFiles/Rivert.dir/src/test.cpp.i

Rivert/CMakeFiles/Rivert.dir/src/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Rivert.dir/src/test.cpp.s"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/src/test.cpp" -o CMakeFiles/Rivert.dir/src/test.cpp.s

# Object files for target Rivert
Rivert_OBJECTS = \
"CMakeFiles/Rivert.dir/src/test.cpp.o"

# External object files for target Rivert
Rivert_EXTERNAL_OBJECTS =

Rivert/libRivert.a: Rivert/CMakeFiles/Rivert.dir/src/test.cpp.o
Rivert/libRivert.a: Rivert/CMakeFiles/Rivert.dir/build.make
Rivert/libRivert.a: Rivert/CMakeFiles/Rivert.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libRivert.a"
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" && $(CMAKE_COMMAND) -P CMakeFiles/Rivert.dir/cmake_clean_target.cmake
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rivert.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Rivert/CMakeFiles/Rivert.dir/build: Rivert/libRivert.a
.PHONY : Rivert/CMakeFiles/Rivert.dir/build

Rivert/CMakeFiles/Rivert.dir/clean:
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" && $(CMAKE_COMMAND) -P CMakeFiles/Rivert.dir/cmake_clean.cmake
.PHONY : Rivert/CMakeFiles/Rivert.dir/clean

Rivert/CMakeFiles/Rivert.dir/depend:
	cd "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert" "/home/michael/ownCloud - Michael Zimmerli (ost.ch)@drive.switch.ch/05_Development/CPP_Projects/Rivert_Engine/Rivert/Rivert/CMakeFiles/Rivert.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : Rivert/CMakeFiles/Rivert.dir/depend

