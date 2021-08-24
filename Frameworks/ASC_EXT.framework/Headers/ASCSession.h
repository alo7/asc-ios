//
//  ASCSession.h
//  ASC_EXT
//
//  Created by Joseph Lee on 2020/7/15.
//  Copyright © 2020 Alo7. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASCDef.h"
#import "ASCSessionDelegate.h"

/// 进行 ASC 课程时的会话对象
__attribute__((objc_subclassing_restricted))
@interface ASCSession : NSObject

/// ASC Session Delegate
@property(weak, nonatomic, nullable) id <ASCSessionDelegate> delegate;

/// ASC Session Player Delegate
@property(weak, nonatomic, nullable) id <ASCSessionPlayerDelegate> playerDelegate;

/// 一次会话的唯一标识
@property(copy, readonly, nonatomic, nonnull) NSString *identifier;

/// 课堂 id
@property(assign, readonly, nonatomic) NSUInteger lessonId;

/// 会话用户ID
@property(copy, nonatomic, nullable) NSString *userId;

/// 是否开启日志记录
@property(assign, nonatomic) BOOL enableLog;

/// 课程模式，默认普通模式
@property(assign, nonatomic) ASCLessonMode mode;

/// 鉴权 token
@property(copy, nonatomic, nullable) NSString *token;

/// 初始化 ASCSession
/// @param lessonId 课程 ID
- (nonnull instancetype)initLessonId:(NSUInteger)lessonId;

/// 设置额外配置信息
- (void)setExtraInfoValue:(nullable id)value forKey:(NSString * _Nonnull)key;

/// 获取额外配置信息
- (nullable id)getExtraInfoValue:(nullable id)value forKey:(NSString * _Nonnull)key;

@end
