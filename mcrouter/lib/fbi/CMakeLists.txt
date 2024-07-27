# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_library(mcrouter_fbi counting_sem.cpp WeightedFurcHash.cpp hash.c network.c)

target_link_libraries(
  mcrouter_fbi
  PUBLIC mcrouter_fbi_cpp
  PRIVATE Folly::folly)

add_subdirectory(cpp)
add_subdirectory(test)
