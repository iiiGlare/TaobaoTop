//
//  TopSimpleCache.h
//  TOPIOSSdk
//
//  用于数据缓存，支持有时效性的数据缓存和定时后台刷新功能
//
//  Created by fangweng on 12-12-7.
//  Copyright (c) 2012年 tmall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TopEventCallback.h"

@interface TopSimpleCache : NSObject

//存储一个数据，validTime表示数据有效时间（从store开始的秒数，0表示永久有效，比如10，就代表存入开始后10秒内有效，过了10秒则无法取道数据）
-(BOOL)store:(NSString *)key value:(id)value validTime:(int)validTime;

//获取数据
-(id)take:(NSString *)key;

@end
