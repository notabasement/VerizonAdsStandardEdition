///
/// @file
/// @brief Definitions for VASNativeAdFactory
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>
#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VerizonAdsSupport.h>

NS_ASSUME_NONNULL_BEGIN

/// VASNativeAd error domain.
FOUNDATION_EXPORT NSErrorDomain const kVASNativeAdFactoryErrorDomain;

/// VASRequestMetadata - Native Ad Placement Type key
FOUNDATION_EXPORT NSString * const kVASMetadataKeyNativeAdPlacementType;
/// VASRequestMetadata - Native Ad Placement ID key
FOUNDATION_EXPORT NSString * const kVASMetadataKeyNativeAdPlacementId;
/// VASRequestMetadata - Native Ad Types key
FOUNDATION_EXPORT NSString * const kVASMetadataKeyNativeAdTypes;

/// Error codes that are used in the NativeAd error domain
typedef NS_ENUM(NSInteger, VASNativeAdFactoryError) {
    /// An ad load is already in progress.
    VASNativeAdFactoryErrorAdLoadInProgress = 1,
    /// A VASAdSession is missing its adapter.
    VASNativeAdFactoryErrorMissingAdAdapter
};

@class VASNativeAdFactory;
@class VASNativeAd;
@protocol VASNativeAdDelegate;

/**
 Protocol for receiving notifications from the VASNativeAdFactory.
 */
@protocol VASNativeAdFactoryDelegate <NSObject>

/**
 Called when the components for the VASNativeAd have been loaded. A new VASNativeAd instance will be provided as part of this callback.
 
 Called on an arbitrary background queue, dispatch to the main queue for UI placement.
 
 @param adFactory The calling VASNativeAdFactory.
 @param nativeAd  The VASNativeAd object that is ready to be displayed.
 */
- (void)nativeAdFactory:(VASNativeAdFactory *)adFactory
        didLoadNativeAd:(VASNativeAd *)nativeAd;

/**
 Called when there is an error requesting a VASNativeAd.
 
 Called on an arbitrary background queue.
 
 @param adFactory The calling VASNativeAdFactory.
 @param errorInfo A VASErrorInfo object containing details about the error.
 */
- (void)nativeAdFactory:(VASNativeAdFactory *)adFactory
       didFailWithError:(nullable VASErrorInfo *)errorInfo;

@end

/**
 VASNativeAdFactory is a factory class that handles loading and caching of VASNativeAd placements. It uses the VASNativeAdFactoryDelegate protocol to provide notifications about VASNativeAd creation.
 */
@interface VASNativeAdFactory : NSObject

/**
 Initialize a VASNativeAdFactory for creating VASNativeAd objects. Use this to set the placementId and listener for VASNativeAd objects that the VASNativeAdFactory will create.
 
 @param placementId       The placementId that will be set for all VASNativeAd objects that the VASNativeAdFactory creates.
 @param adTypes           The array of requested native types.
 @param vasAds            The VASAds object to use for creating a VASNativeAd.
 @param delegate          The VASNativeAdFactoryDelegate that will receive ad factory events for the VASNativeAdFactory.
 @returns An instance of this class.
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                            adTypes:(NSArray<NSString *> *)adTypes
                             vasAds:(VASAds *)vasAds
                           delegate:(nullable id <VASNativeAdFactoryDelegate>)delegate NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
Frees the internal resources held by the factory. The instance cannot be used after this method is called.
 */
- (void)destroy;

/**
 Requests a bid for the opportunity to win the VASNativeAd impression.
 
 @param placementId        The placementId that will be set for all VASNativeAds that the VASNativeAdFactory creates.
 @param adTypes            The array of requested native types.
 @param requestMetadata    The VASRequestMetadata to use for ad requests.
 @param vasAds             The VASAds instance for this object to use.
 @param handler            The completion handler that will receive the bid request result.
 */
+ (void)requestBidForPlacementId:(NSString *)placementId
                         adTypes:(NSArray<NSString *> *)adTypes
                 requestMetadata:(nullable VASRequestMetadata *)requestMetadata
                          vasAds:(VASAds *)vasAds
               completionHandler:(VASBidRequestCompletionHandler)handler;

/**
 Requests a new VASNativeAd.
 
 @param nativeAdDelegate    The VASNativeAdDelegate that will receive ad events for the VASNativeAd.
 */
- (void)load:(id <VASNativeAdDelegate>)nativeAdDelegate;

/**
 Attempts to load a VASNativeAd from the cache.  If the cache is empty, nil is returned.
 
 @param nativeAdDelegate The VASNativeAdDelegate that will receive ad events for the VASNativeAd.
 @return                 A VASNativeAd from the cache or nil if the cache is empty.
 */
- (nullable VASNativeAd *)loadAdFromCache:(id <VASNativeAdDelegate>)nativeAdDelegate /* @cond */ NS_SWIFT_NAME(loadAdFromCache(_:)) /* @endcond */;

/**
 Loads the VASNativeAd for the provided bid.
 
 @param bid              The Bid that will be loaded.
 @param nativeAdDelegate The VASNativeAdDelegate that will receive ad events for the VASNativeAd.
 */
- (void)loadBid:(VASBid *)bid nativeAdDelegate:(id <VASNativeAdDelegate>)nativeAdDelegate;

/**
 Requests a new VASNativeAd without loading its assets (images and videos).
 
 @param nativeAdDelegate    The VASNativeAdDelegate that will receive ad events for the VASNativeAd.
 */
- (void)loadWithoutAssets:(id <VASNativeAdDelegate>)nativeAdDelegate;

/**
 Loads the VASNativeAd for the provided bid, without loading the ad's assets (images and videos).
 
 @param bid              The Bid that will be loaded.
 @param nativeAdDelegate The VASNativeAdDelegate that will receive ad events for the VASNativeAd.
 */
- (void)loadBidWithoutAssets:(VASBid *)bid nativeAdDelegate:(id <VASNativeAdDelegate>)nativeAdDelegate;

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
 The placementId for the VASNativeAdFactory.
 */
@property (readonly, copy) NSString *placementId;

/**
 The object implementing the VASNativeAdFactoryDelegate protocol, to receive ad factory event callbacks.
 */
@property (weak, nullable) id <VASNativeAdFactoryDelegate> delegate;

/**
 The VASRequestMetadata object that overrides global VASRequestMetadata for the VASNativeAdFactory ad requests.
 */
@property (nullable) VASRequestMetadata *requestMetadata;

/**
 Gets or sets the cache replenishment threshold override for this instance of the factory, which will then be used instead
 of SDK configuration or the default value. If the resulting cache size after an ad is loaded from the cache is less than or equal
 to this value the factory will attempt to replenish the cache. Must be a non-negative integer. Max value is 30.
 */
@property NSUInteger cacheReplenishmentThresholdOverride;

@end

NS_ASSUME_NONNULL_END
