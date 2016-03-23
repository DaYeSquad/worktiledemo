//
//  WTCUser_CoreAddition.h
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#import "WTCUser.h"

#include "user.h"

@interface WTCUser () {
 @private
  std::unique_ptr<worktile::User> _coreHandler;
}

+ (instancetype)userWithCoreUser:(const worktile::User&)coreUser;

@end
