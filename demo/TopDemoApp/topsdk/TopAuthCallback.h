//
//  TopAuthCallback.h
//  TOPIOSSdk
//
//  Created by cenwenchu on 12-8-2.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TopAuthCallback : NSObject

@property(retain,nonatomic) id target;
@property SEL callback;

@end
