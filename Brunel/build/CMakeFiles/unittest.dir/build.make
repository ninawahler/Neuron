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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.4_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.4_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build

# Include any dependencies generated for this target.
include CMakeFiles/unittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unittest.dir/flags.make

CMakeFiles/unittest.dir/Neuron.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/Neuron.cpp.o: ../Neuron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unittest.dir/Neuron.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/Neuron.cpp.o -c /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/Neuron.cpp

CMakeFiles/unittest.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/Neuron.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/Neuron.cpp > CMakeFiles/unittest.dir/Neuron.cpp.i

CMakeFiles/unittest.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/Neuron.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/Neuron.cpp -o CMakeFiles/unittest.dir/Neuron.cpp.s

CMakeFiles/unittest.dir/Neuron.cpp.o.requires:

.PHONY : CMakeFiles/unittest.dir/Neuron.cpp.o.requires

CMakeFiles/unittest.dir/Neuron.cpp.o.provides: CMakeFiles/unittest.dir/Neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/unittest.dir/build.make CMakeFiles/unittest.dir/Neuron.cpp.o.provides.build
.PHONY : CMakeFiles/unittest.dir/Neuron.cpp.o.provides

CMakeFiles/unittest.dir/Neuron.cpp.o.provides.build: CMakeFiles/unittest.dir/Neuron.cpp.o


CMakeFiles/unittest.dir/Network.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/Network.cpp.o: ../Network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/unittest.dir/Network.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/Network.cpp.o -c /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/Network.cpp

CMakeFiles/unittest.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/Network.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/Network.cpp > CMakeFiles/unittest.dir/Network.cpp.i

CMakeFiles/unittest.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/Network.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/Network.cpp -o CMakeFiles/unittest.dir/Network.cpp.s

CMakeFiles/unittest.dir/Network.cpp.o.requires:

.PHONY : CMakeFiles/unittest.dir/Network.cpp.o.requires

CMakeFiles/unittest.dir/Network.cpp.o.provides: CMakeFiles/unittest.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/unittest.dir/build.make CMakeFiles/unittest.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/unittest.dir/Network.cpp.o.provides

CMakeFiles/unittest.dir/Network.cpp.o.provides.build: CMakeFiles/unittest.dir/Network.cpp.o


CMakeFiles/unittest.dir/unittest.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/unittest.cpp.o: ../unittest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/unittest.dir/unittest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/unittest.cpp.o -c /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/unittest.cpp

CMakeFiles/unittest.dir/unittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/unittest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/unittest.cpp > CMakeFiles/unittest.dir/unittest.cpp.i

CMakeFiles/unittest.dir/unittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/unittest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/unittest.cpp -o CMakeFiles/unittest.dir/unittest.cpp.s

CMakeFiles/unittest.dir/unittest.cpp.o.requires:

.PHONY : CMakeFiles/unittest.dir/unittest.cpp.o.requires

CMakeFiles/unittest.dir/unittest.cpp.o.provides: CMakeFiles/unittest.dir/unittest.cpp.o.requires
	$(MAKE) -f CMakeFiles/unittest.dir/build.make CMakeFiles/unittest.dir/unittest.cpp.o.provides.build
.PHONY : CMakeFiles/unittest.dir/unittest.cpp.o.provides

CMakeFiles/unittest.dir/unittest.cpp.o.provides.build: CMakeFiles/unittest.dir/unittest.cpp.o


# Object files for target unittest
unittest_OBJECTS = \
"CMakeFiles/unittest.dir/Neuron.cpp.o" \
"CMakeFiles/unittest.dir/Network.cpp.o" \
"CMakeFiles/unittest.dir/unittest.cpp.o"

# External object files for target unittest
unittest_EXTERNAL_OBJECTS =

unittest: CMakeFiles/unittest.dir/Neuron.cpp.o
unittest: CMakeFiles/unittest.dir/Network.cpp.o
unittest: CMakeFiles/unittest.dir/unittest.cpp.o
unittest: CMakeFiles/unittest.dir/build.make
unittest: googletest/libgtest.a
unittest: googletest/libgtest_main.a
unittest: googletest/libgtest.a
unittest: CMakeFiles/unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unittest.dir/build: unittest

.PHONY : CMakeFiles/unittest.dir/build

CMakeFiles/unittest.dir/requires: CMakeFiles/unittest.dir/Neuron.cpp.o.requires
CMakeFiles/unittest.dir/requires: CMakeFiles/unittest.dir/Network.cpp.o.requires
CMakeFiles/unittest.dir/requires: CMakeFiles/unittest.dir/unittest.cpp.o.requires

.PHONY : CMakeFiles/unittest.dir/requires

CMakeFiles/unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unittest.dir/clean

CMakeFiles/unittest.dir/depend:
	cd /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build /Users/ninawahler/Documents/EPFL/BA-3/Programation/Brunel/Brunel/build/CMakeFiles/unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unittest.dir/depend
