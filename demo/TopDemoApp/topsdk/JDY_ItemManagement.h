//
//  ItemManagement.h
//  TOPIOSSdk
//  商品模块插件必须实现的业务协议，作为应用跳转或者消息跳转的实现支持
//
//  Created by fangweng on 12-11-20.
//
//

#import <Foundation/Foundation.h>

//以下接口uid是系统必选传递参数
@protocol JDY_ItemManagement <NSObject>

//跳转到商品详情功能模块，iid是商品id（必选）chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
//authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有）
-(void) itemDetail:(NSString *)uid iid:(NSString *)iid chatNick:(NSString *)chatNick authString:(NSString *)authString params:(NSDictionary *)params;


//跳转到商品列表，ItemStatus参看JDY_ProtocolConstants中的定义（可选）
//authString在第一次从无线卖家平台跳转的时候带有的授权信息（如果用户和应用授权有效的情况下会带有）
//chatNick（可选）如果从旺旺聊天窗口跳转，则会带上聊天对象的nick
-(void) itemList:(NSString *)uid itemStatus:(NSString *)itemStatus chatNick:(NSString *)chatNick authString:(NSString *)authString params:(NSDictionary *)params;

@end
