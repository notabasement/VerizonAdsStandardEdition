///
/// @file
/// @brief Private definitions of VASSupport VASClickEvent.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VASClickEvent.h>

NS_ASSUME_NONNULL_BEGIN

/// Internal accessors to the VASClickEvent class.
@interface VASClickEvent (Internal)

/**
 @param adSession   The VASAdSession object associated with the event.
 @return an instance of this class.
 */
- (instancetype)initWithAdSession:(VASAdSession *)adSession;

@end

NS_ASSUME_NONNULL_END
