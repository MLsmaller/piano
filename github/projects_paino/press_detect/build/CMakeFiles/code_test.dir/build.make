# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/cy/projects/piano/press_detect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cy/projects/piano/press_detect/build

# Include any dependencies generated for this target.
include CMakeFiles/code_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/code_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/code_test.dir/flags.make

CMakeFiles/code_test.dir/detect.cpp.o: CMakeFiles/code_test.dir/flags.make
CMakeFiles/code_test.dir/detect.cpp.o: ../detect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/code_test.dir/detect.cpp.o"
	/opt/rh/devtoolset-4/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/code_test.dir/detect.cpp.o -c /home/cy/projects/piano/press_detect/detect.cpp

CMakeFiles/code_test.dir/detect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code_test.dir/detect.cpp.i"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cy/projects/piano/press_detect/detect.cpp > CMakeFiles/code_test.dir/detect.cpp.i

CMakeFiles/code_test.dir/detect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code_test.dir/detect.cpp.s"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cy/projects/piano/press_detect/detect.cpp -o CMakeFiles/code_test.dir/detect.cpp.s

CMakeFiles/code_test.dir/detect.cpp.o.requires:

.PHONY : CMakeFiles/code_test.dir/detect.cpp.o.requires

CMakeFiles/code_test.dir/detect.cpp.o.provides: CMakeFiles/code_test.dir/detect.cpp.o.requires
	$(MAKE) -f CMakeFiles/code_test.dir/build.make CMakeFiles/code_test.dir/detect.cpp.o.provides.build
.PHONY : CMakeFiles/code_test.dir/detect.cpp.o.provides

CMakeFiles/code_test.dir/detect.cpp.o.provides.build: CMakeFiles/code_test.dir/detect.cpp.o


CMakeFiles/code_test.dir/functions/bwlabel.cpp.o: CMakeFiles/code_test.dir/flags.make
CMakeFiles/code_test.dir/functions/bwlabel.cpp.o: ../functions/bwlabel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/code_test.dir/functions/bwlabel.cpp.o"
	/opt/rh/devtoolset-4/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/code_test.dir/functions/bwlabel.cpp.o -c /home/cy/projects/piano/press_detect/functions/bwlabel.cpp

CMakeFiles/code_test.dir/functions/bwlabel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code_test.dir/functions/bwlabel.cpp.i"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cy/projects/piano/press_detect/functions/bwlabel.cpp > CMakeFiles/code_test.dir/functions/bwlabel.cpp.i

CMakeFiles/code_test.dir/functions/bwlabel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code_test.dir/functions/bwlabel.cpp.s"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cy/projects/piano/press_detect/functions/bwlabel.cpp -o CMakeFiles/code_test.dir/functions/bwlabel.cpp.s

CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.requires:

.PHONY : CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.requires

CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.provides: CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.requires
	$(MAKE) -f CMakeFiles/code_test.dir/build.make CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.provides.build
.PHONY : CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.provides

CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.provides.build: CMakeFiles/code_test.dir/functions/bwlabel.cpp.o


CMakeFiles/code_test.dir/functions/detect_key.cpp.o: CMakeFiles/code_test.dir/flags.make
CMakeFiles/code_test.dir/functions/detect_key.cpp.o: ../functions/detect_key.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/code_test.dir/functions/detect_key.cpp.o"
	/opt/rh/devtoolset-4/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/code_test.dir/functions/detect_key.cpp.o -c /home/cy/projects/piano/press_detect/functions/detect_key.cpp

CMakeFiles/code_test.dir/functions/detect_key.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code_test.dir/functions/detect_key.cpp.i"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cy/projects/piano/press_detect/functions/detect_key.cpp > CMakeFiles/code_test.dir/functions/detect_key.cpp.i

CMakeFiles/code_test.dir/functions/detect_key.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code_test.dir/functions/detect_key.cpp.s"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cy/projects/piano/press_detect/functions/detect_key.cpp -o CMakeFiles/code_test.dir/functions/detect_key.cpp.s

CMakeFiles/code_test.dir/functions/detect_key.cpp.o.requires:

.PHONY : CMakeFiles/code_test.dir/functions/detect_key.cpp.o.requires

CMakeFiles/code_test.dir/functions/detect_key.cpp.o.provides: CMakeFiles/code_test.dir/functions/detect_key.cpp.o.requires
	$(MAKE) -f CMakeFiles/code_test.dir/build.make CMakeFiles/code_test.dir/functions/detect_key.cpp.o.provides.build
