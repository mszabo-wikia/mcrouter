# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_fbthrift_cpp_library(mcrouter_common_thrift Common.thrift DEPENDS
                         mcrouter_carbon_thrift OPTIONS "${THRIFT_OPTIONS}")

add_fbthrift_cpp_library(mcrouter_memcache_thrift Memcache.thrift DEPENDS
                         mcrouter_common_thrift OPTIONS "${THRIFT_OPTIONS}")

add_fbthrift_cpp_library(
  memcache_service_thrift
  MemcacheService.thrift
  DEPENDS
  mcrouter_memcache_thrift
  FBThrift::async
  SERVICES
  Memcache
  OPTIONS
  "${THRIFT_OPTIONS}")

add_library(
  mcrouter_network_messages CommonMessages.cpp CommonMessagesThrift.cpp
                            MemcacheMessages.cpp MemcacheMessagesThrift.cpp)

target_link_libraries(
  mcrouter_network_messages
  PUBLIC mcrouter_common_thrift mcrouter_memcache_thrift
         mcrouter_carbon_protocol)
