# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1

# Include any dependencies generated for this target.
include src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/depend.make

# Include the progress variables for this target.
include src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/flags.make

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/main.cpp.o: src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/flags.make
src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/main.cpp.o: ../src/DATABASE/tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/main.cpp.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Databaselib_test.dir/main.cpp.o -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests/main.cpp

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Databaselib_test.dir/main.cpp.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests/main.cpp > CMakeFiles/Databaselib_test.dir/main.cpp.i

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Databaselib_test.dir/main.cpp.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests/main.cpp -o CMakeFiles/Databaselib_test.dir/main.cpp.s

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.o: src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/flags.make
src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.o: ../src/DATABASE/tests/test_DB_AlarmInfoRead.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.o -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests/test_DB_AlarmInfoRead.cpp

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests/test_DB_AlarmInfoRead.cpp > CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.i

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests/test_DB_AlarmInfoRead.cpp -o CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.s

# Object files for target Databaselib_test
Databaselib_test_OBJECTS = \
"CMakeFiles/Databaselib_test.dir/main.cpp.o" \
"CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.o"

# External object files for target Databaselib_test
Databaselib_test_EXTERNAL_OBJECTS =

src/DATABASE/tests/Databaselib_test: src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/main.cpp.o
src/DATABASE/tests/Databaselib_test: src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/test_DB_AlarmInfoRead.cpp.o
src/DATABASE/tests/Databaselib_test: src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/build.make
src/DATABASE/tests/Databaselib_test: src/DATABASE/libDatabaselib.a
src/DATABASE/tests/Databaselib_test: lib/libgtest.a
src/DATABASE/tests/Databaselib_test: src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Databaselib_test"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Databaselib_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/build: src/DATABASE/tests/Databaselib_test

.PHONY : src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/build

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/clean:
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests && $(CMAKE_COMMAND) -P CMakeFiles/Databaselib_test.dir/cmake_clean.cmake
.PHONY : src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/clean

src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/depend:
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/DATABASE/tests /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1 /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/DATABASE/tests/CMakeFiles/Databaselib_test.dir/depend
