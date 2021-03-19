///
/// @file
/// @brief Definitions for VASNativeAd+Private.h
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsCore/VASCommon.h>
#import <VerizonAdsNativePlacement/VASNativeAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASNativeAd (Private)

// VASAds object used for initialization.
@property (readonly) VASAds *vasAds;

@end

NS_ASSUME_NONNULL_END
