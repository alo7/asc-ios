//
//  ASCDef.h
//  ASC_EXT
//
//  Created by Joseph Lee on 2020/7/15.
//  Copyright © 2020 Alo7. All rights reserved.
//

#ifndef ASCDef_h
#define ASCDef_h

#import <Foundation/Foundation.h>

/**
 * 上课模式
 */
typedef NS_ENUM(NSUInteger, ASCLessonMode) {
    ASCLessonModeClass = 0, // 班课模式
    ASCLessonModeReplay = 1, // 回放模式
    ASCLessonModeVod = 2, // 点播模式
};

/// 配置讯飞 APP ID 的 Key
extern NSString *const iflytekAppId;

/// 配置先声 APP Key 的 Key
extern NSString *const singsoundKey;

/// 配置先声 APP Secrect 的 Key
extern NSString *const singsoundSecret;

#endif /* ASCDef_h */


