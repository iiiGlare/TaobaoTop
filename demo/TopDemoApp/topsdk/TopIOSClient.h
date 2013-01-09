//
//  TopIOSClient.h
//  sdk
//
//  IOS客户端，全局一个appkey使用一个，只需要注册就可以创建全局单例。
//
//
//  Created by cenwenchu on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TopIOSSdk.h"
#import "TopIOSSdkExt.h"
#import "TopAuth.h"
#import "TopEventCallback.h"

@interface TopIOSClient : NSObject <TopIOSSdk,TopIOSSdkExt>

@property(copy,atomic) NSString *appKey;
@property(copy,atomic) NSString *appSecret;
@property(copy,atomic) NSString *callbackUrl;

//以下是内置的一些服务地址，如果用淘宝开放平台正式环境，则不需要配置，如果是沙箱等其他环境，可以修改这些地址
@property(copy,atomic) NSString *authEntryUrl;
@property(copy,atomic) NSString *apiEntryUrl;
@property(copy,atomic) NSString *authRefreshEntryUrl;
@property(copy,atomic) NSString *tqlEntryUrl;
@property(copy,atomic) NSString *scheduleEntryUrl;
@property(copy,atomic) NSString *logServerUrl;

@property(copy,nonatomic)NSString *sysName;
@property(copy,nonatomic)NSString *sysVersion;
@property(copy,nonatomic)NSString *deviceUUID;
@property(copy,nonatomic)NSString *sdkVersion;
@property(copy,nonatomic)NSString *deviceName;

//是否需要自动刷新已经授权过的会话，如果授权用户较多不建议使用自动（> 10个）
@property BOOL needAutoRefreshToken;


//注册不同的appkey的ios客户端,需要提供appkey，appsecretcode，回调地址（保持和appkey注册的时候填入的回调地址一级域名一致），是否需要自动刷新access_token（在freshtoken有效期内）
+(id)registerIOSClient:(NSString *)appKey appSecret:(NSString *)appSecret callbackUrl:(NSString *)callbackUrl needAutoRefreshToken:(BOOL)needAutoRefreshToken;

//注册不同的appkey的ios客户端(带有日志跟踪和统计功能),需要提供appkey，appsecretcode，回调地址（保持和appkey注册的时候填入的回调地址一级域名一致），是否需要自动刷新access_token（在freshtoken有效期内）
+(id)registerIOSClientWithTracker:(NSString *)appKey appSecret:(NSString *)appSecret
                      callbackUrl:(NSString *)callbackUrl needAutoRefreshToken:(BOOL)needAutoRefreshToken isLocalTrack:(BOOL)isLocalTrack
                      maxFlushInterval:(int) maxFlushInterval maxBufferSize:(int)maxBufferSize logServerUrl:(NSString *)logServerUrl;

//根据appkey获得客户端，如果没有注册将得到nil
+(TopIOSClient *)getIOSClientByAppKey:(NSString *)appKey;

//通过接口获得内部某一个user_id的授权
-(TopAuth *)getAuthByUserId:(NSString *)user_id;
//通过接口存储内部某一个user_id的授权
-(void)setAuthByUserId:(NSString *)user_id auth:(TopAuth *)auth;
-(void)removeAuthByUserId:(NSString *)user_id;

//获得当前所有授权用户的授权信息
-(NSArray *)getAllAuths;

//将所有内存中的授权持久化到userdefaults中,默认自动会持久化，不需要调用
-(void)storeAuthPools;
//将持久化的userdefaults中的授权载入内存，client启动的时候会被调用一次
-(void)loadAuthPools;

//oauth从浏览器回调应用时用于解析结果的方法
-(void)authCallback:(NSString *)url;

//如果是通过registerIOSClientWithTracker创建，则可以获得内部的tracker
-(id)innerTracker;

//注册地层的错误监控，可以统一调用上层错误处理逻辑
-(void)registerServiceErrorCodeCallbackEvent:(NSString *)serviceErrorCode eventCallback:(TopEventCallback *) eventCallback;

//注册地层的错误监控，可以统一调用上层错误处理逻辑
-(void)registerErrorCodeCallbackEvent:(NSNumber *)error eventCallback:(TopEventCallback *) eventCallback;

@end
