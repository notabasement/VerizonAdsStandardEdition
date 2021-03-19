///
///  @file
///  @brief Definitions for VASInlineAdFactory.
///
///  @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>
#import <VerizonAdsCore/VerizonAdsCore.h>
#import <VerizonAdsSupport/VerizonAdsSupport.h>
#import "VASInlineAdView.h"
#import "VASInlineAdSize.h"

NS_ASSUME_NONNULL_BEGIN

/// VASInlineAdFactory error domain.
FOUNDATION_EXPORT NSErrorDomain const kVASInlineAdFactoryErrorDomain;

/// Error codes that are used in the VASInlineAdFactory error domain.
typedef NS_ENUM(NSInteger, VASInlineAdFactoryError) {
    /// An ad load is already in progress.
    VASInlineAdFactoryErrorAdLoadInProgress = 1,
    /// The ad adapter view failed.
    VASInlineAdFactoryErrorNilAdView,
    /// A VASAdSession is missing its adapter.
    VASInlineAdFactoryErrorMissingAdAdapter
};

/// The key for the placement id found within placementData in the VASRequestMetadata.
FOUNDATION_EXPORT NSString * const kVASRequestMetadataInlineAdPlacementIdKey;       // NSString

/// The key for the placement type found within placementData in the VASRequestMetadata.
FOUNDATION_EXPORT NSString * const kVASRequestMetadataInlineAdPlacementTypeKey;     // NSString

/// VASRequestMetadata key for an array of dictionaries of ad sizes ("width"/"height")
FOUNDATION_EXPORT NSString * const kVASRequestMetadataInlineAdPlacementAdSizesKey;  // NSArray<NSDictionary<NSString,NSNumber>>

/// Width key for an ad size dict
FOUNDATION_EXPORT NSString * const kVASRequestMetadataInlineAdPlacementAdSizeWidthKey;

/// Height key for an ad size dict
FOUNDATION_EXPORT NSString * const kVASRequestMetadataInlineAdPlacementAdSizeHeightKey;

@class VASInlineAdFactory;

/**
 Protocol for receiving notifications from the VASInlineAdFactory.
 */
@protocol VASInlineAdFactoryDelegate <NSObject>

/**
 Called when the VASInlineAdView has been loaded. A new VASInlineAdView instance will be provided as part of this callback.
 
 @param adFactory The calling VASInlineAdFactory.
 @param inlineAd  The VASInlineAdView object that is ready to be displayed.
 */
- (void)inlineAdFactory:(VASInlineAdFactory *)adFactory didLoadInlineAd:(VASInlineAdView *)inlineAd;

/**
 Called when there is an error requesting a VASInlineAdView or loading a VASInlineAdView from the cache.
 
 @param adFactory The calling VASInlineAdFactory.
 @param errorInfo A VASErrorInfo object containing details about the error.
 */
- (void)inlineAdFactory:(VASInlineAdFactory *)adFactory didFailWithError:(VASErrorInfo *)errorInfo;

@end

/**
 VASInlineAdFactory is a factory class that handles loading and caching of VASInlineAdView placements. It uses the VASInlineAdFactoryDelegate protocol to provide notifications about VASInlineAdView creation.
 */
@interface VASInlineAdFactory : NSObject

/**
 Initialize a VASInlineAdFactory for creating VASInlineAdView objects. Use this to set the placementId and listener for VASInlineAdView that the VASInlineAdFactory will create.
 
 @param placementId     The placementId that will be set for all VASInlineAdView that the VASInlineAdFactory creates.
 @param adSizes         The ad sizes supported by the inline placement (size is specified in dips).
 @param vasAds          The VASAds instance for this object to use.
 @param delegate        The VASInlineAdFactoryDelegate that will receive ad factory events for the VASInlineAdFactory.
 @return An initialized instance of this class.
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                            adSizes:(NSArray<VASInlineAdSize *> *)adSizes
                             vasAds:(VASAds *)vasAds
                           delegate:(nullable id <VASInlineAdFactoryDelegate>)delegate NS_DESIGNATED_INITIALIZER;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

/**
 Requests a new VASInlineAdView.
 
 @param inlineAdDelegate The VASInlineAdViewDelegate that will receive ad events for the  VASInlineAdView.
 */
- (void)load:(id <VASInlineAdViewDelegate>)inlineAdDelegate;

/**
 Attempts to load a VASInlineAd from the cache.  If the cache is empty, nil is returned. This method
 performs UIView activity and therefore must be called from the main thread. If called outside the
 main thread, nil will be returned.
 
 @param inlineAdDelegate The VASInlineAdViewDelegate that will receive ad events for the VASInlineAdView.
 @return                 A VASInlineAdView from the cache or nil if the cache is empty or if the call is not made on the main thread.
 */
- (nullable VASInlineAdView *)loadAdFromCache:(id <VASInlineAdViewDelegate>)inlineAdDelegate /* @cond */ NS_SWIFT_NAME(loadAdFromCache(_:)) /* @endcond */;

/**
 Loads the VASInlineAdView for the provided bid.
 
 @param bid              The Bid that will be loaded.
 @param inlineAdDelegate The VASInlineAdViewDelegate that will receive ad events for the VASInlineAdView.
 */
- (void)loadBid:(VASBid *)bid inlineAdDelegate:(id<VASInlineAdViewDelegate>)inlineAdDelegate;

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
 
 @param placementId     The placementId that will be set for all VASInlineAdView that the VASInlineAdFactory creates.
 @param adSizes         The ad sizes that are supported by the VASInlineAdView that the VASInlineAdFactory creates.
 @param requestMetadata The VASRequestMetadata to use for ad requests.
 @param vasAds          The VASAds instance for this object to use.
 @param handler         The completion handler that will receive the bid request result.
 */
+ (void)requestBidForPlacementId:(NSString *)placementId
                         adSizes:(NSArray<VASInlineAdSize *> *)adSizes
                 requestMetadata:(nullable VASRequestMetadata *)requestMetadata
                          vasAds:(VASAds *)vasAds
                      completion:(VASBidRequestCompletionHandler)handler;

/**
 Returns the ad sizes supported by this ad factory.
 */
@property (readonly, copy) NSArray<VASInlineAdSize *> *adSizes;

/**
 Get the placementId for the VASInlineAdFactory.
 */
@property (readonly, copy) NSString *placementId;

/**
 Gets or sets the cache replenishment threshold override for this instance of the factory, which will then be used instead
 of SDK configuration or the default value. If the resulting cache size after an ad is loaded from the cache is less than or equal
 to this value the factory will attempt to replenish the cache. Must be a non-negative integer. Max value is 30.
 */
@property NSUInteger cacheReplenishmentThresholdOverride;

/**
 The VASRequestMetadata object that overrides global VASRequestMetadata for the VASInlineAdFactory ad requests.
 */
@property (nullable) VASRequestMetadata *requestMetadata;

/**
 The object implementing the VASInlineAdFactoryDelegate protocol, to receive ad factory event callbacks.
 */
@property (nonatomic, weak, nullable) id <VASInlineAdFactoryDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
