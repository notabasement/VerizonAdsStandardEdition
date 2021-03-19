///
/// @file
/// @brief VASPEXFactory
///
/// @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class VASErrorInfo;
@class VASAdSession;

#pragma mark - VASPEXHandlerDelegate

/// The event handler definition passed to the execute command.
typedef void (^VASPEXEventHandler)(NSString * _Nonnull eventType, NSDictionary<NSString *,id> * _Nonnull arguments);

/**
 All classes that handle post event experience execution must implement this interface.
 */
@protocol VASPEXHandlerDelegate <NSObject>

/**
 This method is called by the system to execute the post event experience. Implementors should start their experience when this method is called.
 It will be called on an arbitrary background queue.
 
 @param arguments                Execution specific arguments.
 @param presentingViewController A UIViewController capable of presenting another view controller to use when displaying a fullscreen experience. Passing nil will result in no fullscreen experience being displayed and an error returned to the ad.
 @param eventHandler             The instance MUST call this block to notify of events published by the handler. It is expected to be called on an arbitrary background queue.
 */
- (void)execute:(nullable NSDictionary<NSString *, id> *)arguments presentingViewController:(nullable UIViewController *)presentingViewController event:(VASPEXEventHandler)eventHandler;

/**
 This method is called by the system to allow the VASPEXHandlerDelegate handler instance to prepare itself using the PEX data sandbox. The handler MUST call the VASPEXHandlerDelegate completion callback when done.
 It will be called on an arbitrary background queue.
 
 @param data            The initialization data for the handler. This data is also passed to the VASPEXHandlerDelegate execute:arguments:event: method.
 @param cache           If YES the handler should perform any supported caching; if NO, it must not cache.
 @param adSession       The ad session representing this PEX handler.
 @param completion      The instance MUST call this block to notify of prepare (and optional cache) completion with a nil errorInfo indicating success, otherwise the error that occurred indicating preparation failed. It is expected to be called on an arbitrary background queue.
 */
- (void)prepare:(nullable NSDictionary<NSString *, id> *)data
          cache:(BOOL)cache
 usingAdSession:(VASAdSession *)adSession
 withCompletion:(void(^)(VASErrorInfo * _Nullable errorInfo))completion;

/**
 This method to called by the system to inform the VASPEXHandlerDelegate instance that it will no longer be used and may free any resources.
 */
- (void)releaseResources;

@end

#pragma mark - VASPEXFactory

/**
 An interface that must be implemented to register a class with the PEXRegistry for creating VASPEXHandlerDelegate instances.
 */
@protocol VASPEXFactory <NSObject>

/**
 Generate a VASPEXHandlerDelegate subclass instance for this factory.
 
 @return an instance of the PEX handler for the specified factory type.
 */
- (id<VASPEXHandlerDelegate>)createPEXHandler;

@end

NS_ASSUME_NONNULL_END
