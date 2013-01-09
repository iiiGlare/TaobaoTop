//
//  AppSession.h
//  TOPIOSSdk
//
//  用于应用间交互的会话上下文，作为身份识别等用途
//  Created by cenwenchu on 12-11-16.
//
//

#import <Foundation/Foundation.h>
#import "TopEventCallback.h"

@interface TopAppSession : NSObject

@property(copy,nonatomic) NSString *sourceAppKey;
@property(copy,nonatomic) NSString *destAppKey;
@property(copy,nonatomic) NSString *sourceCallbackUrl;//源应用的回调地址，可以用于结果返回时的回调
@property(copy,nonatomic) NSString *destCallbackUrl;//目标应用的回调地址
@property(copy,nonatomic) NSString *event;//应用交互的行为id
@property(copy,nonatomic) NSString *sequence;//序列号，用于会话交互唯一标示
@property (retain)NSCondition* condition;//用于帮助异步场景下模拟同步返回的同步信号量
@property (retain)TopEventCallback *eventCallback;//如果是异步模式来交互，则填入处理结果产生后返回给应用哪一个异步处理对象
@property(copy,nonatomic) NSString *result;//交互后业务处理的结果
@property double sessionBegTime;
@property double sessionEndTime;

@end
