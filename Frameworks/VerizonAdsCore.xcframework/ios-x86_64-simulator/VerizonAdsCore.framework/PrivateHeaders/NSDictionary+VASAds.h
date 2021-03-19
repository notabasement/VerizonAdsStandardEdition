///
/// @internal
/// @file
/// @brief Definition for NSDictionary (VASAds) category extension.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Common support extension utilities for NSDictionary.
 */
@interface NSDictionary (VASAds)

/**
 Recursively (deeply) prunes any empty keys and returns a new NSDictionary containing the pruned results. If the entire dictionary is completely empty, it will still return a single empty dictionary (and will not return nil).
 
 @return A pruned copy of the dictionary.
 */
- (NSDictionary *)vas_prune;

@end

NS_ASSUME_NONNULL_END
