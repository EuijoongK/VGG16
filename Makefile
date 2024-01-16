# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /mnt/c/Users/MICS/Desktop/모비스/VGG16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/MICS/Desktop/모비스/VGG16

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/MICS/Desktop/모비스/VGG16/CMakeFiles /mnt/c/Users/MICS/Desktop/모비스/VGG16//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/MICS/Desktop/모비스/VGG16/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named featuremap

# Build rule for target.
featuremap: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 featuremap
.PHONY : featuremap

# fast build rule for target.
featuremap/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/featuremap.dir/build.make CMakeFiles/featuremap.dir/build
.PHONY : featuremap/fast

#=============================================================================
# Target rules for targets named layer

# Build rule for target.
layer: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 layer
.PHONY : layer

# fast build rule for target.
layer/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/build
.PHONY : layer/fast

#=============================================================================
# Target rules for targets named datahandler

# Build rule for target.
datahandler: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 datahandler
.PHONY : datahandler

# fast build rule for target.
datahandler/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/datahandler.dir/build.make CMakeFiles/datahandler.dir/build
.PHONY : datahandler/fast

#=============================================================================
# Target rules for targets named model

# Build rule for target.
model: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 model
.PHONY : model

# fast build rule for target.
model/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/build
.PHONY : model/fast

#=============================================================================
# Target rules for targets named test_0116

# Build rule for target.
test_0116: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_0116
.PHONY : test_0116

# fast build rule for target.
test_0116/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_0116.dir/build.make CMakeFiles/test_0116.dir/build
.PHONY : test_0116/fast

#=============================================================================
# Target rules for targets named test_padding

# Build rule for target.
test_padding: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_padding
.PHONY : test_padding

# fast build rule for target.
test_padding/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_padding.dir/build.make CMakeFiles/test_padding.dir/build
.PHONY : test_padding/fast

src/datahandler/datahandler.o: src/datahandler/datahandler.c.o
.PHONY : src/datahandler/datahandler.o

# target to build an object file
src/datahandler/datahandler.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/datahandler.dir/build.make CMakeFiles/datahandler.dir/src/datahandler/datahandler.c.o
.PHONY : src/datahandler/datahandler.c.o

src/datahandler/datahandler.i: src/datahandler/datahandler.c.i
.PHONY : src/datahandler/datahandler.i

# target to preprocess a source file
src/datahandler/datahandler.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/datahandler.dir/build.make CMakeFiles/datahandler.dir/src/datahandler/datahandler.c.i
.PHONY : src/datahandler/datahandler.c.i

src/datahandler/datahandler.s: src/datahandler/datahandler.c.s
.PHONY : src/datahandler/datahandler.s

# target to generate assembly for a file
src/datahandler/datahandler.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/datahandler.dir/build.make CMakeFiles/datahandler.dir/src/datahandler/datahandler.c.s
.PHONY : src/datahandler/datahandler.c.s

src/featuremap/featuremap.o: src/featuremap/featuremap.c.o
.PHONY : src/featuremap/featuremap.o

# target to build an object file
src/featuremap/featuremap.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/featuremap.dir/build.make CMakeFiles/featuremap.dir/src/featuremap/featuremap.c.o
.PHONY : src/featuremap/featuremap.c.o

src/featuremap/featuremap.i: src/featuremap/featuremap.c.i
.PHONY : src/featuremap/featuremap.i

# target to preprocess a source file
src/featuremap/featuremap.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/featuremap.dir/build.make CMakeFiles/featuremap.dir/src/featuremap/featuremap.c.i
.PHONY : src/featuremap/featuremap.c.i

src/featuremap/featuremap.s: src/featuremap/featuremap.c.s
.PHONY : src/featuremap/featuremap.s

# target to generate assembly for a file
src/featuremap/featuremap.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/featuremap.dir/build.make CMakeFiles/featuremap.dir/src/featuremap/featuremap.c.s
.PHONY : src/featuremap/featuremap.c.s

src/layer/conv_layer.o: src/layer/conv_layer.c.o
.PHONY : src/layer/conv_layer.o

# target to build an object file
src/layer/conv_layer.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/conv_layer.c.o
.PHONY : src/layer/conv_layer.c.o

src/layer/conv_layer.i: src/layer/conv_layer.c.i
.PHONY : src/layer/conv_layer.i

# target to preprocess a source file
src/layer/conv_layer.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/conv_layer.c.i
.PHONY : src/layer/conv_layer.c.i

src/layer/conv_layer.s: src/layer/conv_layer.c.s
.PHONY : src/layer/conv_layer.s

# target to generate assembly for a file
src/layer/conv_layer.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/conv_layer.c.s
.PHONY : src/layer/conv_layer.c.s

src/layer/fc_layer.o: src/layer/fc_layer.c.o
.PHONY : src/layer/fc_layer.o

# target to build an object file
src/layer/fc_layer.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/fc_layer.c.o
.PHONY : src/layer/fc_layer.c.o

src/layer/fc_layer.i: src/layer/fc_layer.c.i
.PHONY : src/layer/fc_layer.i

# target to preprocess a source file
src/layer/fc_layer.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/fc_layer.c.i
.PHONY : src/layer/fc_layer.c.i

src/layer/fc_layer.s: src/layer/fc_layer.c.s
.PHONY : src/layer/fc_layer.s

# target to generate assembly for a file
src/layer/fc_layer.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/fc_layer.c.s
.PHONY : src/layer/fc_layer.c.s

