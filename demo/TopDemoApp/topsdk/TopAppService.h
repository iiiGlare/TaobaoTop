//
//  AppService.h
//  TOPIOSSdk
//
//  Created by fangweng on 12-11-21.
//
//

#import <Foundation/Foundation.h>
#import "JDY_Protocol.h"
#import "TopAppConnector.h"
#import "TopAppEntity.h"

@interface TopAppService : NSObject<JDY_ItemManagement,JDY_TradeManagement,JDY_PlugInEntry,JDY_WangWangCommunication,JDY_MsgCenterManagement>

@property(nonatomic,retain) TopAppConnector * appConnector;

+(id)registerAppService:(NSString *)appKey appConnector:(TopAppConnector *) appConnector;

+(TopAppService *)getAppServicebyAppKey:(NSString *)appKey;

//调用sso接口，首先会判断用户授权存在且有效，如果是则返回，否则检查官方应用是否安装，未安装则直接走标准授权，已经安装，则向官方应用发起sso请求。
-(TopAuth *)sso:(NSString *)userId forceRefresh:(BOOL)forceRefresh eventCallback:(TopEventCallback *)eventCallback;

//从主客户端获取所有当前登录用户的id
-(NSArray *)getLoginUsers;

//主客户端为了能够收取主动推送，必须调用改接口向服务端汇报token
-(BOOL)sendPushTokenToPushServer:(NSString *)url userId:(NSString *)userId token:(NSString *)token;

//回到主应用的某一个模块,module参看AppModule的定义
-(void)backToSellserPlatform:(NSString *)module params:(NSMutableDictionary *)params;

//获取默认插件应用信息
-(TopAppEntity *)getPlugInDefaultApp:(NSString *)userId plugInType:(NSString *)plugInType;

//存储默认插件应用信息
-(void)storePlugInDefaultApp:(NSString *)userId plugInType:(NSString *)plugInType topAppEntity:(TopAppEntity *)topAppEntity;

//检查官方应用是否安装
-(BOOL)checkTBSellerPlatformInstalled;

@end
