# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-core-libs/install-gcc4.8.3-openmpi/bin/cmake

# The command to remove a file.
RM = /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-core-libs/install-gcc4.8.3-openmpi/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-core-libs/install-gcc4.8.3-openmpi/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build

# Include any dependencies generated for this target.
include CMakeFiles/buffertest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/buffertest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/buffertest.dir/flags.make

CMakeFiles/buffertest.dir/test/buffertest.cc.o: CMakeFiles/buffertest.dir/flags.make
CMakeFiles/buffertest.dir/test/buffertest.cc.o: ../test/buffertest.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/buffertest.dir/test/buffertest.cc.o"
	/usr/lib64/ccache/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/buffertest.dir/test/buffertest.cc.o -c /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/test/buffertest.cc

CMakeFiles/buffertest.dir/test/buffertest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/buffertest.dir/test/buffertest.cc.i"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/test/buffertest.cc > CMakeFiles/buffertest.dir/test/buffertest.cc.i

CMakeFiles/buffertest.dir/test/buffertest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/buffertest.dir/test/buffertest.cc.s"
	/usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/test/buffertest.cc -o CMakeFiles/buffertest.dir/test/buffertest.cc.s

CMakeFiles/buffertest.dir/test/buffertest.cc.o.requires:
.PHONY : CMakeFiles/buffertest.dir/test/buffertest.cc.o.requires

CMakeFiles/buffertest.dir/test/buffertest.cc.o.provides: CMakeFiles/buffertest.dir/test/buffertest.cc.o.requires
	$(MAKE) -f CMakeFiles/buffertest.dir/build.make CMakeFiles/buffertest.dir/test/buffertest.cc.o.provides.build
.PHONY : CMakeFiles/buffertest.dir/test/buffertest.cc.o.provides

CMakeFiles/buffertest.dir/test/buffertest.cc.o.provides.build: CMakeFiles/buffertest.dir/test/buffertest.cc.o

# Object files for target buffertest
buffertest_OBJECTS = \
"CMakeFiles/buffertest.dir/test/buffertest.cc.o"

# External object files for target buffertest
buffertest_EXTERNAL_OBJECTS =

buffertest: CMakeFiles/buffertest.dir/test/buffertest.cc.o
buffertest: CMakeFiles/buffertest.dir/build.make
buffertest: libavrocpp.so.1.7.7.0
buffertest: /usr/lib64/libboost_filesystem.so
buffertest: /usr/lib64/libboost_system.so
buffertest: /usr/lib64/libboost_program_options.so
buffertest: /usr/lib64/libboost_iostreams.so
buffertest: CMakeFiles/buffertest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable buffertest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buffertest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/buffertest.dir/build: buffertest
.PHONY : CMakeFiles/buffertest.dir/build

CMakeFiles/buffertest.dir/requires: CMakeFiles/buffertest.dir/test/buffertest.cc.o.requires
.PHONY : CMakeFiles/buffertest.dir/requires

CMakeFiles/buffertest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/buffertest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/buffertest.dir/clean

CMakeFiles/buffertest.dir/depend:
	cd /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7 /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7 /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build/CMakeFiles/buffertest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/buffertest.dir/depend

