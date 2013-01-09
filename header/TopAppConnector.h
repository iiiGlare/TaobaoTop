//
//  AppConnector.h
//  TOPIOSSdk
//
//  应用交互连接通信底层实体
//  Created by cenwenchu on 12-11-16.
//
//

#import <Foundation/Foundation.h>
#import "TopIOSClient.h"
#import "TopEventCallback.h"

@interface TopAppConnector : NSObject

+(id)registerAppConnector:(NSString *)appKey topclient:(TopIOSClient *) topclient;
+(TopAppConnector *)getAppConnectorbyAppKey:(NSString *)appKey;
//注册事件处理对象及方法，为另一方应用请求到本地应用时做处理对象分配（根据event来分配事件处理target和方法）,这是类级别，下面有一个对象级别
+(void)registerGlobalEvent:(NSString *)event eventProcessor:(TopEventCallback *)eventProcessor;

@property(nonatomic,retain) TopIOSClient * topclient;
@property(copy,atomic) NSMutableDictionary *appInfoPool;//缓存app信息，key：appkey，value：AppEntity
@property(copy,atomic) NSMutableDictionary *userPlugInPool;//缓存插件信息,key:userId value:Dictionary{key:参看Constants里面的plug常量，value:AppKey}。

//发送请求到另一个应用，通过app的native callback模式，模拟阻塞模式，同步等待返回（30秒钟超时）,需要传递对方应用的appkey，
//事件定义（对方需要能够识别），业务参数。
-(NSString *)sendRequestToApp:(NSString *)appkey event:(NSString *)event params:(NSMutableDictionary *)params;

//异步发送请求到另一个应用，设置callback对象和方法，等有结果会异步返回(如果设置eventcallback 为空，则表示不需要回调)。
-(void)sendRequestToAppWithAsynMode:(NSString *)appkey event:(NSString *)event params:(NSMutableDictionary *)params eventCallback:(TopEventCallback *)eventCallback;

//发送响应回给另一个应用，需要传入请求的会话序列号，对方应用的callback，实际返回结构内容.
-(void)sendResponseToApp:(NSString *)appSequence callbackUrl:(NSString*)callbackUrl response:(NSString *)response;

//应用接收外部传递来的应用消息
-(void)receiveMessageFromApp:(NSString *)url;

//注册事件处理对象及方法，为另一方应用请求到本地应用时做处理对象分配（根据event来分配事件处理target和方法）
-(void)registerEvent:(NSString *)event eventProcessor:(TopEventCallback *)eventProcessor;


@end
