//
//  TopTracker.h
//  TOPIOSSdk
//
//  用于纪录事件，异常，通知等信息，支持数据远端推送和本地文件存储
//
//  Created by fangweng on 12-11-28.
//  Copyright (c) 2012年 tmall.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TopIOSClient.h"

@interface TopTracker : NSObject


@property int maxBufferSize;//每一个Tracker都会先保存数据到内存，然后批量的flush到本地或者远端服务器，这个参数表明最大内存块是多少byte，到了就要flush，默认1k
@property int maxFlushInterval;//隔多少秒flush一次，默认1min一次
@property int maxFileSize;//本地文件保存多大就删除掉，默认设置10m

@property (strong,nonatomic) TopIOSClient *topIOSClient;
@property (copy,nonatomic) NSString *logServer;

//为每个appkey注册一个Tracker
+(id)registerTopTracker:(NSString *)appKey topclient:(TopIOSClient *) topclient
maxFlushInterval:(int) maxFlushInterval maxBufferSize:(int)maxBufferSize logServerUrl:(NSString *)logServerUrl;

//主要分成五部分（客户端和服务的交互直接通过服务端日志来纪录),policy:分成local和remote，前者就是本地文件存储,如果为nil,则默认是local

//最原始的track，可以自主传递类型，类型定义参看TopConstants
-(void)track:(int)trackType data:(NSString *)data isLocal:(BOOL)isLocal forceFlush:(BOOL)forceFlush;

//api调用的结果
-(void)trackAPICall:(NSString *)method network:(NSString *)network error:(NSString *)error timeConsume:(int)timeConsume data:(NSString *)data isLocal:(BOOL)isLocal forceFlush:(BOOL)forceFlush;

//应用间数据交互,如果是本地存储，isLocal设置为True
-(void)trackAPPCall:(NSString *)event appkey:(NSString *)appkey userId:(NSString*)userId fromModule:(NSString *)fromModule isSuccess:(BOOL)isSuccess
               data:(NSString *)data isLocal:(BOOL)isLocal forceFlush:(BOOL)forceFlush;

//异常，只纪录在本地，可以有机制选择性上传
-(void)trackError:(NSString *)action errorcode:(NSString *)errorcode msg:(NSString *)msg isLocal:(BOOL)isLocal forceFlush:(BOOL)forceFlush;

//notify,暂时考虑就做统计
-(void)trackNotify:(NSString *)notifyType userId:(NSString *)userId data:(NSString *)data isAlert:(BOOL)isAlert isLocal:(BOOL)isLocal forceFlush:(BOOL)forceFlush;

//单应用的用户行为纪录
-(void)trackOperation:(NSString *)module funcName:(NSString*)funcName userId:(NSString *)userId data:(NSString *)data isLocal:(BOOL)isLocal forceFlush:(BOOL)forceFlush;

//主动上传日志
-(void)uploadTrackLog;

-(void)stopTracker;

@end
