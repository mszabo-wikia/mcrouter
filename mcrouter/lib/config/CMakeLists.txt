# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_library(mcrouter_config ConfigPreprocessor.cpp RendezvousHash.cpp)

target_link_libraries(mcrouter_config PRIVATE mcrouter_fbi Folly::folly)

add_subdirectory(test)
