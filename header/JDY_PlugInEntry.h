//
//  JDY_PlugInEntry.h
//  TOPIOSSdk
//
//  Created by fangweng on 12-11-23.
//  Copyright (c) 2012年 tmall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TopAppEntity.h"

@protocol JDY_PlugInEntry <NSObject>

//无线卖家平台跳转到第三方应用时的协议，第三方开发者参看该协议来解析请求内容
//uid：当前用户id，TopAppEntity表示要跳转的应用基本信息，authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有），params附带一些扩展参数，暂时忽略
-(void)plugInEntry:(NSString *)uid appEntity:(TopAppEntity *)appEntity authString:(NSString *)authString params:(NSDictionary *)params;

@end
