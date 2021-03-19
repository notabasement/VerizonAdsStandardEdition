///
///  @file
///  @brief Definitions for VASInlineAdViewRefresher
///
///  @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>
#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VerizonAdsSupport.h>

NS_ASSUME_NONNULL_BEGIN

@class VASInlineAdFactory;
@class VASInlineAdView;

@interface VASInlineAdViewRefresher : NSObject

- (instancetype)initWithInlineAdFactory:(VASInlineAdFactory *)inlineAdFactory vasAds:(VASAds *)vasAds NS_DESIGNATED_INITIALIZER;
- (void)startRefreshForAdView:(VASInlineAdView *)inlineAdView queue:(dispatch_queue_t)queue;
- (void)stopRefresh;
- (void)resumeRefreshTimer;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
