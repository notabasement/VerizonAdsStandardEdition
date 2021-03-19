///
/// @internal
/// @file
/// @brief NSLock category extensions.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSLock (VASAds)
- (void)vas_lockWithBlock:(void(^)(void))block;
@end

@interface NSRecursiveLock (VASAds)
- (void)vas_lockWithBlock:(void(^)(void))block;
@end

NS_ASSUME_NONNULL_END
