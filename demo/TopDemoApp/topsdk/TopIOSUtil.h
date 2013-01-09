//
//  TopIOSUtil.h
//  TopIOSSdk
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

+ (NSString *)serializeURL:(NSString *)baseURL params:(NSDictionary *)params httpMethod:(NSString *)httpMethod;
+ (NSString *)stringFromDictionary:(NSDictionary *)dict needURLEncoding:(BOOL)needURLEncoding;
+(void) sign:(NSMutableDictionary *)params appSecret:(NSString *)appSecret;
+(void)setMultipartPostBody:(NSMutableURLRequest *)req reqParams:(NSMutableDictionary *)reqParams attachs:(NSMutableDictionary *)attachs;
+(NSString *)decodeFromPercentEscapeString: (NSString *) input;

@end