src/layer/maxpool_layer.o: src/layer/maxpool_layer.c.o
.PHONY : src/layer/maxpool_layer.o

# target to build an object file
src/layer/maxpool_layer.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/maxpool_layer.c.o
.PHONY : src/layer/maxpool_layer.c.o

src/layer/maxpool_layer.i: src/layer/maxpool_layer.c.i
.PHONY : src/layer/maxpool_layer.i

# target to preprocess a source file
src/layer/maxpool_layer.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/maxpool_layer.c.i
.PHONY : src/layer/maxpool_layer.c.i

src/layer/maxpool_layer.s: src/layer/maxpool_layer.c.s
.PHONY : src/layer/maxpool_layer.s

# target to generate assembly for a file
src/layer/maxpool_layer.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/maxpool_layer.c.s
.PHONY : src/layer/maxpool_layer.c.s

src/layer/zeropadding_layer.o: src/layer/zeropadding_layer.c.o
.PHONY : src/layer/zeropadding_layer.o

# target to build an object file
src/layer/zeropadding_layer.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/zeropadding_layer.c.o
.PHONY : src/layer/zeropadding_layer.c.o

src/layer/zeropadding_layer.i: src/layer/zeropadding_layer.c.i
.PHONY : src/layer/zeropadding_layer.i

# target to preprocess a source file
src/layer/zeropadding_layer.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/zeropadding_layer.c.i
.PHONY : src/layer/zeropadding_layer.c.i

src/layer/zeropadding_layer.s: src/layer/zeropadding_layer.c.s
.PHONY : src/layer/zeropadding_layer.s

# target to generate assembly for a file
src/layer/zeropadding_layer.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/layer.dir/build.make CMakeFiles/layer.dir/src/layer/zeropadding_layer.c.s
.PHONY : src/layer/zeropadding_layer.c.s

src/model/model.o: src/model/model.c.o
.PHONY : src/model/model.o

# target to build an object file
src/model/model.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/model/model.c.o
.PHONY : src/model/model.c.o

src/model/model.i: src/model/model.c.i
.PHONY : src/model/model.i

# target to preprocess a source file
src/model/model.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/model/model.c.i
.PHONY : src/model/model.c.i

src/model/model.s: src/model/model.c.s
.PHONY : src/model/model.s

# target to generate assembly for a file
src/model/model.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/model.dir/build.make CMakeFiles/model.dir/src/model/model.c.s
.PHONY : src/model/model.c.s

test/test_0116.o: test/test_0116.c.o
.PHONY : test/test_0116.o

# target to build an object file
test/test_0116.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_0116.dir/build.make CMakeFiles/test_0116.dir/test/test_0116.c.o
.PHONY : test/test_0116.c.o

test/test_0116.i: test/test_0116.c.i
.PHONY : test/test_0116.i

# target to preprocess a source file
test/test_0116.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_0116.dir/build.make CMakeFiles/test_0116.dir/test/test_0116.c.i
.PHONY : test/test_0116.c.i

test/test_0116.s: test/test_0116.c.s
.PHONY : test/test_0116.s

# target to generate assembly for a file
test/test_0116.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_0116.dir/build.make CMakeFiles/test_0116.dir/test/test_0116.c.s
.PHONY : test/test_0116.c.s

test/test_padding.o: test/test_padding.c.o
.PHONY : test/test_padding.o

# target to build an object file
test/test_padding.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_padding.dir/build.make CMakeFiles/test_padding.dir/test/test_padding.c.o
.PHONY : test/test_padding.c.o

test/test_padding.i: test/test_padding.c.i
.PHONY : test/test_padding.i

# target to preprocess a source file
test/test_padding.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_padding.dir/build.make CMakeFiles/test_padding.dir/test/test_padding.c.i
.PHONY : test/test_padding.c.i

test/test_padding.s: test/test_padding.c.s
.PHONY : test/test_padding.s

# target to generate assembly for a file
test/test_padding.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_padding.dir/build.make CMakeFiles/test_padding.dir/test/test_padding.c.s
.PHONY : test/test_padding.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... datahandler"
	@echo "... featuremap"
	@echo "... layer"
	@echo "... model"
	@echo "... test_0116"
	@echo "... test_padding"
	@echo "... src/datahandler/datahandler.o"
	@echo "... src/datahandler/datahandler.i"
	@echo "... src/datahandler/datahandler.s"
	@echo "... src/featuremap/featuremap.o"
	@echo "... src/featuremap/featuremap.i"
	@echo "... src/featuremap/featuremap.s"
	@echo "... src/layer/conv_layer.o"
	@echo "... src/layer/conv_layer.i"
	@echo "... src/layer/conv_layer.s"
	@echo "... src/layer/fc_layer.o"
	@echo "... src/layer/fc_layer.i"
	@echo "... src/layer/fc_layer.s"
	@echo "... src/layer/maxpool_layer.o"
	@echo "... src/layer/maxpool_layer.i"
	@echo "... src/layer/maxpool_layer.s"
	@echo "... src/layer/zeropadding_layer.o"
	@echo "... src/layer/zeropadding_layer.i"
	@echo "... src/layer/zeropadding_layer.s"
	@echo "... src/model/model.o"
	@echo "... src/model/model.i"
	@echo "... src/model/model.s"
	@echo "... test/test_0116.o"
	@echo "... test/test_0116.i"
	@echo "... test/test_0116.s"
	@echo "... test/test_padding.o"
	@echo "... test/test_padding.i"
	@echo "... test/test_padding.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
