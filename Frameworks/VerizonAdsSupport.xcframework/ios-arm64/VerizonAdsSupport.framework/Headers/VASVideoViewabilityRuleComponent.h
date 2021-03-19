///
/// @file
/// @brief Definitions for VASVideoViewabilityRuleComponent.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VASViewabilityWatcherRule.h>

NS_ASSUME_NONNULL_BEGIN

/// Keys for ComponentFactory args.

/// The VASVideoPlayer object to be used by the VASRuleCompoent.
/// Value: VASWeakRef containing the VASVideoPlayer-conforming object.
extern NSString * const kVASRuleComponentVideoPlayerRefKey;  // VASWeakRef<id<VASVideoPlayer>>

/// The VASRuleFiredDelegate delegate to be called when the rule fires.
/// Value: VASWeakRef containing the delegate.
extern NSString * const kVASRuleComponentDelegateRefKey; // VASWeakRef<id<VASRuleFiredDelegate>>

#pragma mark - VASVideoViewabilityRuleComponentFactory

/**
 VASVideoViewabilityRuleComponentFactory is a factory class that handles creating instances of VASRuleComponent.
*/
@interface VASVideoViewabilityRuleComponentFactory : NSObject <VASComponentFactory>

/**
 Create a new VASVideoViewabilityRuleComponent.
 
 @param componentInfo   The JSON used to construct the rule component.
 @param args            The additional arguments needed for the construction: kVASRuleComponentDelegateRefKey, kVASRuleComponentViewRefKey.
 @param vasAds          The VASAds instance being used.
 @return the VASVideoViewabilityRuleComponent kind of VASRuleComponent.
 */
- (nullable id<VASRuleComponent>)newInstanceFromComponentInfo:(NSDictionary<NSString *,id> *)componentInfo
                                                         args:(nullable NSDictionary<NSString *, id> *)args
                                                       VASAds:(VASAds *)vasAds;

@end

#pragma mark - VASVideoViewabilityRuleComponent

/// A VASRuleComponent that handles viewability of a view.
@interface VASVideoViewabilityRuleComponent : VASViewabilityWatcherRule <VASRuleComponent>

/// VideoPlayer reference from the passed UIView<VASVideoPlayer>.
@property (readonly, weak) id<VASVideoPlayer> videoPlayer;

/**
 Initialize an instance of this class.
 
 @param player              The video player used by the rule component. Must conform to the VASVideoPlayer protocol.
 @param scheduler           The VASScheduler to use for scheduling the rule timers, if needed.
 @param percent             The percent of viewability, 0-100, required to establish the view as visible.
 @param duration            The amount of time required by the rule before firing.
 @param continuous          YES if the duration needs to be continuous.
 @param audioRequired       YES if audio is required to determine viewability.
 @param eventId             The event id of this rule component.
 @param eventArgs           Supplemental event arguments.
 @param delegate            The object that will respond to the VASRuleFiredDelegate protocol calls.
 @return a new instance of this class.
 */
- (instancetype)initWithVideoPlayer:(id<VASVideoPlayer>)player
                          scheduler:(VASScheduler *)scheduler
                 viewabilityPercent:(NSInteger)percent
                     viewedDuration:(NSTimeInterval)duration
                   viewedContinuous:(BOOL)continuous
                      audioRequired:(BOOL)audioRequired
                            eventId:(NSString *)eventId
                          eventArgs:(nullable NSDictionary<NSString *, id> *)eventArgs
                           delegate:(id<VASRuleFiredDelegate>)delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

