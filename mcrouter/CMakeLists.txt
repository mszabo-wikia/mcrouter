# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/RouterRegistry.h"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/RouterRegistry-impl.h"
  COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${CMAKE_CURRENT_SOURCE_DIR}/RouterRegistry-impl.h"
    "${CMAKE_CURRENT_BINARY_DIR}/RouterRegistry.h"
  COMMENT "Creating RouterRegistry.h symlink")

add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/ThriftAcceptor.h"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/ThriftAcceptor-impl.h"
  COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${CMAKE_CURRENT_SOURCE_DIR}/ThriftAcceptor-impl.h"
    "${CMAKE_CURRENT_BINARY_DIR}/ThriftAcceptor.h"
  COMMENT "Creating ThriftAcceptor.h symlink")

add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/HostWithShard-fwd.h"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/HostWithShard-fwd-impl.h"
  COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${CMAKE_CURRENT_SOURCE_DIR}/HostWithShard-fwd-impl.h"
    "${CMAKE_CURRENT_BINARY_DIR}/HostWithShard-fwd.h"
  COMMENT "Creating HostWithShard-fwd.h symlink")

add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/mcrouter_sr_deps.h"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/mcrouter_sr_deps-impl.h"
  COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${CMAKE_CURRENT_SOURCE_DIR}/mcrouter_sr_deps-impl.h"
    "${CMAKE_CURRENT_BINARY_DIR}/mcrouter_sr_deps.h"
  COMMENT "Creating mcrouter_sr_deps.h symlink")

add_custom_command(
  OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/config-impl.h"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/mcrouter_config-impl.h"
  COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    "${CMAKE_CURRENT_SOURCE_DIR}/mcrouter_config-impl.h"
    "${CMAKE_CURRENT_BINARY_DIR}/config-impl.h"
  COMMENT "Creating config-impl.h symlink")

add_custom_target(
  mcrouter_symlink_headers
  DEPENDS RouterRegistry.h ThriftAcceptor.h HostWithShard-fwd.h
          mcrouter_sr_deps.h config-impl.h)

add_library(
  mcroutercore
  AsyncLog.cpp
  AsyncWriter.cpp
  CarbonRouterClient.cpp
  CarbonRouterClientBase.cpp
  CarbonRouterFactory.cpp
  CarbonRouterInstance.cpp
  CarbonRouterInstanceBase.cpp
  ConfigApi.cpp
  FileDataProvider.cpp
  FileObserver.cpp
  flavor.cpp
  LeaseTokenMap.cpp
  mcrouter_config.cpp
  McrouterFiberContext.cpp
  McrouterLogFailure.cpp
  McrouterLogger.cpp
  McrouterManager.cpp
  McSpoolUtils.cpp
  options.cpp
  OptionsUtil.cpp
  PoolFactory.cpp
  ProxyBase.cpp
  ProxyConfigBuilder.cpp
  ProxyDestination.cpp
  ProxyDestinationBase.cpp
  ProxyDestinationKey.cpp
  ProxyDestinationMap.cpp
  ProxyRequestContext.cpp
  ProxyStats.cpp
  route.cpp
  RoutingPrefix.cpp
  RuntimeVarsData.cpp
  ServiceInfo.cpp
  stats.cpp
  ThreadUtil.cpp
  ThriftAcceptor.cpp
  TkoLog.cpp
  TkoTracker.cpp
  ExternalStatsHandler.cpp)

add_dependencies(mcroutercore mcrouter_symlink_headers)

target_link_libraries(
  mcroutercore
  PUBLIC mcrouter_routes mcrouter_carbon_result_thrift mcrouter_carbon_thrift
         mcrouter_common_thrift mcrouter_memcache_thrift memcache_service_thrift
  PRIVATE mcrouter_invalidation FBThrift::thriftcpp2 Folly::folly atomic)

add_executable(mcrouter main.cpp RequestAclChecker.cpp StandaloneConfig.cpp
                        StandaloneUtils.cpp)

target_link_libraries(
  mcrouter
  mcroutercore
  mcrouterinternal
  Folly::folly
  FBThrift::thriftcpp2
  FBThrift::async
  mcrouter_carbon_result_thrift
  mcrouter_carbon_thrift
  mcrouter_common_thrift
  mcrouter_memcache_thrift
  memcache_service_thrift
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
  FBThrift::thrift-core
  fmt::fmt
  wangle::wangle
  pthread
  atomic)

add_subdirectory(lib)
add_subdirectory(routes)
add_subdirectory(tools)
add_subdirectory(test)
