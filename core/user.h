//
//  user.hpp
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#ifndef HELLOWORKTILE_CORE_USER_H_
#define HELLOWORKTILE_CORE_USER_H_

#include "base.h"

NS_WTC_BEGIN

/// Worktile 的用户对象，用于描述用户的信息
///
/// 注释1: 可以设计成构造函数中传所有的参数，也可以像下文中设计成 Init() 的样式，只需要所有设计统一就好，
///       为了应对有可能出现的比较复杂的初始化，我们统一设计成 Init() 的样式
///
/// 注释2: 我们传输 HTTP 请求的时候使用的是 JSON, 故所有的类都有 InitWithJsonOrDie() - 其中 OrDie 可以见
///       Google C++ Code Style (https://google.github.io/styleguide/cppguide.html#Function_Names)
///
/// 注释3: 我们要求所有的拷贝应当显式调用 Clone() 方法，所以我们对几乎所有的类都使用了 DISALLOW_COPY_AND_ASSIGN
///       (可见 Google C++ Code Style https://google.github.io/styleguide/cppguide.html#Declaration_Order)
///
/// 注释4: User::StatusDescription 就是我们跨平台明显共享逻辑的地方，Real-world project 中这种复杂逻辑的方法很多
class User {
public:
  
  enum class Status {
    NORMAL  = 0,
    INVITED = 1,
    PENDING = 2,
  };
  
  // Creation and lifetime --------------------------------------------------------
  
  User() {}
  virtual ~User() {}
  
  void Init(const std::string& uid, const std::string& username, const std::string& display_name, worktile::User::Status status);
  
  bool InitWithJsonOrDie(const std::string& json);
  
  std::unique_ptr<User> Clone() const;
  
  // Attributes --------------------------------------------------------
  
  std::string uid() const { return uid_; }
  std::string username() const { return username_; }
  
  std::string display_name() const { return display_name_; }
  void set_display_name(const std::string& display_name) { display_name_ = display_name; }
  
  worktile::User::Status status() const { return status_; }
  
  // Utils --------------------------------------------------------
  
  std::string StatusDescription() const;
  
private:
  std::string uid_;
  std::string username_;
  std::string display_name_;
  worktile::User::Status status_;
  
  
  DISALLOW_COPY_AND_ASSIGN(User);
};

NS_WTC_END

#endif /* HELLOWORKTILE_CORE_USER_H_ */
