# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pulkit/CG/2019101078_A0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pulkit/CG/2019101078_A0/build

# Include any dependencies generated for this target.
include CMakeFiles/Assignment0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment0.dir/flags.make

CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o: CMakeFiles/Assignment0.dir/flags.make
CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o: ../source/dodecahedron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pulkit/CG/2019101078_A0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o -c /home/pulkit/CG/2019101078_A0/source/dodecahedron.cpp

CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pulkit/CG/2019101078_A0/source/dodecahedron.cpp > CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.i

CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pulkit/CG/2019101078_A0/source/dodecahedron.cpp -o CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.s

CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.requires:

.PHONY : CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.requires

CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.provides: CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment0.dir/build.make CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.provides

CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.provides.build: CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o


# Object files for target Assignment0
Assignment0_OBJECTS = \
"CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o"

# External object files for target Assignment0
Assignment0_EXTERNAL_OBJECTS =

Assignment0: CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o
Assignment0: CMakeFiles/Assignment0.dir/build.make
Assignment0: libraries/glfw/src/libglfw3.a
Assignment0: libglad.a
Assignment0: /usr/lib/x86_64-linux-gnu/librt.so
Assignment0: /usr/lib/x86_64-linux-gnu/libm.so
Assignment0: CMakeFiles/Assignment0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pulkit/CG/2019101078_A0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assignment0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment0.dir/build: Assignment0

.PHONY : CMakeFiles/Assignment0.dir/build

CMakeFiles/Assignment0.dir/requires: CMakeFiles/Assignment0.dir/source/dodecahedron.cpp.o.requires

.PHONY : CMakeFiles/Assignment0.dir/requires

CMakeFiles/Assignment0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment0.dir/clean

CMakeFiles/Assignment0.dir/depend:
	cd /home/pulkit/CG/2019101078_A0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pulkit/CG/2019101078_A0 /home/pulkit/CG/2019101078_A0 /home/pulkit/CG/2019101078_A0/build /home/pulkit/CG/2019101078_A0/build /home/pulkit/CG/2019101078_A0/build/CMakeFiles/Assignment0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment0.dir/depend

