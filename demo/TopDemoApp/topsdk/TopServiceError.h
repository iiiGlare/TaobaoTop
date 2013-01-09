//
//  TopServiceError.h
//  TOPIOSSdk
//
//  Created by fangweng on 12-12-6.
//  Copyright (c) 2012年 tmall.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TopServiceError : NSObject

@property (copy,nonatomic) NSString * errorCode;
@property (copy,nonatomic) NSString * errorMsg;
@property (copy,nonatomic) NSString * subErrorCode;
@property (copy,nonatomic) NSString * subErrorMsg;

@end
