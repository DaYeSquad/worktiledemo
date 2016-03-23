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

#endif /* HELLOWORKTILE_CORE_BASE_H_ */
