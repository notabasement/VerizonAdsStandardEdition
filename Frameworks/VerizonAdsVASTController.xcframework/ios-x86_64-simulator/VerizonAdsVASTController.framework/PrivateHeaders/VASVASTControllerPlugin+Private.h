///
///  @file
///  @brief Definitions for VASVASTControllerPlugin+Private.
///
///  @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsVASTController/VerizonAdsVASTController.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASVASTControllerPlugin (Private)

// private method to access resource bundle (without polluting plugin interface)
+ (nullable NSBundle *)resourceBundle;

@end

NS_ASSUME_NONNULL_END
