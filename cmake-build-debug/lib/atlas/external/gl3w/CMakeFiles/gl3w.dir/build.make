# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug

# Include any dependencies generated for this target.
include lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/depend.make

# Include the progress variables for this target.
include lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/progress.make

# Include the compile flags for this target's objects.
include lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/flags.make

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/flags.make
lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o: ../lib/atlas/external/gl3w/src/gl3w.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gl3w.dir/src/gl3w.c.o   -c /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/gl3w/src/gl3w.c

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gl3w.dir/src/gl3w.c.i"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/gl3w/src/gl3w.c > CMakeFiles/gl3w.dir/src/gl3w.c.i

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gl3w.dir/src/gl3w.c.s"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/gl3w/src/gl3w.c -o CMakeFiles/gl3w.dir/src/gl3w.c.s

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.requires:

.PHONY : lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.requires

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.provides: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.requires
	$(MAKE) -f lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/build.make lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.provides.build
.PHONY : lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.provides

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.provides.build: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o


# Object files for target gl3w
gl3w_OBJECTS = \
"CMakeFiles/gl3w.dir/src/gl3w.c.o"

# External object files for target gl3w
gl3w_EXTERNAL_OBJECTS =

lib/atlas/external/gl3w/libgl3w.a: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o
lib/atlas/external/gl3w/libgl3w.a: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/build.make
lib/atlas/external/gl3w/libgl3w.a: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libgl3w.a"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w && $(CMAKE_COMMAND) -P CMakeFiles/gl3w.dir/cmake_clean_target.cmake
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gl3w.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/build: lib/atlas/external/gl3w/libgl3w.a

.PHONY : lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/build

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/requires: lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/src/gl3w.c.o.requires

.PHONY : lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/requires

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/clean:
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w && $(CMAKE_COMMAND) -P CMakeFiles/gl3w.dir/cmake_clean.cmake
.PHONY : lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/clean

lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/depend:
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/gl3w /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/atlas/external/gl3w/CMakeFiles/gl3w.dir/depend
