//
//  ZTAppDelegate.h
//  viewWillNotAppear
//
//  Created by Billy Gray on 11/28/11.
//  Copyright (c) 2011 Zetetic LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZTLoginViewController.h"

@interface ZTAppDelegate : UIResponder 
<UIApplicationDelegate, UITabBarControllerDelegate, ZTLoginViewControllerDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) UITabBarController *tabBarController;

@property (strong, nonatomic) ZTLoginViewController *loginViewController;

@end
