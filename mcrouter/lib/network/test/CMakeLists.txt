# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

if(NOT BUILD_TESTS)
  return()
endif()

add_executable(mcrouter_mock_mc_server MockMc.cpp MockMcServer.cpp)

target_link_libraries(
  mcrouter_mock_mc_server
  PRIVATE mcrouter_network
          mcrouterinternal
          Folly::folly
          FBThrift::thriftcpp2
          FBThrift::async
          FBThrift::serverdbginfo
          FBThrift::transport
          FBThrift::thriftanyrep
          FBThrift::thrifttype
          FBThrift::thrifttyperep
          FBThrift::thriftprotocol
          FBThrift::rpcmetadata
          FBThrift::thriftannotation
          FBThrift::thriftmetadata
          FBThrift::concurrency
          FBThrift::runtime
          FBThrift::thrift-core)

add_executable(mcrouter_mock_mc_thrift_server MockMc.cpp MockMcThriftServer.cpp)

target_link_libraries(
  mcrouter_mock_mc_thrift_server
  PRIVATE mcrouter_network
          memcache_service_thrift
          mcrouterinternal
          Folly::folly
          FBThrift::thriftcpp2
          FBThrift::async
          FBThrift::serverdbginfo
          FBThrift::transport
          FBThrift::thriftanyrep
          FBThrift::thrifttype
          FBThrift::thrifttyperep
          FBThrift::thriftprotocol
          FBThrift::rpcmetadata
          FBThrift::thriftannotation
          FBThrift::thriftmetadata
          FBThrift::concurrency
          FBThrift::runtime
          FBThrift::thrift-core)

add_executable(mcrouter_mock_mc_server_dual MockMc.cpp MockMcServerDual.cpp)

target_link_libraries(
  mcrouter_mock_mc_server_dual
  PRIVATE mcrouter_network
          memcache_service_thrift
          mcrouterinternal
          Folly::folly
          FBThrift::thriftcpp2
          FBThrift::async
          FBThrift::serverdbginfo
          FBThrift::transport
          FBThrift::thriftanyrep
          FBThrift::thrifttype
          FBThrift::thrifttyperep
          FBThrift::thriftprotocol
          FBThrift::rpcmetadata
          FBThrift::thriftannotation
          FBThrift::thriftmetadata
          FBThrift::concurrency
          FBThrift::runtime
          FBThrift::thrift-core)

add_executable(
  mcrouter_network_tests
  "${CMAKE_SOURCE_DIR}/mcrouter/test/main.cpp"
  ClientSocket.cpp
  ListenSocket.cpp
  AccessPointTest.cpp
  # TODO: Fix certificate issue
  # AsyncMcClientTestSync.cpp
  CarbonMessageDispatcherTest.cpp
  CarbonMockMcTest.cpp
  CarbonQueueAppenderTest.cpp
  McAsciiParserTest.cpp
  McParserTest.cpp
  McServerAsciiParserTest.cpp
  MockMc.cpp
  SessionTest.cpp
  SessionTestHarness.cpp
  TestClientServerUtil.cpp
  TestMcAsciiParserUtil.cpp)

target_link_libraries(
  mcrouter_network_tests
  PRIVATE mcrouter_network
          mcrouter_network_tests_gen
          mcrouter_network_messages
          Folly::folly
          GTest::gtest
          FBThrift::thriftcpp2
          FBThrift::async
          FBThrift::serverdbginfo
          FBThrift::transport
          FBThrift::thriftanyrep
          FBThrift::thrifttype
          FBThrift::thrifttyperep
          FBThrift::thriftprotocol
          FBThrift::rpcmetadata
          FBThrift::thriftannotation
          FBThrift::thriftmetadata
          FBThrift::concurrency
          FBThrift::runtime
          FBThrift::thrift-core)

# Run these tests in the source tree so that they can easily load fixture files.
gtest_discover_tests(mcrouter_network_tests
                     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

add_subdirectory(gen)
