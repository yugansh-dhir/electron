// Copyright (c) 2020 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_COMMON_GIN_HELPER_MICROTASKS_SCOPE_H_
#define SHELL_COMMON_GIN_HELPER_MICROTASKS_SCOPE_H_

#include "shell/common/node_includes.h"
#include "v8/include/v8.h"

namespace gin_helper {

class MicrotasksScope {
 public:
  explicit MicrotasksScope(v8::Isolate* isolate);
  ~MicrotasksScope();

 private:
  std::unique_ptr<v8::MicrotasksScope> v8_microtasks_scope_;
  std::unique_ptr<node::InternalCallbackScope> callback_scope_;

  DISALLOW_COPY_AND_ASSIGN(MicrotasksScope);
};

}  // namespace gin_helper

#endif  // SHELL_COMMON_GIN_HELPER_MICROTASKS_SCOPE_H_
