///
/// @file
/// @brief Definitions for VASStaticViewabilityRuleComponent.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VASViewabilityWatcherRule.h>

NS_ASSUME_NONNULL_BEGIN

/// Keys for ComponentFactory args.

/// The UIView to be used by the VASRuleCompoent.
/// Value: VASWeakRef containing the UIView object.
extern NSString * const kVASRuleComponentViewRefKey;  // VASWeakRef<UIView *>

#pragma mark - VASStaticViewabilityRuleComponentFactory

/**
 VASStaticViewabilityRuleComponentFactory is a factory class that handles creating instances of VASRuleComponent.
*/
@interface VASStaticViewabilityRuleComponentFactory : NSObject <VASComponentFactory>

/**
 Create a new VASStaticViewabilityRuleComponent.
 
 @param componentInfo   The JSON used to construct the rule component.
 @param args            The additional arguments needed for the construction: kVASRuleComponentDelegateRefKey, kVASRuleComponentViewRefKey.
 @param vasAds          The VASAds instance being used.
 @return the VASStaticViewabilityRuleComponent kind of VASRuleComponent.
 */
- (nullable id<VASRuleComponent>)newInstanceFromComponentInfo:(NSDictionary<NSString *,id> *)componentInfo
                                                         args:(nullable NSDictionary<NSString *, id> *)args
                                                       VASAds:(VASAds *)vasAds;

@end

#pragma mark - VASStaticViewabilityRuleComponent

/// A VASRuleComponent that handles viewability of a view.
@interface VASStaticViewabilityRuleComponent : VASViewabilityWatcherRule <VASRuleComponent>

/**
 Initialize an instance of this class.
 
 @param view                The UIView used by the rule component.
 @param scheduler           The VASScheduler to use for scheduling the rule timers, if needed.
 @param percent             The percent of viewability, 0-100, required to establish the view as visible.
 @param duration            The amount of time required by the rule before firing.
 @param continuous          YES if the duration needs to be continuous.
 @param eventId             The event id of this rule component.
 @param eventArgs           Supplemental event arguments.
 @param delegate            The object that will respond to the VASRuleFiredDelegate protocol calls.
 @return a new instance of this class.
 */
- (instancetype)initWithView:(UIView *)view
                   scheduler:(VASScheduler *)scheduler
          viewabilityPercent:(NSInteger)percent
              viewedDuration:(NSTimeInterval)duration
            viewedContinuous:(BOOL)continuous
                     eventId:(NSString *)eventId
                   eventArgs:(nullable NSDictionary<NSString *, id> *)eventArgs
                    delegate:(id<VASRuleFiredDelegate>)delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
