//
//  MsgCenterManagement.h
//  TOPIOSSdk
//
//  消息中心接口定义
//  Created by fangweng on 12-11-21.
//
//

#import <Foundation/Foundation.h>

//以下接口uid是系统必选传递参数
@protocol JDY_MsgCenterManagement <NSObject>

//跳转到消息中心详情功能模块，messageType是消息大类型（必选），id（可选）如果有是具体大类型的某一个业务主id（比如商品消息，那么就是商品id，交易就是交易id），
-(void) messageDetail:(NSString *)uid messageType:(NSString *)messageType id:(NSString *)id params:(NSDictionary *)params;


//跳转到消息中心列表，messageType是消息大类型（必选）
-(void) messageList:(NSString *)uid messageType:(NSString *)messageType params:(NSDictionary *)params;


@end
