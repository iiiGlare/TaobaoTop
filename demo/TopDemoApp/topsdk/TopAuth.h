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

@property(copy,nonatomic) NSString *access_token;
@property(copy,nonatomic) NSString *refresh_token;
@property(copy,nonatomic) NSString *mobile_token;
@property int token_expire_time;
@property int refresh_expire_time; 
@property int refresh_interval;
@property double beg_time; 

@property int token_expire_time_r1;
@property int token_expire_time_r2;
@property int token_expire_time_w1;
@property int token_expire_time_w2;

@property(copy,nonatomic) NSString *user_name;//登录用户nick
@property(copy,nonatomic) NSString *user_id;//登录用户id
@property(copy,nonatomic) NSString *sub_taobao_user_id;//子帐号id，如果是子帐号授权
@property(copy,nonatomic) NSString *sub_taobao_user_nick;//子帐号nick，如果是子帐号授权
@property(copy,nonatomic) NSString *usession_id;//用于用户会话跟踪

//通过授权返回的字符串初始化授权对象
-(id)initTopAuthFromString:(NSString*) authString;

-(id)initTopAuthFromJsonString:(NSString*) authJsonString;

-(id)initTopAuthFromDictionary:(NSDictionary*) authDictionary;

//更新授权内容
-(void)refresh:(NSMutableDictionary *) params;

//将TopAuth对象序列化为字符串
-(NSString *)encodeTopAuthToString;

//转化为Json字符串
-(NSString *)encodeTopAuthToJsonString;

@end
