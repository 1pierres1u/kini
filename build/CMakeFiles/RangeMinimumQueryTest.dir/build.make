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
include CMakeFiles\RangeMinimumQueryTest.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\RangeMinimumQueryTest.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\RangeMinimumQueryTest.dir\flags.make

CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.obj: CMakeFiles\RangeMinimumQueryTest.dir\flags.make
CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.obj: CMakeFiles\RangeMinimumQueryTest.dir\includes_CXX.rsp
CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.obj: ..\tests\RangeMinimumQueryNaiveTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Socrasthy\Desktop\Z\kini\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RangeMinimumQueryTest.dir/tests/RangeMinimumQueryNaiveTest.cpp.obj"
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.obj -c C:\Users\Socrasthy\Desktop\Z\kini\tests\RangeMinimumQueryNaiveTest.cpp

CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RangeMinimumQueryTest.dir/tests/RangeMinimumQueryNaiveTest.cpp.i"
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Socrasthy\Desktop\Z\kini\tests\RangeMinimumQueryNaiveTest.cpp > CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.i

CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RangeMinimumQueryTest.dir/tests/RangeMinimumQueryNaiveTest.cpp.s"
	C:\cygwin64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Socrasthy\Desktop\Z\kini\tests\RangeMinimumQueryNaiveTest.cpp -o CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.s

# Object files for target RangeMinimumQueryTest
RangeMinimumQueryTest_OBJECTS = \
"CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.obj"

# External object files for target RangeMinimumQueryTest
RangeMinimumQueryTest_EXTERNAL_OBJECTS =

RangeMinimumQueryTest.exe: CMakeFiles\RangeMinimumQueryTest.dir\tests\RangeMinimumQueryNaiveTest.cpp.obj
RangeMinimumQueryTest.exe: CMakeFiles\RangeMinimumQueryTest.dir\build.make
RangeMinimumQueryTest.exe: libs\gtest-1.6.0\libgtest.a
RangeMinimumQueryTest.exe: libs\gtest-1.6.0\libgtest_main.a
RangeMinimumQueryTest.exe: libs\gtest-1.6.0\libgtest.a
RangeMinimumQueryTest.exe: CMakeFiles\RangeMinimumQueryTest.dir\linklibs.rsp
RangeMinimumQueryTest.exe: CMakeFiles\RangeMinimumQueryTest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Socrasthy\Desktop\Z\kini\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RangeMinimumQueryTest.exe"
	"C:\Program Files (x86)\CMake\bin\cmake.exe" -E rm -f CMakeFiles\RangeMinimumQueryTest.dir/objects.a
	C:\cygwin64\bin\ar.exe cr CMakeFiles\RangeMinimumQueryTest.dir/objects.a @CMakeFiles\RangeMinimumQueryTest.dir\objects1.rsp
	C:\cygwin64\bin\g++.exe -Wl,--whole-archive CMakeFiles\RangeMinimumQueryTest.dir/objects.a -Wl,--no-whole-archive -o RangeMinimumQueryTest.exe -Wl,--out-implib,libRangeMinimumQueryTest.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles\RangeMinimumQueryTest.dir\linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles\RangeMinimumQueryTest.dir\build: RangeMinimumQueryTest.exe

.PHONY : CMakeFiles\RangeMinimumQueryTest.dir\build

CMakeFiles\RangeMinimumQueryTest.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RangeMinimumQueryTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles\RangeMinimumQueryTest.dir\clean

CMakeFiles\RangeMinimumQueryTest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Socrasthy\Desktop\Z\kini C:\Users\Socrasthy\Desktop\Z\kini C:\Users\Socrasthy\Desktop\Z\kini\build C:\Users\Socrasthy\Desktop\Z\kini\build C:\Users\Socrasthy\Desktop\Z\kini\build\CMakeFiles\RangeMinimumQueryTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\RangeMinimumQueryTest.dir\depend

