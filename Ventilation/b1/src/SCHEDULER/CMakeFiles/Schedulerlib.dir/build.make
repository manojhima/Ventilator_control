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
include src/SCHEDULER/CMakeFiles/Schedulerlib.dir/depend.make

# Include the progress variables for this target.
include src/SCHEDULER/CMakeFiles/Schedulerlib.dir/progress.make

# Include the compile flags for this target's objects.
include src/SCHEDULER/CMakeFiles/Schedulerlib.dir/flags.make

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.o: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/flags.make
src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.o: ../src/SCHEDULER/SCHED_Setup_entry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.o   -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Setup_entry.c

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Setup_entry.c > CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.i

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Setup_entry.c -o CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.s

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.o: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/flags.make
src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.o: ../src/SCHEDULER/SCHED_Setup_Main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.o   -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Setup_Main.c

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Setup_Main.c > CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.i

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Setup_Main.c -o CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.s

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.o: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/flags.make
src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.o: ../src/SCHEDULER/SCHED_Ventilation_entry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.o   -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Ventilation_entry.c

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Ventilation_entry.c > CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.i

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Ventilation_entry.c -o CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.s

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.o: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/flags.make
src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.o: ../src/SCHEDULER/SCHED_Ventilation_Main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.o"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.o   -c /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Ventilation_Main.c

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.i"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Ventilation_Main.c > CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.i

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.s"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER/SCHED_Ventilation_Main.c -o CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.s

# Object files for target Schedulerlib
Schedulerlib_OBJECTS = \
"CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.o" \
"CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.o" \
"CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.o" \
"CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.o"

# External object files for target Schedulerlib
Schedulerlib_EXTERNAL_OBJECTS =

src/SCHEDULER/libSchedulerlib.a: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_entry.c.o
src/SCHEDULER/libSchedulerlib.a: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Setup_Main.c.o
src/SCHEDULER/libSchedulerlib.a: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_entry.c.o
src/SCHEDULER/libSchedulerlib.a: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/SCHED_Ventilation_Main.c.o
src/SCHEDULER/libSchedulerlib.a: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/build.make
src/SCHEDULER/libSchedulerlib.a: src/SCHEDULER/CMakeFiles/Schedulerlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libSchedulerlib.a"
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && $(CMAKE_COMMAND) -P CMakeFiles/Schedulerlib.dir/cmake_clean_target.cmake
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Schedulerlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/SCHEDULER/CMakeFiles/Schedulerlib.dir/build: src/SCHEDULER/libSchedulerlib.a

.PHONY : src/SCHEDULER/CMakeFiles/Schedulerlib.dir/build

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/clean:
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER && $(CMAKE_COMMAND) -P CMakeFiles/Schedulerlib.dir/cmake_clean.cmake
.PHONY : src/SCHEDULER/CMakeFiles/Schedulerlib.dir/clean

src/SCHEDULER/CMakeFiles/Schedulerlib.dir/depend:
	cd /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/src/SCHEDULER /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1 /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER /home/bhavya/Main_WS/Ventilation_Maintest/Ventilation/b1/src/SCHEDULER/CMakeFiles/Schedulerlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/SCHEDULER/CMakeFiles/Schedulerlib.dir/depend

