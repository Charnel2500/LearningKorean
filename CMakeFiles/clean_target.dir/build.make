# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jakub/C++/NaukaKoreanskiegoAplikacja

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/C++/NaukaKoreanskiegoAplikacja

# Utility rule file for clean_target.

# Include any custom commands dependencies for this target.
include CMakeFiles/clean_target.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clean_target.dir/progress.make

CMakeFiles/clean_target:
	rm -rf /home/jakub/C++/NaukaKoreanskiegoAplikacja/*.o /home/jakub/C++/NaukaKoreanskiegoAplikacja/LearningKorean

clean_target: CMakeFiles/clean_target
clean_target: CMakeFiles/clean_target.dir/build.make
.PHONY : clean_target

# Rule to build all files generated by this target.
CMakeFiles/clean_target.dir/build: clean_target
.PHONY : CMakeFiles/clean_target.dir/build

CMakeFiles/clean_target.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clean_target.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clean_target.dir/clean

CMakeFiles/clean_target.dir/depend:
	cd /home/jakub/C++/NaukaKoreanskiegoAplikacja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/C++/NaukaKoreanskiegoAplikacja /home/jakub/C++/NaukaKoreanskiegoAplikacja /home/jakub/C++/NaukaKoreanskiegoAplikacja /home/jakub/C++/NaukaKoreanskiegoAplikacja /home/jakub/C++/NaukaKoreanskiegoAplikacja/CMakeFiles/clean_target.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/clean_target.dir/depend

