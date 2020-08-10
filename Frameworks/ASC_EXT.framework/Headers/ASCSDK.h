//
//  ASCEntry.h
//  ASC_EXT
//
//  Created by Joseph Lee on 2020/7/8.
//  Copyright © 2020 Alo7. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ASCSession.h"

/// ASC SDK
__attribute__((objc_subclassing_restricted))
@interface ASCSDK : NSObject

/// SDK 单例
+ (nonnull instancetype)sharedInstance;

/// 获得当前 SDK 版本
+ (NSString * _Nonnull)getVersion;

/// SDK 是否校验初始化成功
+ (BOOL)isInitialized;

/// 携带参数初始化 SDK（参数待定义，当前以普通 Key-Value 方式传递）
/// @param context 启动参数
+ (void)initialize:(NSDictionary * _Nullable)context;

/// SDK 是否进行日志采集，默认 YES
/// @param enable YES/NO
+ (void)setLogEnabld:(BOOL)enable;

/// SDK 获取日志，返回压缩后的文件地址
+ (NSURL * _Nonnull)getArchivedLog;

/// 开始进行 ASC 课程
/// @param session ASC课程会话
/// @param viewController 设置源 ViewController
+ (void)startBySession:(ASCSession * _Nonnull)session
    fromViewController:(UIViewController * _Nullable)viewController;

@end
