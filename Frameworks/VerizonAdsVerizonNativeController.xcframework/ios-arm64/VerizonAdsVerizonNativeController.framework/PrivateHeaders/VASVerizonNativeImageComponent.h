///
///  @file
///  @brief Definitions for VASVerizonNativeImageComponent.
///
///  @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <VerizonAdsVerizonNativeController/VASNativeImageComponent.h>
#import <VerizonAdsVerizonNativeController/VASVerizonNativeComponent.h>
#import <VerizonAdsCore/VASComponentFactory.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - VASVerizonNativeImageComponentFactory

@interface VASVerizonNativeImageComponentFactory : NSObject <VASComponentFactory>

/// Required args: kVASComponentArgsAdSessionKey, kVASNativeComponentIdKey, kVASNativeComponentDelegateRefKey
- (nullable id<VASComponent>)newInstanceFromComponentInfo:(NSDictionary<NSString *,id> *)componentInfo
                                                     args:(nullable NSDictionary<NSString *, id> *)args
                                                   VASAds:(VASAds *)vasAds;

@end

#pragma mark - VASVerizonNativeImageComponent

@interface VASVerizonNativeImageComponent : VASVerizonNativeComponent <VASNativeImageComponent>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
