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
include lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/depend.make

# Include the progress variables for this target.
include lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/progress.make

# Include the compile flags for this target's objects.
include lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/flags.make

lib/atlas/external/glfw/examples/wave.app/Contents/Resources/glfw.icns: ../lib/atlas/external/glfw/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content lib/atlas/external/glfw/examples/wave.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/examples/glfw.icns lib/atlas/external/glfw/examples/wave.app/Contents/Resources/glfw.icns

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/flags.make
lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o: ../lib/atlas/external/glfw/examples/wave.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wave.dir/wave.c.o   -c /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/examples/wave.c

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wave.dir/wave.c.i"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/examples/wave.c > CMakeFiles/wave.dir/wave.c.i

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wave.dir/wave.c.s"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/examples/wave.c -o CMakeFiles/wave.dir/wave.c.s

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.requires:

.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.requires

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.provides: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.requires
	$(MAKE) -f lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/build.make lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.provides.build
.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.provides

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.provides.build: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o


lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/flags.make
lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o: ../lib/atlas/external/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wave.dir/__/deps/glad.c.o   -c /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/deps/glad.c

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wave.dir/__/deps/glad.c.i"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/deps/glad.c > CMakeFiles/wave.dir/__/deps/glad.c.i

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wave.dir/__/deps/glad.c.s"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/deps/glad.c -o CMakeFiles/wave.dir/__/deps/glad.c.s

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.requires:

.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.requires

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.provides: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.requires
	$(MAKE) -f lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/build.make lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.provides.build
.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.provides

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.provides.build: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o


# Object files for target wave
wave_OBJECTS = \
"CMakeFiles/wave.dir/wave.c.o" \
"CMakeFiles/wave.dir/__/deps/glad.c.o"

# External object files for target wave
wave_EXTERNAL_OBJECTS =

lib/atlas/external/glfw/examples/wave.app/Contents/MacOS/wave: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o
lib/atlas/external/glfw/examples/wave.app/Contents/MacOS/wave: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o
lib/atlas/external/glfw/examples/wave.app/Contents/MacOS/wave: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/build.make
lib/atlas/external/glfw/examples/wave.app/Contents/MacOS/wave: lib/atlas/external/glfw/src/libglfw3.a
lib/atlas/external/glfw/examples/wave.app/Contents/MacOS/wave: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable wave.app/Contents/MacOS/wave"
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/build: lib/atlas/external/glfw/examples/wave.app/Contents/MacOS/wave
lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/build: lib/atlas/external/glfw/examples/wave.app/Contents/Resources/glfw.icns

.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/build

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/requires: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/wave.c.o.requires
lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/requires: lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/__/deps/glad.c.o.requires

.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/requires

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/clean:
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/wave.dir/cmake_clean.cmake
.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/clean

lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/depend:
	cd /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/lib/atlas/external/glfw/examples /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples /Users/scottgoerzen/Desktop/CSC_473/Project/csc473_fall2018_labs/cmake-build-debug/lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/atlas/external/glfw/examples/CMakeFiles/wave.dir/depend

