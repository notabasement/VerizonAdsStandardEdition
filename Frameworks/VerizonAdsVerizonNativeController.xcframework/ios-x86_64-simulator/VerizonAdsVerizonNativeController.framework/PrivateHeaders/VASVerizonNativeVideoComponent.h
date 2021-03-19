///
///  @file
///  @brief Definitions for VASVerizonNativeVideoComponent.
///
///  @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <VerizonAdsVerizonNativeController/VASVerizonNativeComponent.h>
#import <VerizonAdsVerizonNativeController/VASNativeVideoComponent.h>
#import <VerizonAdsCore/VASComponentFactory.h>
#import <VerizonAdsOMSDK/VerizonAdsOMSDK.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - VASVerizonNativeVideoComponentFactory

@interface VASVerizonNativeVideoComponentFactory : NSObject <VASComponentFactory>

/// Required args: kVASComponentArgsAdSessionKey, kVASNativeComponentIdKey, kVASNativeComponentDelegateRefKey
- (nullable id<VASComponent>)newInstanceFromComponentInfo:(NSDictionary<NSString *,id> *)componentInfo
                                                     args:(nullable NSDictionary<NSString *, id> *)args
                                                   VASAds:(VASAds *)vasAds;

@end

#pragma mark - VASVerizonNativeVideoComponent

@interface VASVerizonNativeVideoComponent : VASVerizonNativeComponent <VASNativeVideoComponent>

@property (nonatomic, nullable) OMIDVerizonmediaMediaEvents *omVideoEvents;
@property (nonatomic, nullable) OMIDVerizonmediaAdEvents *omAdEvents;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
