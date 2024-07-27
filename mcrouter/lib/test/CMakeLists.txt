# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

if(NOT BUILD_TESTS)
  return()
endif()

add_executable(
  mcrouter_lib_tests
  "${CMAKE_SOURCE_DIR}/mcrouter/test/main.cpp"
  FiberLocalTest.cpp
  HashTestUtil.cpp
  Ch3HashTest.cpp
  CompressionCodecManagerTest.cpp
  CompressionTest.cpp
  CompressionTestUtil.cpp
  Crc32HashTest.cpp
  DynamicUtilTest.cpp
  IovecCursorTest.cpp
  Lz4ImmutableTest.cpp
  McResUtilTest.cpp
  MigrateRouteTest.cpp
  RandomRouteTest.cpp
  RendezvousHashTest.cpp
  RouteHandleTest.cpp
  WeightedCh3HashFuncTest.cpp
  WeightedCh4HashFuncTest.cpp
  WeightedChHashFuncBaseTest.cpp
  WeightedRendezvousHashTest.cpp)

target_link_libraries(
  mcrouter_lib_tests
  PRIVATE mcrouter_compression_codecs
          mcrouter_hash_functions
          mcrouter_fiber_local
          mcrouter_utils
          mcrouter_memcache_thrift
          mcroutercore
          GTest::gtest
          Folly::folly
          Folly::follybenchmark
          FBThrift::thriftcpp2)

add_executable(mcrouter_weighted_hash_benchmark WeightedHashBenchmark.cpp)

target_link_libraries(
  mcrouter_weighted_hash_benchmark PRIVATE mcrouter_hash_functions Folly::folly
                                           Folly::follybenchmark)

gtest_discover_tests(mcrouter_lib_tests)
