///
/// @file
/// @brief Definitions for VASVerizonNativeImpressionRuleComponent.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VerizonAdsSupport.h>

@class VASVerizonNativeAd;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kVASVerizonNativeImpressionRuleComponentType;

/// Additional keys for VASVerizonNativeImpressionRuleComponentFactory args.

/// The VASVerizonNativeAd to be associated with the VASRuleCompoent.
/// Value: VASWeakRef containing the VASVerizonNativeAd object.
extern NSString * const kVASRuleComponentVerizonNativeAdRefKey;  // VASWeakRef<VASVerizonNativeAd *>

#pragma mark - VASVerizonNativeImpressionRuleComponentFactory

/**
 VASVerizonNativeImpressionRuleComponentFactory is a factory class that handles creating instances of VASRuleComponent.
 */
@interface VASVerizonNativeImpressionRuleComponentFactory : NSObject <VASComponentFactory>

/**
 Create a new VASVerizonNativeImpressionRuleComponent.
 
 @param componentInfo   The JSON used to construct the rule component.
 @param args            The additional arguments needed for the construction: kVASRuleComponentDelegateRefKey, kVASRuleComponentViewRefKey, kVASRuleComponentVerizonNativeAdRefKey. Any missing or invalid args will ressult in returning nil.
 @param vasAds          The VASAds instance being used.
 @return the VASVerizonNativeImpressionRuleComponent kind of VASRuleComponent.
 */
- (nullable id<VASRuleComponent>)newInstanceFromComponentInfo:(NSDictionary<NSString *,id> *)componentInfo
                                                         args:(nullable NSDictionary<NSString *, id> *)args
                                                       VASAds:(VASAds *)vasAds;

@end

#pragma mark - VASVerizonNativeImpressionRuleComponent

/// A VASRuleComponent that handles viewability of a view.
@interface VASVerizonNativeImpressionRuleComponent : VASStaticViewabilityRuleComponent

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
