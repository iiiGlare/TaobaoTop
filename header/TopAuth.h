//
//  TopAuth.h
//  TopIOSSdk
//   
//  授权对象，一个TopIOSclient内置一个授权对象，当调用auth接口成功后，授权信息都会保存到对象中，
//  用于服务调用。
//
//  Created by cenwenchu on 12-6-20.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TopAuth : NSObject

@property(copy,nonatomic) NSString *access_token;//Oauth授权token
@property(copy,nonatomic) NSString *refresh_token;//Oauth刷新token
@property(copy,nonatomic) NSString *mobile_token;//如果接入mtop需要，普通无线开发不需要
@property int token_expire_time;//token失效时间，对于Top的开发者应该关注下面四个失效时间，因为topapi分级为r1r2w1w2
@property int refresh_expire_time; //刷新token失效时间
@property int refresh_interval;//自动会根据四个失效时间换算出需要刷新的时长，取四个失效时间非0的最小值
@property double beg_time; //token创建时间，根据这个值和失效时长来计算当前是否失效

@property int token_expire_time_r1;//r1 api的时效长度，单位秒
@property int token_expire_time_r2;//r2 api的时效长度，单位秒
@property int token_expire_time_w1;//w1 api的时效长度，单位秒
@property int token_expire_time_w2;//w2 api的时效长度，单位秒

@property(copy,nonatomic) NSString *user_name;//登录用户nick
@property(copy,nonatomic) NSString *user_id;//登录用户id
@property(copy,nonatomic) NSString *sub_taobao_user_id;//子帐号id，如果是子帐号授权
@property(copy,nonatomic) NSString *sub_taobao_user_nick;//子帐号nick，如果是子帐号授权
@property(copy,nonatomic) NSString *usession_id;//用于用户会话跟踪

//通过授权返回的字符串初始化授权对象
-(id)initTopAuthFromString:(NSString*) authString;

//根据json对象初始化授权对象
-(id)initTopAuthFromJsonString:(NSString*) authJsonString;

//根据dict对象初始化授权对象
-(id)initTopAuthFromDictionary:(NSDictionary*) authDictionary;

//更新授权内容
-(void)refresh:(NSMutableDictionary *) params;

//将TopAuth对象序列化为字符串
-(NSString *)encodeTopAuthToString;

//转化为Json字符串
-(NSString *)encodeTopAuthToJsonString;

@end
