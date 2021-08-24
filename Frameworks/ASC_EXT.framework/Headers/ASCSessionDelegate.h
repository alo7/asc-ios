//
//  ASCSessionDelegate.h
//  ASC_EXT
//
//  Created by Joseph Lee on 2020/7/15.
//  Copyright © 2020 Alo7. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASCError.h"
#import "ASCDef.h"
@class ASCSession;

/// ASC 会话协议
@protocol ASCSessionDelegate <NSObject>

@optional

-(void)ascSessionDidStart:(ASCSession *)session;
-(void)ascSession:(ASCSession *)session didOccurError:(ASCErrorCode)errorCode;
-(void)ascSessionDidExit:(ASCSession *)session;
@end

@protocol ASCSessionPlayerDelegate <NSObject>

@optional
-(void)ascSession:(ASCSession *)session playEvent:(ASCEventType)event;
-(void)onCurrentPositionUpdate:(ASCSession *)session position:(int64_t)position;
-(void)onBufferedPositionUpdate:(ASCSession *)session position:(int64_t)position;
@end

