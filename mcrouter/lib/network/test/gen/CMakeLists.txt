# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_fbthrift_cpp_library(mcrouter_network_carbon_test_thrift CarbonTest.thrift
                         OPTIONS "${THRIFT_OPTIONS}")

add_library(mcrouter_network_tests_gen CarbonTestMessages.cpp
                                       CarbonTestMessagesThrift.cpp)

target_link_libraries(mcrouter_network_tests_gen
                      PUBLIC mcrouter_network_carbon_test_thrift)
