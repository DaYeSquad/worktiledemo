//
//  user.cpp
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#include "user.h"

#include "json11/json11.hpp"

using std::string;
using std::unique_ptr;

NS_WTC_BEGIN

////////////////////////////////////////////////////////////////////////////////
// User, public:

// Creation and lifetime --------------------------------------------------------

void User::Init(const std::string &uid, const std::string &username, const std::string &display_name, worktile::User::Status status) {
  uid_ = uid;
  username_ = username;
  display_name_ = display_name;
  status_ = status;
}

bool User::InitWithJsonOrDie(const std::string& json) {
  /* worktile 示例中的 json (https://open.worktile.com/wiki/user_info.html#/user)
   {
   "uid":"679efdf3960d45a0b8679693098135ff",
   "name":"gonglinjie",
   "display_name":"龚林杰",
   "email":"gonglinjie@worktile.com",
   "desc":"",
   "avatar":"https://api.worktile.com/avatar/80/ae2805fc-9aca-4f3b-8ac4-320c5d664db7.png",
   "status":3,
   "online":0
   }
   */
  string error;
  json11::Json json_obj = json11::Json::parse(json, error);
  
  if (!error.empty()) {
    return false;
  }
  
  uid_ = json_obj["uid"].string_value();
  username_ = json_obj["name"].string_value();
  display_name_ = json_obj["display_name"].string_value();
  status_ = static_cast<User::Status>(json_obj["status"].int_value());
  
  return true;
}

std::unique_ptr<User> User::Clone() const {
  unique_ptr<User> user(new User());
  user->Init(uid_, username_, display_name_, status_);
  return user;
}

// Utils --------------------------------------------------------

std::string User::StatusDescription() const {
  return display_name_ + " is " + std::to_string(static_cast<int>(status_));
}

NS_WTC_END
