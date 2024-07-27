# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

if(NOT BUILD_TESTS)
  return()
endif()

add_executable(
  cpp_unit_tests
  "${CMAKE_SOURCE_DIR}/mcrouter/test/main.cpp"
  awriter_test.cpp
  config_api_test.cpp
  exponential_smooth_data_test.cpp
  file_observer_test.cpp
  flavor_test.cpp
  LeaseTokenMapTest.cpp
  mc_route_handle_provider_test.cpp
  McrouterClientUsage.cpp
  observable_test.cpp
  options_test.cpp
  pool_factory_test.cpp
  ProxyRequestContextTest.cpp
  route_test.cpp
  runtime_vars_data_test.cpp)

target_link_libraries(cpp_unit_tests GTest::gtest Folly::folly mcroutercore
                      mcrouterinternal mcrouter_hello_goodbye)

# Run these tests in the source tree so that they can easily load fixture files.
gtest_discover_tests(cpp_unit_tests WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
