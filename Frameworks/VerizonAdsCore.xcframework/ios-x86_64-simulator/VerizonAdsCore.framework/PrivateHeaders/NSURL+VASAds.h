///
/// @file
/// @brief Definitions for the NSURL (VASAds) category extension.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

@interface NSURL (VASAds)

/**
 Get a new URL by extending with a NString path and handling path separators properly.
 
 @return A URL representing the joined path.
 */
- (NSURL *)vas_URLByExtendingWithPath:(NSString *)path;

@end

