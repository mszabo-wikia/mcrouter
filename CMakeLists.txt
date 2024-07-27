# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

cmake_minimum_required(VERSION 3.10)

project(mcrouter)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/build/fbcode_builder/CMake"
                      ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "If enabled, compile the tests." OFF)

# Disable Meta-specific functionality for the OSS build.
add_compile_definitions(LIBMC_FBTRACE_DISABLE DISABLE_COMPRESSION)

if(WIN32)
  include(FBCompilerSettingsMSVC)
else()
  include(FBCompilerSettingsUnix)
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -fno-coroutines -Wno-unused-parameter -Wno-uninitialized -Wno-maybe-uninitialized"
  )

  # Create symlink to compile_commands.json for IDE to pick it up
  execute_process(
    COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json)
endif()

# Set up options for generated Thrift client code
include(FBThriftLibrary)
set(THRIFT_OPTIONS stack_arguments sync_methods_return_try
                   deprecated_terse_writes)

find_package(Boost 1.65.1 REQUIRED COMPONENTS system thread filesystem regex
                                              context program_options)

find_package(fmt REQUIRED)
find_package(folly REQUIRED)
find_package(Fizz REQUIRED)
find_package(Glog REQUIRED)
find_package(gflags REQUIRED)
find_package(wangle REQUIRED)
find_package(FBThrift REQUIRED)

include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

if(BUILD_TESTS)
  enable_testing()
  include(CTest)

  find_package(GTest MODULE REQUIRED)

  include(GoogleTest)
endif()

add_subdirectory(mcrouter)

install(TARGETS mcrouter mcpiper)
