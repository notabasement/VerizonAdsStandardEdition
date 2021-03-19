///
///  @file
///  @brief Definitions for VASNativeVideoComponent.
///
///  @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <VerizonAdsVerizonNativeController/VASNativeViewComponent.h>

NS_ASSUME_NONNULL_BEGIN

/**
 API definition for native video components.
 */
@protocol VASNativeVideoComponent <VASNativeViewComponent>

/// The current playback state of the video asset within this component, YES if playing, NO otherwise.
@property (readonly) BOOL isPlaying;

/// The current mute state of the video asset within this component, YES if muted, NO otherwise.
@property (readonly) BOOL isMuted;

/// Set the percentage at which video playback pauses or resumes playback. Percentage is represented between 0 - 100 or the special identifier, kVASViewAtLeastOnePixelViewable (-1).
@property (readwrite) NSInteger autoplayThresholdPercentage;

/// The "natural" height of the video in points. Returns 0 if the video is not available.
@property (readonly) CGFloat height;

/// The "natural" width of the video in points which may take into account non-square pixel aspect ratios. Returns 0 if the video is not available.
@property (readonly) CGFloat width;

/// Starts playback of the video asset within this component.
- (void)play;

/// Pauses the playback of the video asset within this component.
- (void)pause;

/// Replays the video asset within this component.
- (void)replay;

/// Mutes the audio of this component.
- (void)mute;

/// Unmutes the audio of this component.
- (void)unmute;

/**
 Override the default value (or the value set by the ad server response) for autoplay.
 
 @param autoplay  Boolean value for override autplay
 */
- (void)overrideAutoplay:(BOOL)autoplay;

/**
 Show or hide mute toggle from the video component.
 
 @param muteToggleEnabled  Boolean value for showing/hiding mute toggle
 */
- (void)muteToggleEnabled:(BOOL)muteToggleEnabled;

/**
 Show or hide play button from the video component.
 
 @param playButtonEnabled  Boolean value for showing/hiding play button
 */
- (void)playButtonEnabled:(BOOL)playButtonEnabled;

/**
 Show or hide replay button from the video component.
 
 @param replayButtonEnabled Boolean value for showing/hiding replay button
 */
- (void)replayButtonEnabled:(BOOL)replayButtonEnabled;

/// Called when the video player loaded the video
@property (nonatomic, copy, nullable) void (^videoLoadedHandler)(void);

/// Called when the video player is ready to play the video
@property (nonatomic, copy, nullable) void (^videoReadyHandler)(void);

/// Called when the video player to plays the video
@property (nonatomic, copy, nullable) void (^videoPlayedHandler)(void);

/// Called when the video player to pauses the video
@property (nonatomic, copy, nullable) void (^videoPausedHandler)(void);

/// Called when the video player to completes playing the video
@property (nonatomic, copy, nullable) void (^videoCompletedHandler)(void);

/// Called when the video player volume changes
@property (nonatomic, copy, nullable) void (^videoVolumeChangedHandler)(float volume);

/// Called when the video player progress changes
@property (nonatomic, copy, nullable) void (^videoProgressChangedHandler)(NSTimeInterval current);


@end

NS_ASSUME_NONNULL_END
