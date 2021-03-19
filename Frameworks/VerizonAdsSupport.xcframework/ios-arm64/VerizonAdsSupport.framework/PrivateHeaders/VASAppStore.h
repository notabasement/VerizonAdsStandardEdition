///
/// @internal
/// @file
/// @brief Definitions for VASAppStore
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class VASAds;
@class VASEnvironmentInfo;

typedef void (^VASAppStorePresentedHandler)(BOOL presentSuccess, BOOL loadSuccess, BOOL adContentDidLeaveApplication, NSError * _Nullable error);

// NOTE: We should consider refactoring this class to use a delegate to provide more specific callbacks for each different type of status because the current design presupposes the user (of this class) to have too much knowledge about internal details such as whether the open ultimately happened using the StoreKit or by way of an external browser open URL. As a result, the pattern for implementing the callbacks is a little more confusing than it should be - and is indirectly dependent on the internal behavior and logic in the open call.

@interface VASAppStore : NSObject

+ (nullable NSString *)storeItemIdentifierForURL:(NSURL *)url;

- (instancetype)initWithVASAds:(VASAds *)vasAds NS_DESIGNATED_INITIALIZER;

/**
 Opens the app store using the StoreKit or by URL depending on orientation.
 <br/>
 Notes: The `presentedHandler` may be called back with `presentedSuccess` of YES at any time - this may be used to notify a delegate of the modal presentation.  The handler may be called back with `loadSuccess` of YES once the StoreKit viewController has sucessfully loaded - this may be used together with `presentedSuccess` to determine successful handling of a StoreKit URI. The sequence is as follows: a callback with `presentedSuccess` YES, loadSuccess `NO` means the StoreKit VC has been presented; a callback with `presentedSuccess` NO and `loadSuccess` YES means the VC may still be in process of presenting; final success is a callback with both values YES, final failure is a callback with both values NO.  The `dismissCompletion` callback is called only after `presentedHandler` with both a `success` of `YES` and an `adContentDidLeaveApplication` of `NO`. In other words, it only calls this when a successful open happened using the StoreKit and not if an error occurred or if it was opened using an external browser in landscape mode. You must be careful to handle any errors received by `presentedHandler` and do any relevant cleanup there as well, in combination with any relevant modal cleanup done in the `dismissCompletion` callback. For an example of this, see the implementation in the `openAppStoreForAppId` method of VASMRAIDWebView or VASURIExperience.
 <br/>
 Also note that `presentedHandler` and `dismissCompletion` may be called on an arbitrary thread.
 */
- (void)openAppStoreForAppId:(NSString *)appId
                 affiliateId:(nullable NSString *)affiliateId
                  campaignId:(nullable NSString *)campaignId
         usingViewController:(UIViewController *)presentingVC
             transitionStyle:(UIModalTransitionStyle)transitionStyle
        withPresentedHandler:(VASAppStorePresentedHandler)presentedHandler
           dismissCompletion:(void(^)(void))dismissCompletion;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
