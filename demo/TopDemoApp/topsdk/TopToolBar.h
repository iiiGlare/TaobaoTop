//
//  ToolBar.h
//  TopTooBar
//
//  Created by lihao on 12-11-28.
//  Copyright (c) 2012年 lihao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TopBridgeWebview.h"

@protocol TopToolBarProtocol <NSObject>

-(void) willGotoPlatform;

-(void) willGotoPlugin;

@end

@interface TopToolBar : NSObject

@property(retain,nonatomic) id<TopToolBarProtocol> delegate;


+(TopToolBar*) bindBaseView:(UIView*) baseView
                    withApp:(NSString*) app
                 tmallStyle:(bool) tmalluser;

+(TopToolBar*) bindBaseView:(UIView*) baseView
                    withApp:(NSString*) app
                 tmallStyle:(bool) tmalluser
                unreadCountFromUser:(NSString*) user;


- (CGFloat)height;
- (void)setHeight:(CGFloat)height;
- (CGFloat)top ;
- (void)setTop:(CGFloat)y ;
- (CGFloat)left;
- (void)setLeft:(CGFloat)left;


- (void)bringToFront;
- (void)unbind;


@end



