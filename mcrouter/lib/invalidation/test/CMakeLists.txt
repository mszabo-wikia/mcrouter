# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

if(NOT BUILD_TESTS)
  return()
endif()

add_executable(
  mcrouter_invalidation_tests "${CMAKE_SOURCE_DIR}/mcrouter/test/main.cpp"
                              McInvalidationKvPairsTest.cpp)

target_link_libraries(
  mcrouter_invalidation_tests
  PRIVATE mcrouter_invalidation mcrouter_network_messages Folly::folly
          GTest::gtest)
