//
//  WTCUser.h
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WTCUserStatus) { // 对应 user.h 中的 worktile::User::Status
  WTCUserStatusNormal  = 0,
  WTCUserStatusInvited = 1,
  WTCUserStatusPending = 2,
};

/**
 *  Objective-C 层的 User, 用于给外部的 iOS App 的 Objective-C/Swift 调用
 *
 *  注释1: 此部分代码我们遵循 Google Objective-C Code Style (https://google.github.io/styleguide/objcguide.xml)
 *
 *  注释2: C++ 的部分我们做了一个 Extension 放在 WTCUser_CoreAddition.h 中，这样可以起到隐藏非公开方法的作用，
 *        即对于 App 开发者而言，此部分的代码和正常的 Objective-C 代码并没有区别
 */
NS_ASSUME_NONNULL_BEGIN
@interface WTCUser : NSObject

@property(nonatomic, copy, readonly) NSString *uid;

@property(nonatomic, copy, readonly) NSString *username;

@property(nonatomic, copy) NSString *displayName;

@property(nonatomic, readonly) WTCUserStatus status;

- (NSString *)statusDescription;

- (instancetype)initWithJSON:(NSString *)json;

@end
NS_ASSUME_NONNULL_END
