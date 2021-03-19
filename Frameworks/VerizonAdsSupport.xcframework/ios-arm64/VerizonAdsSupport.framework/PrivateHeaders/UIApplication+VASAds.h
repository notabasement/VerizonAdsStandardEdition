///
/// @file
/// @brief Definitions for the UIApplication+VASAds category.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <UIKit/UIKit.h>

@interface UIApplication (VASAds)

// A more comprehensive alternative to UIApplication canOpenURL.
- (BOOL)vas_isURLSchemeSupported:(NSURL *)url;

// Supports iOS 8+ to implement with a completion handler. The call is handled asynchronously on the main thread for all iOS versions, however, pre-iOS 10 will still execute the older openURL call syncrhonously on the main thread before calling the completion handler.
- (void)vas_openURL:(NSURL *)url completionHandler:(void (^)(BOOL success))completion;

@end
