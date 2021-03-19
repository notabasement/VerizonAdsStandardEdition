///
///  @file
///  @brief Definitions for VASVideoPlayerPlugin+Private.
///
///  @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsVideoPlayer/VASVideoPlayerPlugin.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASVideoPlayerPlugin (Private)

// private method to access resource bundle (without polluting plugin interface)
+ (nullable NSBundle *)resourceBundle;

@end

NS_ASSUME_NONNULL_END
