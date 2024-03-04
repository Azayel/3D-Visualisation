# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/asayel/Documents/git/3D-Visualisation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asayel/Documents/git/3D-Visualisation/build

# Include any dependencies generated for this target.
include CMakeFiles/Visual3D.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Visual3D.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Visual3D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Visual3D.dir/flags.make

CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o: CMakeFiles/Visual3D.dir/flags.make
CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o: /home/asayel/Documents/git/3D-Visualisation/src/CubeRenderer.cpp
CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o: CMakeFiles/Visual3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o -MF CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o.d -o CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o -c /home/asayel/Documents/git/3D-Visualisation/src/CubeRenderer.cpp

CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asayel/Documents/git/3D-Visualisation/src/CubeRenderer.cpp > CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.i

CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asayel/Documents/git/3D-Visualisation/src/CubeRenderer.cpp -o CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.s

CMakeFiles/Visual3D.dir/src/Cubes.cpp.o: CMakeFiles/Visual3D.dir/flags.make
CMakeFiles/Visual3D.dir/src/Cubes.cpp.o: /home/asayel/Documents/git/3D-Visualisation/src/Cubes.cpp
CMakeFiles/Visual3D.dir/src/Cubes.cpp.o: CMakeFiles/Visual3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Visual3D.dir/src/Cubes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visual3D.dir/src/Cubes.cpp.o -MF CMakeFiles/Visual3D.dir/src/Cubes.cpp.o.d -o CMakeFiles/Visual3D.dir/src/Cubes.cpp.o -c /home/asayel/Documents/git/3D-Visualisation/src/Cubes.cpp

CMakeFiles/Visual3D.dir/src/Cubes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Visual3D.dir/src/Cubes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asayel/Documents/git/3D-Visualisation/src/Cubes.cpp > CMakeFiles/Visual3D.dir/src/Cubes.cpp.i

CMakeFiles/Visual3D.dir/src/Cubes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Visual3D.dir/src/Cubes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asayel/Documents/git/3D-Visualisation/src/Cubes.cpp -o CMakeFiles/Visual3D.dir/src/Cubes.cpp.s

CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o: CMakeFiles/Visual3D.dir/flags.make
CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o: /home/asayel/Documents/git/3D-Visualisation/src/RayRenderer.cpp
CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o: CMakeFiles/Visual3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o -MF CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o.d -o CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o -c /home/asayel/Documents/git/3D-Visualisation/src/RayRenderer.cpp

CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asayel/Documents/git/3D-Visualisation/src/RayRenderer.cpp > CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.i

CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asayel/Documents/git/3D-Visualisation/src/RayRenderer.cpp -o CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.s

CMakeFiles/Visual3D.dir/src/Shader.cpp.o: CMakeFiles/Visual3D.dir/flags.make
CMakeFiles/Visual3D.dir/src/Shader.cpp.o: /home/asayel/Documents/git/3D-Visualisation/src/Shader.cpp
CMakeFiles/Visual3D.dir/src/Shader.cpp.o: CMakeFiles/Visual3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Visual3D.dir/src/Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visual3D.dir/src/Shader.cpp.o -MF CMakeFiles/Visual3D.dir/src/Shader.cpp.o.d -o CMakeFiles/Visual3D.dir/src/Shader.cpp.o -c /home/asayel/Documents/git/3D-Visualisation/src/Shader.cpp

CMakeFiles/Visual3D.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Visual3D.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asayel/Documents/git/3D-Visualisation/src/Shader.cpp > CMakeFiles/Visual3D.dir/src/Shader.cpp.i

CMakeFiles/Visual3D.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Visual3D.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asayel/Documents/git/3D-Visualisation/src/Shader.cpp -o CMakeFiles/Visual3D.dir/src/Shader.cpp.s

CMakeFiles/Visual3D.dir/src/main.cpp.o: CMakeFiles/Visual3D.dir/flags.make
CMakeFiles/Visual3D.dir/src/main.cpp.o: /home/asayel/Documents/git/3D-Visualisation/src/main.cpp
CMakeFiles/Visual3D.dir/src/main.cpp.o: CMakeFiles/Visual3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Visual3D.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Visual3D.dir/src/main.cpp.o -MF CMakeFiles/Visual3D.dir/src/main.cpp.o.d -o CMakeFiles/Visual3D.dir/src/main.cpp.o -c /home/asayel/Documents/git/3D-Visualisation/src/main.cpp

CMakeFiles/Visual3D.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Visual3D.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asayel/Documents/git/3D-Visualisation/src/main.cpp > CMakeFiles/Visual3D.dir/src/main.cpp.i

CMakeFiles/Visual3D.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Visual3D.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asayel/Documents/git/3D-Visualisation/src/main.cpp -o CMakeFiles/Visual3D.dir/src/main.cpp.s

CMakeFiles/Visual3D.dir/src/glad.c.o: CMakeFiles/Visual3D.dir/flags.make
CMakeFiles/Visual3D.dir/src/glad.c.o: /home/asayel/Documents/git/3D-Visualisation/src/glad.c
CMakeFiles/Visual3D.dir/src/glad.c.o: CMakeFiles/Visual3D.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Visual3D.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Visual3D.dir/src/glad.c.o -MF CMakeFiles/Visual3D.dir/src/glad.c.o.d -o CMakeFiles/Visual3D.dir/src/glad.c.o -c /home/asayel/Documents/git/3D-Visualisation/src/glad.c

CMakeFiles/Visual3D.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Visual3D.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asayel/Documents/git/3D-Visualisation/src/glad.c > CMakeFiles/Visual3D.dir/src/glad.c.i

CMakeFiles/Visual3D.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Visual3D.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asayel/Documents/git/3D-Visualisation/src/glad.c -o CMakeFiles/Visual3D.dir/src/glad.c.s

# Object files for target Visual3D
Visual3D_OBJECTS = \
"CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o" \
"CMakeFiles/Visual3D.dir/src/Cubes.cpp.o" \
"CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o" \
"CMakeFiles/Visual3D.dir/src/Shader.cpp.o" \
"CMakeFiles/Visual3D.dir/src/main.cpp.o" \
"CMakeFiles/Visual3D.dir/src/glad.c.o"

# External object files for target Visual3D
Visual3D_EXTERNAL_OBJECTS =

Visual3D: CMakeFiles/Visual3D.dir/src/CubeRenderer.cpp.o
Visual3D: CMakeFiles/Visual3D.dir/src/Cubes.cpp.o
Visual3D: CMakeFiles/Visual3D.dir/src/RayRenderer.cpp.o
Visual3D: CMakeFiles/Visual3D.dir/src/Shader.cpp.o
Visual3D: CMakeFiles/Visual3D.dir/src/main.cpp.o
Visual3D: CMakeFiles/Visual3D.dir/src/glad.c.o
Visual3D: CMakeFiles/Visual3D.dir/build.make
Visual3D: CMakeFiles/Visual3D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Visual3D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Visual3D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Visual3D.dir/build: Visual3D
.PHONY : CMakeFiles/Visual3D.dir/build

CMakeFiles/Visual3D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Visual3D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Visual3D.dir/clean

CMakeFiles/Visual3D.dir/depend:
	cd /home/asayel/Documents/git/3D-Visualisation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asayel/Documents/git/3D-Visualisation /home/asayel/Documents/git/3D-Visualisation /home/asayel/Documents/git/3D-Visualisation/build /home/asayel/Documents/git/3D-Visualisation/build /home/asayel/Documents/git/3D-Visualisation/build/CMakeFiles/Visual3D.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Visual3D.dir/depend
