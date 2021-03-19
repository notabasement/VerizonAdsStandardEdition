///
/// @file
/// @brief Definitions for VASWaterfallProvider.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VASErrorInfo.h>
#import <VerizonAdsCore/VASRequestMetadata.h>
#import <VerizonAdsCore/VASWaterfall.h>
#import <VerizonAdsCore/VASComponent.h>

NS_ASSUME_NONNULL_BEGIN

@class VASAds;
@class VASBid;

/// Completion handler called when a waterfall load request has completed. If the adSessions array is nil, then `errorInfo` should report the reason for the failure.
typedef void (^VASWaterfallRequestCompletionHandler)(NSArray<VASAdSession *> * _Nullable adSessions, VASErrorInfo * _Nullable errorInfo);

/// Completion handler called when a waterfall bid request has completed. A `bid` will be returned, or an `error` will report the reason for the failure.
typedef void (^VASBidRequestCompletionHandler)(VASBid * _Nullable bid, VASErrorInfo * _Nullable errorInfo);

/**
 An abstract class for loading waterfalls. This must be subclassed to use.
 */
@interface VASWaterfallProvider : NSObject <VASComponent>

/// The VASAds object to use.
@property (readonly) VASAds *vasAds;

/**
 @param vasAds The VASAds instance making the call; dependency injection.
 @return instance of this class.
 */
- (instancetype)initWithVASAds:(VASAds *)vasAds NS_DESIGNATED_INITIALIZER;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

/**
Use this method to retrieve a bidding token.

@param requestMetadata The request metadata that will be used as part of the bidding token.
@return The bidding token or `nil` if the waterfall provider doesn't support bidding.
*/
- (nullable NSString *)biddingTokenUsingMetadata:(nullable VASRequestMetadata *)requestMetadata;

/**
 Called by the SDK core to load waterfalls.
 Calling the base class [super] implementation will call the specified completion method with a nil VASAdSession and an `VASErrorNotImplemented` error.

 @param requestMetadata  Metadata to consider when making the playlist request.
 @param timeout          Represents the total time available for a high level ads request, and not for individual calls to this waterfall provider. So the time available for this call will be less, but provides a general timeout after which no more waterfalls will be accepted and further waterfall loading can be discontinued.
 @param waterfallHandler A block that the waterfall provider must call when all waterfalls for a single load request have been loaded.
 */
- (void)loadWaterfallsUsingRequestMetadata:(VASRequestMetadata *)requestMetadata
                                   withTimeout:(NSTimeInterval)timeout
                          waterfallHandler:(VASWaterfallRequestCompletionHandler)waterfallHandler;

/**
 This method must return NO if the WaterfallProvider implementation does not implement both optional selectors requestBidUsingRequestMetadata:withTimeout:completion: and loadWaterfallUsingBid:withTimeout:waterfallHandler:.
 
 @return returns YES if super auction methods are supported; NO otherwise.
 */
- (BOOL)isSuperAuctionSupported;

/**
 Retrieve a bid using this waterfall provider. Subclasses should not override this method if bids are not supported by the provider and `isSuperAuctionSupported` returns NO.
 Calling the base class [super] implementation will call the specified completion method with a nil bid and an `VASErrorNotImplemented` error.
 @param requestMetadata Metadata to consider when making the bid request.
 @param timeout         The `NSTimeInterval` seconds the caller is willing to wait for a bid. Note that this represents the total time available for a high level bid request, and not for this individual call to this waterfall provider. So the time available for this call will be less, but provides a general timeout guideline after which the `completion` callback will be ignored.
 @param completion      Block that the waterfall provider must call upon bid load completion. Subclasses should call `completion` on an arbitrary background queue.
 */
- (void)requestBidUsingRequestMetadata:(VASRequestMetadata *)requestMetadata
                     withTimeout:(NSTimeInterval)timeout
                      completion:(VASBidRequestCompletionHandler)completion;

/**
 This method will load a single VASAdSession containing a waterfall, kVASResponseWaterfallKey, based on the provided bid if still valid and available. Subclasses should not override this method if bids are not supported by the provider and `isSuperAuctionSupported` returns NO.
 Calling the base class [super] implementation will call the specified completion method with a nil ad and an `VASErrorNotImplemented` error.
 
 @param bid The `VASBid` to use to attempt to retrieve a waterfall.
 @param timeout The `NSTimeInterval` seconds the caller is willing to wait for an ad. Note that this represents the total time available for a high level ads request, and not for this individual call to this waterfall provider. So the time available for this call will be less, but provides a general timeout guideline after which the `completion` callback will be ignored.
 @param handler Block that the waterfall provider must call upon ad load completion. Subclasses should call `handler` on an arbitrary background queue.
 */
- (void)loadWaterfallUsingBid:(VASBid *)bid
                  withTimeout:(NSTimeInterval)timeout
             waterfallHandler:(VASWaterfallRequestCompletionHandler)handler;

@end

NS_ASSUME_NONNULL_END
