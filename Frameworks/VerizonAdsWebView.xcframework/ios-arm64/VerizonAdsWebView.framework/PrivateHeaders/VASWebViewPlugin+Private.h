///
///  @file
///  @brief Definitions for VASWebViewPlugin+Private.
///
///  @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsWebView/VASWebViewPlugin.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASWebViewPlugin (Private)

// private method to access resource bundle (without polluting plugin interface)
+ (nullable NSBundle *)resourceBundle;

@end

NS_ASSUME_NONNULL_END
