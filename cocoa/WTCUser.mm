//
//  WTCUser.m
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//
#if !defined(__has_feature) || !__has_feature(objc_arc)
#error "This file requires ARC support."
#endif

#import "WTCUser.h"
#import "WTCUser_CoreAddition.h"

@implementation WTCUser

#pragma mark - Lifecyle

- (instancetype)init {
  if (self = [super init]) {
    _coreHandler = std::unique_ptr<worktile::User>(new worktile::User());
  }
  return self;
}

#pragma mark - Property

- (NSString *)uid {
  return [NSString stringWithUTF8String:_coreHandler->uid().c_str()];
}

- (NSString *)username {
  return [NSString stringWithUTF8String:_coreHandler->username().c_str()];
}

- (NSString *)displayName {
  return [NSString stringWithUTF8String:_coreHandler->display_name().c_str()];
}

- (void)setDisplayName:(NSString *)displayName {
  _coreHandler->set_display_name([displayName UTF8String]);
}

- (WTCUserStatus)status {
  return (WTCUserStatus)_coreHandler->status();
}

- (instancetype)initWithJSON:(NSString *)json {
  if (self = [self init]) {
    _coreHandler->InitWithJsonOrDie([json UTF8String]);
  }
  return self;
}

#pragma mark - Utils

- (NSString *)statusDescription {
  return [NSString stringWithUTF8String:_coreHandler->StatusDescription().c_str()];
}

#pragma mark - Core Addition

+ (instancetype)userWithCoreUser:(const worktile::User&)coreUser {
  WTCUser *user = [[WTCUser alloc] init];
  user->_coreHandler = coreUser.Clone();
  return user;
}

@end
