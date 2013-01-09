//
//  Attachment.h
//  TopIOSSdk
//  如果要发起mutlipart请求，请用TopAttachment来封装二进制数据，将这个对象作为params的value放入，apicall的时候自动会发起mutlipart请求
//
//  Created by cenwenchu on 12-6-27.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TopAttachment : NSObject

@property(copy,nonatomic) NSString *name;
@property(copy,nonatomic) NSData *data;

@end
