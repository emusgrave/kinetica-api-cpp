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

# Utility rule file for reuse_hh.

# Include the progress variables for this target.
include CMakeFiles/reuse_hh.dir/progress.make

CMakeFiles/reuse_hh: reuse.hh

reuse.hh: avrogencpp
reuse.hh: ../jsonschemas/reuse
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating reuse.hh"
	./avrogencpp -p - -i /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/jsonschemas/reuse -o reuse.hh -n ru -U

reuse_hh: CMakeFiles/reuse_hh
reuse_hh: reuse.hh
reuse_hh: CMakeFiles/reuse_hh.dir/build.make
.PHONY : reuse_hh

# Rule to build all files generated by this target.
CMakeFiles/reuse_hh.dir/build: reuse_hh
.PHONY : CMakeFiles/reuse_hh.dir/build

CMakeFiles/reuse_hh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reuse_hh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reuse_hh.dir/clean

CMakeFiles/reuse_hh.dir/depend:
	cd /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7 /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7 /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build /home/mmahmud/gisfederal/gpudb-dev/gpudb-dev-master/gpudb-api-cpp/thirdparty/build/avro-cpp-1.7.7/build/CMakeFiles/reuse_hh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reuse_hh.dir/depend

