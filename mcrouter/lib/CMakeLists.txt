# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_library(mcrouter_clocks Clocks.cpp)

add_library(
  mcrouter_hash_functions
  RendezvousHashFunc.cpp RendezvousHashHelper.cpp WeightedCh3HashFunc.cpp
  WeightedCh4HashFunc.cpp WeightedChHashFuncBase.cpp
  WeightedRendezvousHashFunc.cpp)

target_link_libraries(mcrouter_hash_functions PRIVATE mcrouter_fbi Folly::folly)

add_library(mcrouter_utils DynamicUtil.cpp IOBufUtil.cpp)

target_link_libraries(mcrouter_utils PRIVATE Folly::folly FBThrift::thriftcpp2)

add_library(
  mcrouter_compression_codecs
  Compression.cpp
  CompressionCodecManager.cpp
  IovecCursor.cpp
  Lz4CompressionCodec.cpp
  Lz4Immutable.cpp
  Lz4ImmutableCompressionCodec.cpp
  ZstdCompressionCodec.cpp)

target_link_libraries(mcrouter_compression_codecs PRIVATE mcrouter_utils
                                                          Folly::folly)

add_library(mcrouter_thread_pools AuxiliaryCPUThreadPool.cpp
                                  AuxiliaryIOThreadPool.cpp)

target_link_libraries(mcrouter_thread_pools PRIVATE Folly::folly)

add_library(mcrouter_fiber_local FiberLocalInternal.cpp)

target_link_libraries(mcrouter_fiber_local PRIVATE Folly::folly)

add_library(mcrouter_failover_errors_settings FailoverErrorsSettingsBase.cpp)

target_link_libraries(
  mcrouter_failover_errors_settings
  PRIVATE mcrouter_fbi mcrouter_mc_protocol mcrouter_network_messages
          Folly::folly FBThrift::thriftcpp2)

add_library(mcrouterinternal MessageQueue.cpp StatsReply.cpp)

target_link_libraries(
  mcrouterinternal
  PUBLIC mcrouter_fbi
         mcrouter_config
         mcrouter_debug
         mcrouter_network_messages
         mcrouter_hash_functions
         mcrouter_compression_codecs
         mcrouter_thread_pools
         mcrouter_carbon_protocol
         mcrouter_mc_protocol
         mcrouter_network
         mcrouter_failover_errors_settings
         mcrouter_carbon_result_thrift
         mcrouter_carbon_thrift
         mcrouter_common_thrift
         mcrouter_memcache_thrift
         memcache_service_thrift)

add_subdirectory(carbon)
add_subdirectory(config)
add_subdirectory(debug)
add_subdirectory(fbi)
add_subdirectory(mc)
add_subdirectory(network)
add_subdirectory(invalidation)
add_subdirectory(test)
