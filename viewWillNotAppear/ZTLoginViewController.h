//
//  ZTLoginViewController.h
//  viewWillNotAppear
//
//  Created by Billy Gray on 11/28/11.
//  Copyright (c) 2011 Zetetic LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ZTLoginViewController;

@protocol ZTLoginViewControllerDelegate <NSObject>
@required
- (void)loginViewControllerGrantedAccess:(ZTLoginViewController *)controller;
@end

@interface ZTLoginViewController : UIViewController

@property (nonatomic,strong) IBOutlet UIButton *button;
@property (nonatomic,assign) id<ZTLoginViewControllerDelegate> delegate;

- (IBAction)login:(id)sender;

@end
