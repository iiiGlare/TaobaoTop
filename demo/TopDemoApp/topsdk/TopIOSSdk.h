//
//  TopIOSSdk.h
//  sdk
//
//  IOS的最基本两个操作接口：授权和发起服务请求。
//
//  Created by cenwenchu on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TopApiResponse.h"


@protocol TopIOSSdk <NSObject>

//可以对api调用结果做解析，如果是一个NSDictionary，则表明是正确的对象结果，如果是TopServiceError，则是返回的业务出错信息
+(id)getResponseObject:(NSString *)resp;

//授权接口，直接封装了授权的页面和授权返回解析保存,当前暂时支持成功授权返回TopAuth对象，失败场景后续支持
-(void)auth:(id)target cb:(SEL)cb;

//刷新授权access_token，指定刷新某一个用户的授权会话
-(void)refreshTokenByUserId:(NSString *)userId;

//调用api入口(异步):  method请求的方法(GET,POST);params具体的业务和系统参数(可以不传，内部会有默认设置，如果要修改比如返回格式，可以设置);target和cb用于请求后传递结果回调（NSString或者NSError两种返回）
//userid如果传入，则可以根据授权状况自动选择不同的用户授权来请求服务，具体业务参看：http://open.taobao.com/doc/category_list.htm?id=102 
//needMainThreadCallBack表明是否回调的时候采用主线程的方式回调（如果为true就采用主线程，主线程回调的作用是当回调函数需要操作ui界面的时候，必须是主线程，如果只是后台保存数据，这个值可以是false）
//返回的参数可以用于取消改次请求的返回，参看TopIOSSdk中的取消接口cancel,入参就是这个api的出参
-(NSString *)api:(NSString *)method params:(NSDictionary *)params target:(id)target cb:(SEL)cb userId:(NSString *)userId  needMainThreadCallBack:(Boolean) needMainThreadCallBack;

//调用tql的入口（异步），method请求的方法(GET,POST);params具体的业务和系统参数;target和cb用于请求后传递结果回调（NSString或者NSError两种返回）
//userid如果传入，则可以根据授权状况自动选择不同的用户授权来请求服务，具体使用参看 http://open.taobao.com/doc/category_list.htm?id=143
//needMainThreadCallBack表明是否回调的时候采用主线程的方式回调（如果为true就采用主线程，主线程回调的作用是当回调函数需要操作ui界面的时候，必须是主线程，如果只是后台保存数据，这个值可以是false）
//返回的参数可以用于取消改次请求的返回，参看TopIOSSdk中的取消接口cancel,入参就是这个api的出参
-(NSString *)tql:(NSString *)method params:(NSDictionary *)params target:(id)target cb:(SEL)cb userId:(NSString *)userId needMainThreadCallBack:(Boolean) needMainThreadCallBack;

//调用api入口(同步):  method请求的方法(GET,POST);params具体的业务和系统参数(可以不传，内部会有默认设置，如果要修改比如返回格式，可以设置);
//userid如果传入，则可以根据授权状况自动选择不同的用户授权来请求服务，具体业务参看：http://open.taobao.com/doc/category_list.htm?id=102 
//返回结果是NSString或者NSError
-(TopApiResponse *)api:(NSString *)method params:(NSDictionary *)params userId:(NSString *)userId;

//调用tql的入口（同步），method请求的方法(GET,POST);params具体的业务和系统参数;
//userid如果传入，则可以根据授权状况自动选择不同的用户授权来请求服务，具体使用参看 http://open.taobao.com/doc/category_list.htm?id=143
//返回结果是NSString或者NSError
-(TopApiResponse *)tql:(NSString *)method params:(NSDictionary *)params userId:(NSString *)userId;

//调用schedule的入口（同步,schedule本来就是异步执行，因此就只提供同步接口），method请求的方法(GET,POST);params具体的业务和系统参数;
//userid如果传入，则可以根据授权状况自动选择不同的用户授权来请求服务，具体使用参看 http://open.taobao.com/doc/category_list.htm?id=143
//返回结果是NSString或者NSError
-(TopApiResponse *)schedule:(NSString *)method params:(NSDictionary *)params userId:(NSString *)userId;

//取消某一次请求，入参是异步apicall过程中返回的字符串,返回结果为True，表示取消成功，为false表示api已经返回，且结果已经被处理
-(BOOL)cancel:(NSString *) sessionKey;

@end
