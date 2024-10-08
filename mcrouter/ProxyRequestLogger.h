/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include "mcrouter/McrouterFiberContext.h"
#include "mcrouter/config.h"
#include "mcrouter/lib/carbon/Result.h"
#include "mcrouter/lib/carbon/RoutingGroups.h"

namespace facebook {
namespace memcache {
namespace mcrouter {

template <class RouterInfo>
class Proxy;
struct RequestLoggerContext;

template <class RouterInfo>
class ProxyRequestLogger {
 public:
  explicit ProxyRequestLogger(Proxy<RouterInfo>& proxy)
      : proxy_(proxy), loggerCreatedTimeUs_(nowUs()) {}

  template <class Request>
  void log(const RequestLoggerContext& loggerContext);

 protected:
  Proxy<RouterInfo>& proxy_;

  void logError(carbon::Result result, RequestClass reqClass);

 private:
  template <class Request>
  void logDurationByRequestType(
      uint64_t durationUs,
      carbon::GetLikeT<Request> = 0);
  template <class Request>
  void logDurationByRequestType(
      uint64_t durationUs,
      carbon::UpdateLikeT<Request> = 0);
  template <class Request>
  void logDurationByRequestType(
      uint64_t durationUs,
      carbon::OtherThanT<Request, carbon::GetLike<>, carbon::UpdateLike<>> = 0);

  int64_t loggerCreatedTimeUs_ = 0;
};
} // namespace mcrouter
} // namespace memcache
} // namespace facebook

#include "ProxyRequestLogger-inl.h"
