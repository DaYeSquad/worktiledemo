//
//  base.h
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#ifndef HELLOWORKTILE_CORE_BASE_H_
#define HELLOWORKTILE_CORE_BASE_H_

#include <string>
#include <memory>

#include "options.h"

// DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&); \
void operator=(const TypeName&)

// namespace Worktile {}
#ifdef __cplusplus
#define NS_WTC_BEGIN                     namespace worktile {
#define NS_WTC_END                       }
#else
#define NS_WTC_BEGIN
#define NS_WTC_END
#endif

// delete
#define WTC_SAFE_DELETE(p) do { if(p) { delete (p); (p) = nullptr; } } while(0)

// 在 Androdi 的平台上添加一些兼容方法
#if WTC_PLATFORM == WTC_PLATFORM_ANDROID
#include "jni/string_utils_android.h"
#endif

#endif /* HELLOWORKTILE_CORE_BASE_H_ */
