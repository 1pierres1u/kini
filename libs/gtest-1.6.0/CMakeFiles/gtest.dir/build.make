# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Socrasthy\Desktop\test\gest1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Socrasthy\Desktop\test\gest1\build

# Include any dependencies generated for this target.
include lib\gtest-1.6.0\CMakeFiles\gtest.dir\depend.make

# Include the progress variables for this target.
include lib\gtest-1.6.0\CMakeFiles\gtest.dir\progress.make

# Include the compile flags for this target's objects.
include lib\gtest-1.6.0\CMakeFiles\gtest.dir\flags.make

lib\gtest-1.6.0\CMakeFiles\gtest.dir\src\gtest-all.cc.o: lib\gtest-1.6.0\CMakeFiles\gtest.dir\flags.make
lib\gtest-1.6.0\CMakeFiles\gtest.dir\src\gtest-all.cc.o: lib\gtest-1.6.0\CMakeFiles\gtest.dir\includes_CXX.rsp
lib\gtest-1.6.0\CMakeFiles\gtest.dir\src\gtest-all.cc.o: ..\lib\gtest-1.6.0\src\gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Socrasthy\Desktop\test\gest1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/gtest-1.6.0/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.o -c C:\Users\Socrasthy\Desktop\test\gest1\lib\gtest-1.6.0\src\gtest-all.cc
	cd C:\Users\Socrasthy\Desktop\test\gest1\build

lib\gtest-1.6.0\CMakeFiles\gtest.dir\src\gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Socrasthy\Desktop\test\gest1\lib\gtest-1.6.0\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i
	cd C:\Users\Socrasthy\Desktop\test\gest1\build

lib\gtest-1.6.0\CMakeFiles\gtest.dir\src\gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Socrasthy\Desktop\test\gest1\lib\gtest-1.6.0\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s
	cd C:\Users\Socrasthy\Desktop\test\gest1\build

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles\gtest.dir\src\gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib\gtest-1.6.0\libgtest.a: lib\gtest-1.6.0\CMakeFiles\gtest.dir\src\gtest-all.cc.o
lib\gtest-1.6.0\libgtest.a: lib\gtest-1.6.0\CMakeFiles\gtest.dir\build.make
lib\gtest-1.6.0\libgtest.a: lib\gtest-1.6.0\CMakeFiles\gtest.dir\link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Socrasthy\Desktop\test\gest1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	cd C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd C:\Users\Socrasthy\Desktop\test\gest1\build
	cd C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)
	cd C:\Users\Socrasthy\Desktop\test\gest1\build

# Rule to build all files generated by this target.
lib\gtest-1.6.0\CMakeFiles\gtest.dir\build: lib\gtest-1.6.0\libgtest.a

.PHONY : lib\gtest-1.6.0\CMakeFiles\gtest.dir\build

lib\gtest-1.6.0\CMakeFiles\gtest.dir\clean:
	cd C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
	cd C:\Users\Socrasthy\Desktop\test\gest1\build
.PHONY : lib\gtest-1.6.0\CMakeFiles\gtest.dir\clean

lib\gtest-1.6.0\CMakeFiles\gtest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Socrasthy\Desktop\test\gest1 C:\Users\Socrasthy\Desktop\test\gest1\lib\gtest-1.6.0 C:\Users\Socrasthy\Desktop\test\gest1\build C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0 C:\Users\Socrasthy\Desktop\test\gest1\build\lib\gtest-1.6.0\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib\gtest-1.6.0\CMakeFiles\gtest.dir\depend