.PHONY : CMakeFiles/code_test.dir/functions/detect_key.cpp.o.provides

CMakeFiles/code_test.dir/functions/detect_key.cpp.o.provides.build: CMakeFiles/code_test.dir/functions/detect_key.cpp.o


CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o: CMakeFiles/code_test.dir/flags.make
CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o: ../functions/get_keyboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o"
	/opt/rh/devtoolset-4/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o -c /home/cy/projects/piano/press_detect/functions/get_keyboard.cpp

CMakeFiles/code_test.dir/functions/get_keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code_test.dir/functions/get_keyboard.cpp.i"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cy/projects/piano/press_detect/functions/get_keyboard.cpp > CMakeFiles/code_test.dir/functions/get_keyboard.cpp.i

CMakeFiles/code_test.dir/functions/get_keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code_test.dir/functions/get_keyboard.cpp.s"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cy/projects/piano/press_detect/functions/get_keyboard.cpp -o CMakeFiles/code_test.dir/functions/get_keyboard.cpp.s

CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.requires:

.PHONY : CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.requires

CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.provides: CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.requires
	$(MAKE) -f CMakeFiles/code_test.dir/build.make CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.provides.build
.PHONY : CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.provides

CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.provides.build: CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o


CMakeFiles/code_test.dir/functions/to_json.cpp.o: CMakeFiles/code_test.dir/flags.make
CMakeFiles/code_test.dir/functions/to_json.cpp.o: ../functions/to_json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/code_test.dir/functions/to_json.cpp.o"
	/opt/rh/devtoolset-4/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/code_test.dir/functions/to_json.cpp.o -c /home/cy/projects/piano/press_detect/functions/to_json.cpp

CMakeFiles/code_test.dir/functions/to_json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code_test.dir/functions/to_json.cpp.i"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cy/projects/piano/press_detect/functions/to_json.cpp > CMakeFiles/code_test.dir/functions/to_json.cpp.i

CMakeFiles/code_test.dir/functions/to_json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code_test.dir/functions/to_json.cpp.s"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cy/projects/piano/press_detect/functions/to_json.cpp -o CMakeFiles/code_test.dir/functions/to_json.cpp.s

CMakeFiles/code_test.dir/functions/to_json.cpp.o.requires:

.PHONY : CMakeFiles/code_test.dir/functions/to_json.cpp.o.requires

CMakeFiles/code_test.dir/functions/to_json.cpp.o.provides: CMakeFiles/code_test.dir/functions/to_json.cpp.o.requires
	$(MAKE) -f CMakeFiles/code_test.dir/build.make CMakeFiles/code_test.dir/functions/to_json.cpp.o.provides.build
.PHONY : CMakeFiles/code_test.dir/functions/to_json.cpp.o.provides

CMakeFiles/code_test.dir/functions/to_json.cpp.o.provides.build: CMakeFiles/code_test.dir/functions/to_json.cpp.o


CMakeFiles/code_test.dir/functions/utils.cpp.o: CMakeFiles/code_test.dir/flags.make
CMakeFiles/code_test.dir/functions/utils.cpp.o: ../functions/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/code_test.dir/functions/utils.cpp.o"
	/opt/rh/devtoolset-4/root/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/code_test.dir/functions/utils.cpp.o -c /home/cy/projects/piano/press_detect/functions/utils.cpp

CMakeFiles/code_test.dir/functions/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/code_test.dir/functions/utils.cpp.i"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cy/projects/piano/press_detect/functions/utils.cpp > CMakeFiles/code_test.dir/functions/utils.cpp.i

CMakeFiles/code_test.dir/functions/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/code_test.dir/functions/utils.cpp.s"
	/opt/rh/devtoolset-4/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cy/projects/piano/press_detect/functions/utils.cpp -o CMakeFiles/code_test.dir/functions/utils.cpp.s

CMakeFiles/code_test.dir/functions/utils.cpp.o.requires:

.PHONY : CMakeFiles/code_test.dir/functions/utils.cpp.o.requires

CMakeFiles/code_test.dir/functions/utils.cpp.o.provides: CMakeFiles/code_test.dir/functions/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/code_test.dir/build.make CMakeFiles/code_test.dir/functions/utils.cpp.o.provides.build
.PHONY : CMakeFiles/code_test.dir/functions/utils.cpp.o.provides

