//
//  EventCallBack.h
//  TOPIOSSdk
//
//  异步处理返回后的消息驱动属性
//
//  Created by cenwenchu on 12-11-16.
//
//

#import <Foundation/Foundation.h>

@interface TopEventCallback : NSObject

@property(retain,nonatomic) id target;
@property SEL callback;
@property BOOL needMainThreadCallback;//是否需要用主线程来处理返回结果。
@property(retain,nonatomic) NSDictionary* context;//回调以前的上下文保存

@end
