//
//  AppPlugin.h
//  TOPIOSSdk
//  官方应用可以插拔的模块定义
//  Created by fangweng on 12-11-21.
//
//

#import <Foundation/Foundation.h>

@interface TopPluginServiceType : NSObject

FOUNDATION_EXPORT NSString *const PLUGIN_ITEM;//商品模块
FOUNDATION_EXPORT NSString *const PLUGIN_TRADE;//交易模块
FOUNDATION_EXPORT NSString *const PLUGIN_STATISTICS;//数据模块
FOUNDATION_EXPORT NSString *const PLUGIN_OTHER;

@end
