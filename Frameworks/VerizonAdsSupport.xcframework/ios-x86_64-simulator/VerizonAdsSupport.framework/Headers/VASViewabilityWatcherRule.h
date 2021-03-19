///
/// @file
/// @brief Implementation of VASViewabilityWatcherRule.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <UIKit/UIView.h>
#import <VerizonAdsSupport/VASVisibilityWatcher.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASViewabilityWatcherRule : NSObject

/// Specifies if the rule, or subclassed rule, should be tracking time. Default is YES.
@property (readonly) BOOL shouldTrack;

/// Indicates whether or not currently tracking viewability.
@property (readonly) BOOL tracking;

/// If the class is tracking time, contains the current amount of time tracked. Default is 0 unless overridden by a subclass.
@property (readonly) NSTimeInterval currentTrackingTime;

/// The duration passed into the initializer.
@property (readonly) NSTimeInterval duration;

/// The amount of time since most recently became viewable.
@property (readonly) NSTimeInterval currentTimeInView;

/// The total time the view has been viewable.
@property (readonly) NSTimeInterval totalTimeInView;

/// The view being watched, passed in on the initializer. Will be nil if the view goes away.
@property (readonly, weak, nullable) UIView *view;

/// Indicates that the view is viewable according to the viewability percentage specified at initialization. See the VASVisibilityWatcher class isVisible method for specifics on how this is calculated.
@property (readonly) BOOL isViewable;

/**
 Initialize the rule viewability watcher and start watching.
 @param view    The view attached to the VASVisibilityWatcher.
 @param scheduler   VASScheduler used by the VASVisibilityWatcher.
 @param targetPercent   Percentage used by the VASVisibilityWatcher.
 @param duration    The amount of time required by the rule before firing.
 @param continuous  Should the viewability time be continous?
 @return an instance of the this class.
 */
- (instancetype)initWithView:(UIView *)view
                   scheduler:(VASScheduler *)scheduler
          viewabilityPercent:(NSInteger)targetPercent
                    duration:(NSTimeInterval)duration
                  continuous:(BOOL)continuous;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// Instruct the watcher to start tracking.
- (void)startTracking;

/// Instruct the watcher to stop tracking.
- (void)stopTracking;

/// Instruct the watcher to stop watching, it cannot be restarted.
- (void)stopWatching;

/// Sub-classes should override to perform any actions required when tracking starts.
- (void)startedTracking;

/// Sub-classes should override to perform any actions required when tracking stops.
- (void)stoppedTracking;

@end

NS_ASSUME_NONNULL_END
