# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

if(NOT BUILD_TESTS)
  return()
endif()

add_executable(mcrouter_fbi_tests "${CMAKE_SOURCE_DIR}/mcrouter/test/main.cpp"
                                  sem_test.cpp test_util.cpp hash_test.cpp)

target_link_libraries(mcrouter_fbi_tests PRIVATE mcrouter_fbi GTest::gtest
                                                 Folly::folly)

gtest_discover_tests(mcrouter_fbi_tests)
