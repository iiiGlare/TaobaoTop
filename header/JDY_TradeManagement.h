//
//  TradeManagement.h
//  TOPIOSSdk
//  交易模块插件必须实现的业务协议，作为应用跳转或者消息跳转的实现支持
//  Created by fangweng on 12-11-20.
//
//

#import <Foundation/Foundation.h>

//以下接口uid是系统必选传递参数
@protocol JDY_TradeManagement <NSObject>

//跳转到交易详情功能模块，tid是交易id（必选），chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
//authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有）
-(void) tradeDetail:(NSString *)uid tid:(NSString *)tid chatNick:(NSString *)chatNick authString:(NSString *)authString params:(NSDictionary *)params;


//跳转到交易列表（所有参数都可选），tradeStatus参看JDY_ProtocolConstants中的定义,buyerNick买家信息，startCreated交易创建时间的下限，endCreated交易创建时间上限
//authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有）
//chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
-(void) tradeList:(NSString *)uid tradeStatus:(NSString *)tradeStatus buyerNick:(NSString *)buyerNick startCreated:(double)startCreated endCreated:(double)endCreated chatNick:(NSString *)chatNick authString:(NSString *)authString params:(NSDictionary *)params;

//跳转到退款详情功能模块，refundid是退款id（必选），chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
//authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有）
//chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
-(void) refundDetail:(NSString *)uid refundId:(NSString *)refundId chatNick:(NSString *)chatNick authString:(NSString *)authString params:(NSDictionary *)params;


//跳转到退款列表（所有参数都可选），refundStatus参看JDY_ProtocolConstants中的定义,buyerNick买家信息
//authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有）
//chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
-(void) refundList:(NSString *)uid refundStatus:(NSString *)refundStatus buyerNick:(NSString *)buyerNick chatNick:(NSString *)chatNick authString:(NSString *)authString params:(NSDictionary *)params;

@end
