//
//  TopApiResponse.h
//  TOPIOSSdk
//
//  服务端的请求返回，如果是业务错误请获取serviceError,如果是系统错误获取error，如果是正常返回获取content
//  如果想要对请求的回复做业务对应处理，可以在请求时放置一个会话码到request，
//  然后获得这个response的时候从reqparams中再找出会话码对应是哪一次的回复。
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
