# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/TryCa/Documents/Git/3D-Visualisation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/TryCa/Documents/Git/3D-Visualisation/build

# Include any dependencies generated for this target.
include lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/flags.make

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/flags.make
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/includes_C.rsp
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj: C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/tests/gamma.c
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/TryCa/Documents/Git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj -MF CMakeFiles/gamma.dir/gamma.c.obj.d -o CMakeFiles/gamma.dir/gamma.c.obj -c C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/tests/gamma.c

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gamma.dir/gamma.c.i"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/tests/gamma.c > CMakeFiles/gamma.dir/gamma.c.i

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gamma.dir/gamma.c.s"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/tests/gamma.c -o CMakeFiles/gamma.dir/gamma.c.s

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/flags.make
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/includes_C.rsp
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/deps/glad_gl.c
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/TryCa/Documents/Git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj -MF CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj.d -o CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj -c C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/deps/glad_gl.c

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/gamma.dir/__/deps/glad_gl.c.i"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/deps/glad_gl.c > CMakeFiles/gamma.dir/__/deps/glad_gl.c.i

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/gamma.dir/__/deps/glad_gl.c.s"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/deps/glad_gl.c -o CMakeFiles/gamma.dir/__/deps/glad_gl.c.s

# Object files for target gamma
gamma_OBJECTS = \
"CMakeFiles/gamma.dir/gamma.c.obj" \
"CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj"

# External object files for target gamma
gamma_EXTERNAL_OBJECTS =

lib/glfw-3.3.8/tests/gamma.exe: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/gamma.c.obj
lib/glfw-3.3.8/tests/gamma.exe: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/__/deps/glad_gl.c.obj
lib/glfw-3.3.8/tests/gamma.exe: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/build.make
lib/glfw-3.3.8/tests/gamma.exe: lib/glfw-3.3.8/src/libglfw3.a
lib/glfw-3.3.8/tests/gamma.exe: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/linkLibs.rsp
lib/glfw-3.3.8/tests/gamma.exe: lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/TryCa/Documents/Git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gamma.exe"
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && "C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/gamma.dir/objects.a
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/ar.exe qc CMakeFiles/gamma.dir/objects.a @CMakeFiles/gamma.dir/objects1.rsp
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && C:/msys64/mingw64/bin/cc.exe -mwindows -Wl,--whole-archive CMakeFiles/gamma.dir/objects.a -Wl,--no-whole-archive -o gamma.exe -Wl,--out-implib,libgamma.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/gamma.dir/linkLibs.rsp

# Rule to build all files generated by this target.
lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/build: lib/glfw-3.3.8/tests/gamma.exe
.PHONY : lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/build

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/clean:
	cd C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests && $(CMAKE_COMMAND) -P CMakeFiles/gamma.dir/cmake_clean.cmake
.PHONY : lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/clean

lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/TryCa/Documents/Git/3D-Visualisation C:/Users/TryCa/Documents/Git/3D-Visualisation/lib/glfw-3.3.8/tests C:/Users/TryCa/Documents/Git/3D-Visualisation/build C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests C:/Users/TryCa/Documents/Git/3D-Visualisation/build/lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/glfw-3.3.8/tests/CMakeFiles/gamma.dir/depend
