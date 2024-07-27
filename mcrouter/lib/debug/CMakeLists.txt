# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the LICENSE file
# in the root directory of this source tree.

add_library(mcrouter_debug ConnectionFifo.cpp ConnectionFifoProtocol.cpp
                           FifoManager.cpp Fifo.cpp)

target_link_libraries(mcrouter_debug PRIVATE mcrouter_fbi Folly::folly)
