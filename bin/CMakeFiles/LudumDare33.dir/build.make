# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.3

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ianma\Development\ludumdare33\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ianma\Development\ludumdare33\bin

# Include any dependencies generated for this target.
include CMakeFiles/LudumDare33.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LudumDare33.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LudumDare33.dir/flags.make

CMakeFiles/LudumDare33.dir/main.cpp.obj: CMakeFiles/LudumDare33.dir/flags.make
CMakeFiles/LudumDare33.dir/main.cpp.obj: CMakeFiles/LudumDare33.dir/includes_CXX.rsp
CMakeFiles/LudumDare33.dir/main.cpp.obj: C:/Users/ianma/Development/ludumdare33/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ianma\Development\ludumdare33\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LudumDare33.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\LudumDare33.dir\main.cpp.obj -c C:\Users\ianma\Development\ludumdare33\src\main.cpp

CMakeFiles/LudumDare33.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LudumDare33.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\ianma\Development\ludumdare33\src\main.cpp > CMakeFiles\LudumDare33.dir\main.cpp.i

CMakeFiles/LudumDare33.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LudumDare33.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\ianma\Development\ludumdare33\src\main.cpp -o CMakeFiles\LudumDare33.dir\main.cpp.s

CMakeFiles/LudumDare33.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/LudumDare33.dir/main.cpp.obj.requires

CMakeFiles/LudumDare33.dir/main.cpp.obj.provides: CMakeFiles/LudumDare33.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\LudumDare33.dir\build.make CMakeFiles/LudumDare33.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/LudumDare33.dir/main.cpp.obj.provides

CMakeFiles/LudumDare33.dir/main.cpp.obj.provides.build: CMakeFiles/LudumDare33.dir/main.cpp.obj


CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj: CMakeFiles/LudumDare33.dir/flags.make
CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj: CMakeFiles/LudumDare33.dir/includes_CXX.rsp
CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj: C:/Users/ianma/Development/ludumdare33/src/gameprefix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ianma\Development\ludumdare33\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\LudumDare33.dir\gameprefix.cpp.obj -c C:\Users\ianma\Development\ludumdare33\src\gameprefix.cpp

CMakeFiles/LudumDare33.dir/gameprefix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LudumDare33.dir/gameprefix.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\ianma\Development\ludumdare33\src\gameprefix.cpp > CMakeFiles\LudumDare33.dir\gameprefix.cpp.i

CMakeFiles/LudumDare33.dir/gameprefix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LudumDare33.dir/gameprefix.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\ianma\Development\ludumdare33\src\gameprefix.cpp -o CMakeFiles\LudumDare33.dir\gameprefix.cpp.s

CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.requires:

.PHONY : CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.requires

CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.provides: CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.requires
	$(MAKE) -f CMakeFiles\LudumDare33.dir\build.make CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.provides.build
.PHONY : CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.provides

CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.provides.build: CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj


# Object files for target LudumDare33
LudumDare33_OBJECTS = \
"CMakeFiles/LudumDare33.dir/main.cpp.obj" \
"CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj"

# External object files for target LudumDare33
LudumDare33_EXTERNAL_OBJECTS =

LudumDare33.exe: CMakeFiles/LudumDare33.dir/main.cpp.obj
LudumDare33.exe: CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj
LudumDare33.exe: CMakeFiles/LudumDare33.dir/build.make
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_acodec-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_audio-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/libvorbis-1.3.2-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_color-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_dialog-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_font-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_image-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_memfile-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_physfs-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/liballegro_primitives-5.0.10-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/libdumb-0.9.3-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/libFLAC-1.2.1-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/libogg-1.2.1-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/libzlib-1.2.5-static-mt.a
LudumDare33.exe: C:/Users/ianma/Development/ludumdare33/src/allegro/lib/libopenal-1.14-static-mt.a
LudumDare33.exe: CMakeFiles/LudumDare33.dir/linklibs.rsp
LudumDare33.exe: CMakeFiles/LudumDare33.dir/objects1.rsp
LudumDare33.exe: CMakeFiles/LudumDare33.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ianma\Development\ludumdare33\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LudumDare33.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LudumDare33.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LudumDare33.dir/build: LudumDare33.exe

.PHONY : CMakeFiles/LudumDare33.dir/build

CMakeFiles/LudumDare33.dir/requires: CMakeFiles/LudumDare33.dir/main.cpp.obj.requires
CMakeFiles/LudumDare33.dir/requires: CMakeFiles/LudumDare33.dir/gameprefix.cpp.obj.requires

.PHONY : CMakeFiles/LudumDare33.dir/requires

CMakeFiles/LudumDare33.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LudumDare33.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LudumDare33.dir/clean

CMakeFiles/LudumDare33.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ianma\Development\ludumdare33\src C:\Users\ianma\Development\ludumdare33\src C:\Users\ianma\Development\ludumdare33\bin C:\Users\ianma\Development\ludumdare33\bin C:\Users\ianma\Development\ludumdare33\bin\CMakeFiles\LudumDare33.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LudumDare33.dir/depend

