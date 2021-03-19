///
///  @file
///  @brief Definitions for VASOMSDKPlugin+Private.
///
///  @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsOMSDK/VASOMSDKPlugin.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASOMSDKPlugin (Private)

// private method to access resource bundle (without polluting plugin interface)
+ (nullable NSBundle *)resourceBundle;

@end

NS_ASSUME_NONNULL_END
