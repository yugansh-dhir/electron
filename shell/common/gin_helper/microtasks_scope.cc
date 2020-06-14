// Copyright (c) 2020 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "shell/common/gin_helper/microtasks_scope.h"

#include "shell/browser/electron_browser_main_parts.h"
#include "shell/browser/javascript_environment.h"
#include "shell/common/gin_helper/locker.h"

namespace gin_helper {

MicrotasksScope::MicrotasksScope(v8::Isolate* isolate) {
  if (Locker::IsBrowserProcess()) {
    auto* node_env = electron::ElectronBrowserMainParts::Get()->node_env();
    callback_scope_.reset(new node::InternalCallbackScope(
        node_env->env(), v8::Local<v8::Object>(), {0, 0},
        node::InternalCallbackScope::kAllowEmptyResource));
  } else {
    v8_microtasks_scope_ = std::make_unique<v8::MicrotasksScope>(
        isolate, v8::MicrotasksScope::kRunMicrotasks);
  }
}

MicrotasksScope::~MicrotasksScope() = default;

}  // namespace gin_helper