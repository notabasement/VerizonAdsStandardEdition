///
///  @file
///  @brief Definitions for VASInterstitialAdFactory.
///
///  @copyright Copyright © 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>
#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VerizonAdsSupport.h>
#import "VASInterstitialAd.h"

NS_ASSUME_NONNULL_BEGIN

/// VASInterstitialAdFactory error domain.
FOUNDATION_EXPORT NSErrorDomain const kVASInterstitialAdFactoryErrorDomain;

/// Error codes that are used in the VASInterstitialAdFactory error domain.
typedef NS_ENUM(NSInteger, VASInterstitialAdFactoryError) {
    /// An ad load is already in progress.
    VASInterstitialAdFactoryErrorAdLoadInProgress = 1,
    /// A VASAdSession is missing its adapter.
    VASInterstitialAdFactoryErrorMissingAdAdapter
};

/// VASRequestMetadata - Interstitial Ad Placement ID key
FOUNDATION_EXPORT NSString * const kVASMetadataInterstitialAdPlacementIdKey;
/// VASRequestMetadata - Interstitial Ad Type key
FOUNDATION_EXPORT NSString * const kVASMetadataInterstitialPlacementTypeKey;


@class VASInterstitialAdFactory;

/**
 Protocol for receiving notifications from the VASInterstitialAdFactory.
 */
@protocol VASInterstitialAdFactoryDelegate <NSObject>

/**
 Called when the VASInterstitialAd has been loaded. A new VASInterstitialAd instance will be provided as part of this callback.
 
 @param adFactory         The calling VASInterstitialAdFactory.
 @param interstitialAd    The VASInterstitialAd object that is ready to be displayed.
 */
- (void)interstitialAdFactory:(VASInterstitialAdFactory *)adFactory didLoadInterstitialAd:(VASInterstitialAd *)interstitialAd;

/**
 Called when there is an error requesting a VASInterstitialAd.
 
 @param adFactory The calling VASInterstitialAdFactory.
 @param errorInfo An VASErrorInfo object containing details about the error.
 */
- (void)interstitialAdFactory:(VASInterstitialAdFactory *)adFactory didFailWithError:(VASErrorInfo *)errorInfo;

@end

/**
 VASInterstitialAdFactory is a factory class that handles loading and caching of VASInterstitialAd placements. It uses the VASInterstitialAdFactoryDelegate protocol to provide notifications about VASInterstitialAd creation.
 */
@interface VASInterstitialAdFactory : NSObject

/**
 Initialize an VASInterstitialAdFactory for creating VASInterstitialAd objects. Use this to set the placementId and listener for VASInterstitialAd that the VASInterstitialAdFactory will create.
 
 @param placementId   The placementId that will be set for all VASInterstitialAd that the VASInterstitialAdFactory creates.
 @param vasAds        The VASAds instance for this object to use.
 @param delegate      The VASInterstitialAdFactoryDelegate that will receive ad factory events for the VASInterstitialAdFactory.
 @return An initialized instance of this class.
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                             vasAds:(VASAds *)vasAds
                           delegate:(nullable id <VASInterstitialAdFactoryDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

/**
 Requests a new VASInterstitialAd.
 
 @param interstitialAdDelegate the VASInterstitialAdDelegate that will receive ad events for the  VASInterstitialAd.
 */
- (void)load:(id <VASInterstitialAdDelegate>)interstitialAdDelegate;

/**
 Attempts to load a VASInterstitialAd from the cache.  If the cache is empty, nil is returned.
 
 @param interstitialAdDelegate The VASInterstitialAdDelegate that will receive ad events for the VASInterstitialAd.
 @return                       A VASInterstitialAd from the cache or nil if the cache is empty.
 */
- (nullable VASInterstitialAd *)loadAdFromCache:(id <VASInterstitialAdDelegate>)interstitialAdDelegate /* @cond */ NS_SWIFT_NAME(loadAdFromCache(_:)) /* @endcond */;

/**
 Loads the VASInterstitialAd for the provided bid.
 
 @param bid              The Bid that will be loaded.
 @param interstitialAdDelegate The VASInterstitialAdDelegate that will receive ad events for the VASInterstitialAd.
 */
- (void)loadBid:(VASBid *)bid interstitialAdDelegate:(id <VASInterstitialAdDelegate>)interstitialAdDelegate;

/**
 Aborts any load requests that are still active.
 */
- (void)abortLoad;

/**
 Initializes a cache replenishment request.  Note that if a request is already
 in progress or the cache is not below the replenishment threshold, no request will be made.
 */
- (void)prefetch;

/**
Frees the internal resources held by the factory. The instance cannot be used after this method is called.
 */
- (void)destroy;

/**
 Requests a bid for the provided placement Id.
 
 @param placementId        The placementId that will be set for all VASInterstitialAd that the VASInterstitialAdFactory creates.
 @param requestMetadata    The VASRequestMetadata to use for ad requests.
 @param vasAds             The VASAds instance for this object to use.
 @param handler            The completion handler that will receive the bid request result.
 */
+ (void)requestBidForPlacementId:(NSString *)placementId
                 requestMetadata:(nullable VASRequestMetadata *)requestMetadata
                          vasAds:(VASAds *)vasAds
               completionHandler:(VASBidRequestCompletionHandler)handler;

/**
 Get the placementId for the VASInterstitialAdFactory.
 */
@property (readonly, copy) NSString *placementId;

/**
 Gets or sets the cache replenishment threshold override for this instance of the factory, which will then be used instead
 of SDK configuration or the default value. If the resulting cache size after an ad is loaded from the cache is less than or equal
 to this value the factory will attempt to replenish the cache. Must be a non-negative integer. Max value is 30.
 */
@property NSUInteger cacheReplenishmentThresholdOverride;

/**
 The VASRequestMetadata object that overrides global VASRequestMetadata for the VASInterstitialAdFactory ad requests.
 */
@property (nullable) VASRequestMetadata *requestMetadata;

/**
 The object implementing the VASInterstitialAdFactoryDelegate protocol, to receive ad factory event callbacks.
 */
@property (nonatomic, weak, nullable) id <VASInterstitialAdFactoryDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
