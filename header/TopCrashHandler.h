//
//  TopCrashHandler.h
//  TOPIOSSdk
//
//  crash监控处理
//
//  Created by fangweng on 12-12-18.
//  Copyright (c) 2012年 tmall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TopTracker.h"

@interface TopCrashHandler : NSObject

+(void) monitor:(TopTracker *) topTracker;

@end
