# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_library(
  mcrouter_routes
  BigValueRoute.cpp
  CarbonLookasideRoute.cpp
  FailoverRateLimiter.cpp
  HashStopAllowListRoute.cpp
  KeyParseRoute.cpp
  LatencyInjectionRoute.cpp
  McBucketRoute.cpp
  McImportResolver.cpp
  McRouteHandleProvider.cpp
  McRouteHandleProvider-AllFastestRoute.cpp
  McRouteHandleProvider-CarbonLookasideRoute.cpp
  McRouteHandleProvider-FailoverRoute.cpp
  McRouteHandleProvider-HashRoute.cpp
  McRouteHandleProvider-PoolRoute.cpp
  NullRoute.cpp
  RateLimiter.cpp
  RendezvousRouteHelpers.cpp
  ShadowSettings.cpp
  ShardHashFunc.cpp
  ShardSelectionRouteFactory.cpp
  ShardSplitRoute.cpp
  ShardSplitter.cpp
  SlowWarmUpRouteSettings.cpp
  StagingRoute.cpp
  WarmUpRoute.cpp)

target_link_libraries(
  mcrouter_routes
  PRIVATE mcroutercore
          mcrouterinternal
          mcrouter_network_messages
          mcrouter_failover_errors_settings
          mcrouter_utils
          Folly::folly
          FBThrift::thriftcpp2)

add_subdirectory(test)
