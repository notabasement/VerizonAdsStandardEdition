///
/// @internal
/// @file
/// @brief Definitions for VASComponentRegistry
///
/// @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VASComponent.h>
#import <VerizonAdsCore/VASComponentFactory.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The Component Registry is used to register VASComponentFactory instances to component content types. The Component Registry is also used to create a VASComponent instance for a specified factory type.
 */
@interface VASComponentRegistry : NSObject

/**
 Registers the specified content type with the VASComponentFactory instance provided.
 
 @param factory The VASComponentFactory that creates instances of this content type.
 @param type    The component content type for this factory.
 @return YES if the VASComponentFactory object was successfully registered, NO if already registered or does not conform to the VASComponentFactory protocol.
 */
- (BOOL)registerComponentFactory:(id<VASComponentFactory>)factory forType:(NSString *)type;

/**
 Creates a new VASComponent instance for the specified content type.
 
 @param type            The component content type for this factory.
 @param componentInfo   The JSON data used to construct a new component of the class that implements this protocol.
 @param args            An optional dictionary of arguments that can be customized for each class implementing this protocol.
 @param vasAds          The VASAds instance being used.
 @return a new VASComponent for the VASComponentFactory if it is registered for the specified component type, otherwise nil.
 */
- (nullable id<VASComponent>)createComponentForType:(NSString *)type
                                      componentInfo:(NSDictionary<NSString *, id> *)componentInfo
                                               args:(nullable NSDictionary<NSString *, id> *)args
                                             VASAds:(VASAds *)vasAds;

@end

NS_ASSUME_NONNULL_END
