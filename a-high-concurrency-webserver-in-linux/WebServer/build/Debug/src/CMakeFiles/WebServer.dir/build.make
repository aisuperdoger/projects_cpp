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
CMAKE_COMMAND = /home/zwl/software/anaconda3/lib/python3.9/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/zwl/software/anaconda3/lib/python3.9/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug

# Include any dependencies generated for this target.
include src/CMakeFiles/WebServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/WebServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/WebServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/WebServer.dir/flags.make

src/CMakeFiles/WebServer.dir/Main.cpp.o: src/CMakeFiles/WebServer.dir/flags.make
src/CMakeFiles/WebServer.dir/Main.cpp.o: /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer/src/Main.cpp
src/CMakeFiles/WebServer.dir/Main.cpp.o: src/CMakeFiles/WebServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/WebServer.dir/Main.cpp.o"
	cd /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/WebServer.dir/Main.cpp.o -MF CMakeFiles/WebServer.dir/Main.cpp.o.d -o CMakeFiles/WebServer.dir/Main.cpp.o -c /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer/src/Main.cpp

src/CMakeFiles/WebServer.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Main.cpp.i"
	cd /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer/src/Main.cpp > CMakeFiles/WebServer.dir/Main.cpp.i

src/CMakeFiles/WebServer.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Main.cpp.s"
	cd /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer/src/Main.cpp -o CMakeFiles/WebServer.dir/Main.cpp.s

# Object files for target WebServer
WebServer_OBJECTS = \
"CMakeFiles/WebServer.dir/Main.cpp.o"

# External object files for target WebServer
WebServer_EXTERNAL_OBJECTS =

src/WebServer: src/CMakeFiles/WebServer.dir/Main.cpp.o
src/WebServer: src/CMakeFiles/WebServer.dir/build.make
src/WebServer: src/server/libserver.a
src/WebServer: src/base/libserver_base.a
src/WebServer: src/threadPool/libthreadPool.a
src/WebServer: src/reactor/libreactor.a
src/WebServer: src/connection/libconnection.a
src/WebServer: src/reactor/libreactor.a
src/WebServer: src/connection/libconnection.a
src/WebServer: src/manager/libmanager.a
src/WebServer: src/LFUCache/libLFUCache.a
src/WebServer: src/memory/libmemory.a
src/WebServer: src/base/libserver_base.a
src/WebServer: src/package/libpackage.a
src/WebServer: src/CMakeFiles/WebServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WebServer"
	cd /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WebServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/WebServer.dir/build: src/WebServer
.PHONY : src/CMakeFiles/WebServer.dir/build

src/CMakeFiles/WebServer.dir/clean:
	cd /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src && $(CMAKE_COMMAND) -P CMakeFiles/WebServer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/WebServer.dir/clean

src/CMakeFiles/WebServer.dir/depend:
	cd /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/MyWebServer/src /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src /home/zwl/projects/cpp/projects_cpp/a-high-concurrency-webserver-in-linux/WebServer/build/Debug/src/CMakeFiles/WebServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/WebServer.dir/depend
