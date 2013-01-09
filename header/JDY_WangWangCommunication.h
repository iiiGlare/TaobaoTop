//
//  WangWangCommunication.h
//  TOPIOSSdk
//  旺旺模块插件必须实现的业务协议，作为应用跳转或者消息跳转的实现支持
//  Created by fangweng on 12-11-20.
//
//

#import <Foundation/Foundation.h>

@protocol JDY_WangWangCommunication <NSObject>

//旺旺聊天接口，chatNick必选（聊天对象chatNick），iid和tid可选，分别是商品id和交易id，text是聊天模版，带到聊天中
-(void) chat:(NSString *)uid chatNick:(NSString *)chatNick iid:(NSString *)iid tid:(NSString *)tid text:(NSString *)text params:(NSDictionary *)params;

@end
