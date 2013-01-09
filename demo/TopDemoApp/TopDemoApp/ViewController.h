//
//  ViewController.h
//  TopDemoApp
//
//  Created by fangweng on 12-12-26.
//  Copyright (c) 2012年 fangweng. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (retain, nonatomic) IBOutlet UITextField *requestInputText;
@property (retain, nonatomic) IBOutlet UIButton *authBtn;
@property (retain, nonatomic) IBOutlet UITextField *userIdText;
@property (retain, nonatomic) IBOutlet UIButton *uploadPicBtn;
@property (retain, nonatomic) IBOutlet UIButton *sendRequestBtn;
@property (retain, nonatomic) IBOutlet UITextView *responseView;
@property (retain, nonatomic) IBOutlet UIButton *tqlBtn;
- (IBAction)dismissInput:(id)sender;

@property (copy,nonatomic) NSMutableArray * userIds;

- (IBAction)authAction:(id)sender;
- (IBAction)tqlRequest:(id)sender;
- (IBAction)uploadPicAction:(id)sender;
- (IBAction)sendRequestAction:(id)sender;

@end