CMakeFiles/code_test.dir/functions/utils.cpp.o.provides.build: CMakeFiles/code_test.dir/functions/utils.cpp.o


# Object files for target code_test
code_test_OBJECTS = \
"CMakeFiles/code_test.dir/detect.cpp.o" \
"CMakeFiles/code_test.dir/functions/bwlabel.cpp.o" \
"CMakeFiles/code_test.dir/functions/detect_key.cpp.o" \
"CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o" \
"CMakeFiles/code_test.dir/functions/to_json.cpp.o" \
"CMakeFiles/code_test.dir/functions/utils.cpp.o"

# External object files for target code_test
code_test_EXTERNAL_OBJECTS =

code_test: CMakeFiles/code_test.dir/detect.cpp.o
code_test: CMakeFiles/code_test.dir/functions/bwlabel.cpp.o
code_test: CMakeFiles/code_test.dir/functions/detect_key.cpp.o
code_test: CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o
code_test: CMakeFiles/code_test.dir/functions/to_json.cpp.o
code_test: CMakeFiles/code_test.dir/functions/utils.cpp.o
code_test: CMakeFiles/code_test.dir/build.make
code_test: /usr/local/lib64/libopencv_cudabgsegm.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudaobjdetect.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudastereo.so.3.4.0
code_test: /usr/local/lib64/libopencv_dnn.so.3.4.0
code_test: /usr/local/lib64/libopencv_ml.so.3.4.0
code_test: /usr/local/lib64/libopencv_shape.so.3.4.0
code_test: /usr/local/lib64/libopencv_stitching.so.3.4.0
code_test: /usr/local/lib64/libopencv_superres.so.3.4.0
code_test: /usr/local/lib64/libopencv_videostab.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudafeatures2d.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudacodec.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudaoptflow.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudalegacy.so.3.4.0
code_test: /usr/local/lib64/libopencv_calib3d.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudawarping.so.3.4.0
code_test: /usr/local/lib64/libopencv_features2d.so.3.4.0
code_test: /usr/local/lib64/libopencv_flann.so.3.4.0
code_test: /usr/local/lib64/libopencv_highgui.so.3.4.0
code_test: /usr/local/lib64/libopencv_objdetect.so.3.4.0
code_test: /usr/local/lib64/libopencv_photo.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudaimgproc.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudafilters.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudaarithm.so.3.4.0
code_test: /usr/local/lib64/libopencv_video.so.3.4.0
code_test: /usr/local/lib64/libopencv_videoio.so.3.4.0
code_test: /usr/local/lib64/libopencv_imgcodecs.so.3.4.0
code_test: /usr/local/lib64/libopencv_imgproc.so.3.4.0
code_test: /usr/local/lib64/libopencv_core.so.3.4.0
code_test: /usr/local/lib64/libopencv_cudev.so.3.4.0
code_test: CMakeFiles/code_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cy/projects/piano/press_detect/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable code_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/code_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/code_test.dir/build: code_test

.PHONY : CMakeFiles/code_test.dir/build

CMakeFiles/code_test.dir/requires: CMakeFiles/code_test.dir/detect.cpp.o.requires
CMakeFiles/code_test.dir/requires: CMakeFiles/code_test.dir/functions/bwlabel.cpp.o.requires
CMakeFiles/code_test.dir/requires: CMakeFiles/code_test.dir/functions/detect_key.cpp.o.requires
CMakeFiles/code_test.dir/requires: CMakeFiles/code_test.dir/functions/get_keyboard.cpp.o.requires
CMakeFiles/code_test.dir/requires: CMakeFiles/code_test.dir/functions/to_json.cpp.o.requires
CMakeFiles/code_test.dir/requires: CMakeFiles/code_test.dir/functions/utils.cpp.o.requires

.PHONY : CMakeFiles/code_test.dir/requires

CMakeFiles/code_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/code_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/code_test.dir/clean

CMakeFiles/code_test.dir/depend:
	cd /home/cy/projects/piano/press_detect/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cy/projects/piano/press_detect /home/cy/projects/piano/press_detect /home/cy/projects/piano/press_detect/build /home/cy/projects/piano/press_detect/build /home/cy/projects/piano/press_detect/build/CMakeFiles/code_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/code_test.dir/depend

