///
///  @file
///  @brief Definitions for VASVerizonNativeTextComponent.
///
///  @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <VerizonAdsVerizonNativeController/VASNativeTextComponent.h>
#import <VerizonAdsVerizonNativeController/VASVerizonNativeComponent.h>
#import <VerizonAdsCore/VASComponentFactory.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - VASVerizonNativeTextComponentFactory

@interface VASVerizonNativeTextComponentFactory : NSObject <VASComponentFactory>

/// Required args: kVASComponentArgsAdSessionKey, kVASNativeComponentIdKey, kVASNativeComponentDelegateRefKey
- (nullable id<VASComponent>)newInstanceFromComponentInfo:(NSDictionary<NSString *,id> *)componentInfo
                                                     args:(nullable NSDictionary<NSString *, id> *)args
                                                   VASAds:(VASAds *)vasAds;

@end

#pragma mark - VASVerizonNativeTextComponent

@interface VASVerizonNativeTextComponent : VASVerizonNativeComponent <VASNativeTextComponent>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
