///
/// @internal
/// @file
/// @brief Definitions for VASWeakRef.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Wrapper container object for a weak reference to allow storage within VASDataStore or any other collection class object (NSDictionary, NSArray, ...)
@interface VASWeakRef<__covariant ObjectType> : NSObject

/// A weak reference to an arbitrary NSObject. Will be nil once the object is released.
@property (readonly, weak, nullable) ObjectType object;

/**
Create an instance of the wrapper object containing the actual object to be weakly-referenced.

@param object   NSObject to be weakly stored.
@return an instance of the container.
*/
- (VASWeakRef<ObjectType> *)initWithObject:(ObjectType)object NS_DESIGNATED_INITIALIZER;

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
