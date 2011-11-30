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

@property (retain, nonatomic) UIWindow *window;

@property (retain, nonatomic) UITabBarController *tabBarController;

@property (retain, nonatomic) ZTLoginViewController *loginViewController;

@property (nonatomic) BOOL isLoginViewShowing;

@end
