///
/// @internal
/// @file
/// @brief VASPostEventExperience
///
/// @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - VASPostEventExperience

/**
 A class containing a structured representation of the Post Event Experience (PEX) information delivered with a placement.
 */
@interface VASPostEventExperience : NSObject

/// This is the identifier of the specific PEX instance that is specified within the definition for an event action.  It allows for distinguishing between multiple instances of a single PEX content type.
@property (readonly) NSString *pexId;

/// Content type that is used as the key when registering and looking up a PEX factory. Expected form: "experience/<PEX Type>"
@property (readonly) NSString *contentType;

/// Indicates whether the PEX data should be cached as part of loading the creative.
@property (readonly) BOOL cacheable;

/// Indicates whether the PEX data should be exposed as part of sterilized JSON for the ad.
@property (readonly) BOOL secret;

/// PEX data to be handed to the experience after lookup from the registry.
@property (readonly, nullable) NSDictionary<NSString *, id> *data;

/**
 Create an instance of this class using the passed parameters.
 
 @param pexId       Identifier of this PEX.
 @param contentType Content this PEX supports.
 @param cacheable   Whether the handler will be expected to cache during resource loading.
 @param secret      If this data should be removed from the sterilized JSON for the ad.
 @param data        Optional PEX data passed along to the handler.
 @return an instance of this PEX representation.
 */
- (instancetype)initWithId:(NSString *)pexId
               contentType:(NSString *)contentType
                 cacheable:(BOOL)cacheable
                    secret:(BOOL)secret
                      data:(nullable NSDictionary<NSString *, id> *)data;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
