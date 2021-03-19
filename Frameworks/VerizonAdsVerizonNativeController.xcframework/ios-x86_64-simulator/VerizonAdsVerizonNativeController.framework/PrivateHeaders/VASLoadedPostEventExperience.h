///
/// @internal
/// @file
/// @brief VASLoadedPostEventExperience
///
/// @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VASPostEventExperience.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VASPEXHandlerDelegate;

/**
 Represents a loaded VASPostEventExperience instance and its associated PEX handler available from the core PEXRegistry lookup.
 */
@interface VASLoadedPostEventExperience : NSObject

/// The VASPostEventExperience for the specified PEX id.
@property (readonly) VASPostEventExperience *experience;

/// The PEX handler used to execute actions and provide caching support.
@property (readonly) id<VASPEXHandlerDelegate> handler;

/**
 Create an instance of this class containing the two corresponding elements.
 
 @param experience  The VASPostEventExperience
 @param handler     The VASPEXHandlerDelegate associated with the experience.
 @return an instance of this class.
 */
- (instancetype)initWithExperience:(VASPostEventExperience *)experience
                           handler:(id<VASPEXHandlerDelegate>)handler;

@end

NS_ASSUME_NONNULL_END
