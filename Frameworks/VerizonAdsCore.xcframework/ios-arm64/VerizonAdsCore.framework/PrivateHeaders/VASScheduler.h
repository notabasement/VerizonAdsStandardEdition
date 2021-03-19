///
/// @internal
/// @file
/// @brief Definitions for VASScheduler.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class VASTask;

/// Block definition for scheduled task blocks.
typedef void (^VASSchedulerTaskBlock)(VASTask *task);


/// The facility for starting any timer-based functionality such as expiration timers or repeating polling tasks like daily GDPR checks. It adds additional benefits such as automatically handling pausing timers when an app is backgrounded and resuming when foregrounded. All usage is with dispatch timers and can be called from any queue while still maintaining thread safety.
@interface VASScheduler : NSObject

/** Used to schedule a timer to fire at an absolute time. This is based on "wall time", e.g. an ad should expire after 30 min., regardless if it is in the background and suspended. If the time has elapsed while suspended in the background, then it will execute immediately upon foregrounding.
 
 @param fireDate    An absolute time for the task handler to be executed. Note 10% leeway is added for system performance optimization.
 @param identifier  An optional name to be given to the task to identify it.
 @param taskBlock   Task executed when the timer fires. The `taskBlock` is called on an arbitrary queue.
 @return An instance of VASTask that has been added to the scheduler.
 */
- (VASTask *)scheduleTaskForDate:(NSDate *)fireDate
                      identifier:(nullable NSString *)identifier
                            task:(VASSchedulerTaskBlock)taskBlock;

/** Used to schedule a timer to fire after a given interval. If `wallTime` is NO, then the time is paused while in the background, e.g. display something on screen for a certain amount of time that would not include time suspended in the background. If `wallTime` is YES, then the interval is an absolute time such as retrieving GDPR every 24 hours. If the "wall time" has elapsed while suspended in the background, then it will execute immediately upon foregrounding.
 
 @param interval    Interval in NSTimeInterval seconds between the task firing.
 @param wallTime    If `wallTime` is YES, the task will base its time on "wall time" which is independent.
 @param identifier  An optional name to be given to the task to identify it.
 @param taskBlock   Task executed when the timer fires. The `taskBlock` is called on an arbitrary queue.
 @return An instance of VASTask that has been added to the scheduler.
 */
- (VASTask *)startTaskWithInterval:(NSTimeInterval)interval
                          wallTime:(BOOL)wallTime
                        identifier:(nullable NSString *)identifier
                              task:(VASSchedulerTaskBlock)taskBlock;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
