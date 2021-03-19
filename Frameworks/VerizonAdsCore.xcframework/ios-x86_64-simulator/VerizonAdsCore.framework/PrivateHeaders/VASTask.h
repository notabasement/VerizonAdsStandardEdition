///
/// @internal
/// @file
/// @brief Definitions for VASTask.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// This class handles the duties of executing a task at a specified time. It is only generated by initiating a task using the VASScheduler as the central scheduling utility. Once added to the scheduler, use the methods in this class to manipulate the task by pausing, resuming, and canceling the task when no longer needed.
@interface VASTask : NSObject

/// An arbitrary named value to help uniquely identify this task.
@property (readonly, copy) NSString *identifier;

/// YES when the task has been completed and removed from the scheduler.
@property (readonly) BOOL completed;

/// YES when the task timer has been paused. NO indicates the task is executing or waiting for the next fire date.
@property (readonly) BOOL paused;

/// Cancel the task. Doing so stops the timer and removes it from the scheduler. No more handler calls will be made, but will not stop one already being executed.
- (void)cancel;

/// Pause the task's timer. The task will no longer fire the handler, but will not stop one already being executed. Calling resume will restart the timer with the amount of time remaining on the timer.
- (void)pause;

/// Resume the paused task's timer. The timer will pick up from the time it was paused.
- (void)resume;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
