//
//  AppEvent.h
//  TOPIOSSdk
//  应用交互的事件定义
//  Created by fangweng on 12-11-21.
//
//

#import <Foundation/Foundation.h>

@interface TopAppEvent : NSObject

FOUNDATION_EXPORT NSString *const EVENT_SSO;//sso 消息
FOUNDATION_EXPORT NSString *const EVENT_GETLOGINUSERS;//获取卖家平台登陆成功后的用户列表
FOUNDATION_EXPORT NSString *const EVENT_BACK_PLATFORM;//回到卖家平台
FOUNDATION_EXPORT NSString *const EVENT_GO_PLUGIN;//从一个应用到另一个应用
FOUNDATION_EXPORT NSString *const EVENT_ITEM_DETAIL;//商品detail的事件
FOUNDATION_EXPORT NSString *const EVENT_ITEM_LIST;//商品列表事件
FOUNDATION_EXPORT NSString *const EVENT_TRADE_DETAIL;//交易detail事件
FOUNDATION_EXPORT NSString *const EVENT_TRADE_LIST;//交易列表事件
FOUNDATION_EXPORT NSString *const EVENT_REFUND_DETAIL;//退款detail事件
FOUNDATION_EXPORT NSString *const EVENT_REFUND_LIST;//退款列表事件
FOUNDATION_EXPORT NSString *const EVENT_WANGWANG_CHAT;//进入旺旺聊天模块
FOUNDATION_EXPORT NSString *const EVENT_MC_DETAIL;//进入消息中心详细功能
FOUNDATION_EXPORT NSString *const EVENT_MC_LIST;//进入消息中心列表

@end
