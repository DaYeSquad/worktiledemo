//
//  ViewController.m
//  HelloWorktile
//
//  Created by Frank Lin on 3/23/16.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#import "ViewController.h"

#import "WTCUser.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  NSString *exampleJSON = @"{\
  \"uid\":\"679efdf3960d45a0b8679693098135ff\",\
  \"name\":\"gonglinjie\",\
  \"display_name\":\"龚林杰\",\
  \"email\":\"gonglinjie@worktile.com\",\
  \"desc\":\"\",\
  \"avatar\":\"https://api.worktile.com/avatar/80/ae2805fc-9aca-4f3b-8ac4-320c5d664db7.png\",\
  \"status\":3,\
  \"online\":0\
  }";

  WTCUser* user = [[WTCUser alloc] initWithJSON:exampleJSON];
  self.outputLabel.text = [user statusDescription];
}

@end
