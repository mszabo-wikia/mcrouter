# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_library(mcrouter_fbi_cpp LogFailure.cpp globals.cpp LowerBoundPrefixMap.cpp
                             ParsingUtil.cpp util.cpp)

target_link_libraries(mcrouter_fbi_cpp PRIVATE Folly::folly)

add_subdirectory(test)
