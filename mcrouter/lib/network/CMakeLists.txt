# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/McAsciiParser-gen.cpp
  COMMAND ragel -G1 ${CMAKE_CURRENT_SOURCE_DIR}/McAsciiParser.rl -o
          ${CMAKE_CURRENT_BINARY_DIR}/McAsciiParser-gen.cpp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/McAsciiParser.rl
  VERBATIM)

add_library(
  mcrouter_network
  AccessPoint.cpp
  AsciiSerialized.cpp
  AsyncMcClientImpl.cpp
  AsyncTlsToPlaintextSocket.cpp
  CaretProtocol.cpp
  FailureDomains.cpp
  FizzContextProvider.cpp
  McClientRequestContext.cpp
  McSerializedRequest.cpp
  McSSLUtil.cpp
  Qos.cpp
  SecurityOptions.cpp
  ServerLoad.cpp
  SocketConnector.cpp
  SocketUtil.cpp
  ThreadLocalSSLContextProvider.cpp
  ThriftTransport.cpp
  WriteBuffer.cpp
  McAsciiParser-gen.cpp
  McAsciiParser.cpp
  McParser.cpp
  AsyncMcServer.cpp
  AsyncMcServerWorker.cpp
  ConnectionTracker.cpp
  CpuController.cpp
  McServerRequestContext.cpp
  McServerRequestContext.cpp
  McServerSession.cpp
  McServerThriftRequestContext.cpp
  MultiOpParent.cpp)

target_link_libraries(
  mcrouter_network
  PUBLIC Folly::folly
  PRIVATE mcrouter_clocks
          mcrouter_carbon_protocol
          mcrouter_memcache_thrift
          mcrouter_debug
          mcrouter_thread_pools
          mcrouter_compression_codecs
          mcrouter_utils
          fizz::fizz
          FBThrift::thriftcpp2)

add_subdirectory(gen)
add_subdirectory(test)
