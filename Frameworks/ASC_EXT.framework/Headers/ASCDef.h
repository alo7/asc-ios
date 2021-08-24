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
    ASCLessonModePlan = 3,  
    ASCLessonModePlanReplay = 4
};

/// 配置讯飞 APP ID 的 Key
extern NSString *const iflytekAppId;

/// 配置先声 APP Key 的 Key
extern NSString *const singsoundKey;

/// 配置先声 APP Secrect 的 Key
extern NSString *const singsoundSecret;

#endif /* ASCDef_h */


typedef enum ASCEventType: NSUInteger {
    /**@brief 准备完成事件*/
    ASCEventPrepareDone,
    /**@brief 自动启播事件*/
    ASCEventAutoPlayStart,
    /**@brief 首帧显示时间*/
    ASCEventFirstRenderedStart,
    /**@brief 播放完成事件*/
    ASCEventCompletion,
    /**@brief 缓冲开始事件*/
    ASCEventLoadingStart,
    /**@brief 缓冲完成事件*/
    ASCEventLoadingEnd,
    /**@brief 跳转完成事件*/
    ASCEventSeekEnd,
    /**@brief 循环播放开始事件*/
    ASCEventLoopingStart,
    /**@brief player Stop*/
    ASCEventStop = 9999,
    /**@brief player Start*/
    ASCEventStart,
    /**@brief player Pause*/
    ASCEventPause,
    
} ASCEventType;
