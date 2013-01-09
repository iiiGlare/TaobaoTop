//
//  TopIOSUtil.h
//  TopIOSSdk
//
//  top的一系列工具类
//
//  Created by cenwenchu on 12-6-19.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonHMAC.h>

//Functions for Encoding Data.
@interface NSData (TOPEncode)
- (NSString *)MD5EncodedString;
- (NSData *)HMACSHA1EncodedDataWithKey:(NSString *)key;
- (NSString *)base64EncodedString;
@end

//Functions for Encoding String.
@interface NSString (TOPEncode)
- (NSString *)MD5EncodedString;
- (NSData *)HMACSHA1EncodedDataWithKey:(NSString *)key;
- (NSString *)base64EncodedString;
@end

@interface TopIOSUtil : NSObject

//将dict里面的参数和url连接起来成为一个可以get的地址，会做urlencoding
+ (NSString *)serializeURL:(NSString *)baseURL params:(NSDictionary *)params httpMethod:(NSString *)httpMethod;
//将dict中的数据转换为字符串，可以选择是否需要urlencoding
+ (NSString *)stringFromDictionary:(NSDictionary *)dict needURLEncoding:(BOOL)needURLEncoding;
//用开放平台的签名算法对dict做签名，并放入到params中
+(void) sign:(NSMutableDictionary *)params appSecret:(NSString *)appSecret;
//创建Mutlipart请求
+(void)setMultipartPostBody:(NSMutableURLRequest *)req reqParams:(NSMutableDictionary *)reqParams attachs:(NSMutableDictionary *)attachs;
+(NSString *)decodeFromPercentEscapeString: (NSString *) input;

@end
