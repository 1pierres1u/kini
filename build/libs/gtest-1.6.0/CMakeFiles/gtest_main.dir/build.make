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
CMAKE_SOURCE_DIR = C:\Users\Socrasthy\Desktop\Z\kini

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Socrasthy\Desktop\Z\kini\build

# Include any dependencies generated for this target.
include libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\depend.make

# Include the progress variables for this target.
include libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\progress.make

# Include the compile flags for this target's objects.
include libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\flags.make

libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\src\gtest_main.cc.o: libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\flags.make
libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\src\gtest_main.cc.o: libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\includes_CXX.rsp
libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\src\gtest_main.cc.o: ..\libs\gtest-1.6.0\src\gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Socrasthy\Desktop\Z\kini\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.o -c C:\Users\Socrasthy\Desktop\Z\kini\libs\gtest-1.6.0\src\gtest_main.cc
	cd C:\Users\Socrasthy\Desktop\Z\kini\build

libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\src\gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Socrasthy\Desktop\Z\kini\libs\gtest-1.6.0\src\gtest_main.cc > CMakeFiles\gtest_main.dir\src\gtest_main.cc.i
	cd C:\Users\Socrasthy\Desktop\Z\kini\build

libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\src\gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Socrasthy\Desktop\Z\kini\libs\gtest-1.6.0\src\gtest_main.cc -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.s
	cd C:\Users\Socrasthy\Desktop\Z\kini\build

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles\gtest_main.dir\src\gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

libs\gtest-1.6.0\libgtest_main.a: libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\src\gtest_main.cc.o
libs\gtest-1.6.0\libgtest_main.a: libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\build.make
libs\gtest-1.6.0\libgtest_main.a: libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Socrasthy\Desktop\Z\kini\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0
	$(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean_target.cmake
	cd C:\Users\Socrasthy\Desktop\Z\kini\build
	cd C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest_main.dir\link.txt --verbose=$(VERBOSE)
	cd C:\Users\Socrasthy\Desktop\Z\kini\build

# Rule to build all files generated by this target.
libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\build: libs\gtest-1.6.0\libgtest_main.a

.PHONY : libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\build

libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\clean:
	cd C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0
	$(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean.cmake
	cd C:\Users\Socrasthy\Desktop\Z\kini\build
.PHONY : libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\clean

libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Socrasthy\Desktop\Z\kini C:\Users\Socrasthy\Desktop\Z\kini\libs\gtest-1.6.0 C:\Users\Socrasthy\Desktop\Z\kini\build C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0 C:\Users\Socrasthy\Desktop\Z\kini\build\libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs\gtest-1.6.0\CMakeFiles\gtest_main.dir\depend
