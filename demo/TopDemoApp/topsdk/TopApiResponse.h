//
//  TopApiResponse.h
//  TOPIOSSdk
//
//  api请求返回的结果
//
//  Created by cenwenchu on 12-7-13.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TopServiceError.h"

@interface TopApiResponse : NSObject

@property(copy,nonatomic) NSString *content;//返回的结果，如果失败没有该属性
@property(retain,nonatomic) TopServiceError *serviceError;//业务级别的错误码
@property(retain,nonatomic) NSError *error;//返回的错误信息，如果成功没有该属性(系统级别的错误)
@property(copy,nonatomic) NSDictionary *reqParams;//请求时候的入参，不包括附件类型的参数

@end
