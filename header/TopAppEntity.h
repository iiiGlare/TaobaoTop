//
//  AppEntity.h
//  TOPIOSSdk
//
//  app信息
//  Created by cenwenchu on 12-11-16.
//
//

#import <Foundation/Foundation.h>
#import "TopAppEntity.h"

@interface TopAppEntity : NSObject

FOUNDATION_EXPORT NSString *const PLUG_TYPE_NATIVE;
FOUNDATION_EXPORT NSString *const PLUG_TYPE_H5;

@property(copy,nonatomic) NSString *appkey;
@property(copy,nonatomic) NSString *callbackUrl;//应用下载地址，如果apptype是h5，则不会使用
@property(copy,nonatomic) NSString *downloadUrl;//应用下载地址，如果apptype是h5，则不需要
@property(copy,nonatomic) NSString *pluginType;//分成native和h5两种模式
@property(copy,nonatomic) NSString *categoryCode;//插件类目code
@property(copy,nonatomic) NSString *articleCode;//插件id
@property(copy,nonatomic) NSString *articleName;//插件名称
@property(copy,nonatomic) NSString *introduce;
@property(copy,nonatomic) NSString *desc;
@property(copy,nonatomic) NSString *pictures;
@property(copy,nonatomic) NSString *userUrl;
@property(copy,nonatomic) NSString *iconUrl;
@property(copy,nonatomic) NSString *spId;
@property(copy,nonatomic) NSString *spNick;
@property(copy,nonatomic) NSString *spWangWang;
@property(copy,nonatomic) NSString *spMobile;


@property double timestamp;


+(TopAppEntity *)generateTopAppEntityFromDictionary:(NSDictionary *)data;

@end
