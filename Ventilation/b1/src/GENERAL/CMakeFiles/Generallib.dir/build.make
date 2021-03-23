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
include src/GENERAL/CMakeFiles/Generallib.dir/depend.make

# Include the progress variables for this target.
include src/GENERAL/CMakeFiles/Generallib.dir/progress.make

# Include the compile flags for this target's objects.
include src/GENERAL/CMakeFiles/Generallib.dir/flags.make

src/GENERAL/CMakeFiles/Generallib.dir/Average.c.o: src/GENERAL/CMakeFiles/Generallib.dir/flags.make
src/GENERAL/CMakeFiles/Generallib.dir/Average.c.o: ../src/GENERAL/Average.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/GENERAL/CMakeFiles/Generallib.dir/Average.c.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Generallib.dir/Average.c.o   -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL/Average.c

src/GENERAL/CMakeFiles/Generallib.dir/Average.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Generallib.dir/Average.c.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL/Average.c > CMakeFiles/Generallib.dir/Average.c.i

src/GENERAL/CMakeFiles/Generallib.dir/Average.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Generallib.dir/Average.c.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL/Average.c -o CMakeFiles/Generallib.dir/Average.c.s

src/GENERAL/CMakeFiles/Generallib.dir/Saturation.c.o: src/GENERAL/CMakeFiles/Generallib.dir/flags.make
src/GENERAL/CMakeFiles/Generallib.dir/Saturation.c.o: ../src/GENERAL/Saturation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/GENERAL/CMakeFiles/Generallib.dir/Saturation.c.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Generallib.dir/Saturation.c.o   -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL/Saturation.c

src/GENERAL/CMakeFiles/Generallib.dir/Saturation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Generallib.dir/Saturation.c.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL/Saturation.c > CMakeFiles/Generallib.dir/Saturation.c.i

src/GENERAL/CMakeFiles/Generallib.dir/Saturation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Generallib.dir/Saturation.c.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL/Saturation.c -o CMakeFiles/Generallib.dir/Saturation.c.s

# Object files for target Generallib
Generallib_OBJECTS = \
"CMakeFiles/Generallib.dir/Average.c.o" \
"CMakeFiles/Generallib.dir/Saturation.c.o"

# External object files for target Generallib
Generallib_EXTERNAL_OBJECTS =

src/GENERAL/libGenerallib.a: src/GENERAL/CMakeFiles/Generallib.dir/Average.c.o
src/GENERAL/libGenerallib.a: src/GENERAL/CMakeFiles/Generallib.dir/Saturation.c.o
src/GENERAL/libGenerallib.a: src/GENERAL/CMakeFiles/Generallib.dir/build.make
src/GENERAL/libGenerallib.a: src/GENERAL/CMakeFiles/Generallib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libGenerallib.a"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && $(CMAKE_COMMAND) -P CMakeFiles/Generallib.dir/cmake_clean_target.cmake
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Generallib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GENERAL/CMakeFiles/Generallib.dir/build: src/GENERAL/libGenerallib.a

.PHONY : src/GENERAL/CMakeFiles/Generallib.dir/build

src/GENERAL/CMakeFiles/Generallib.dir/clean:
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL && $(CMAKE_COMMAND) -P CMakeFiles/Generallib.dir/cmake_clean.cmake
.PHONY : src/GENERAL/CMakeFiles/Generallib.dir/clean

src/GENERAL/CMakeFiles/Generallib.dir/depend:
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/GENERAL /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1 /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/GENERAL/CMakeFiles/Generallib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/GENERAL/CMakeFiles/Generallib.dir/depend
