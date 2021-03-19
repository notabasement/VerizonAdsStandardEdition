///
/// @file
/// @brief Definitions for VASPlacement.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsCore/VASCreativeInfo.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Implementations of a placement must conform to this protocol.
 */
@protocol VASPlacement

/// Contains the placement's creative info.
@property (readonly, nullable) VASCreativeInfo *creativeInfo;

@end

NS_ASSUME_NONNULL_END
