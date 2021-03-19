///
/// @file
/// @brief Definitions for VASRuleComponent.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <VerizonAdsCore/VASComponent.h>

NS_ASSUME_NONNULL_BEGIN

/// Key for specifying the VASRuleFiredDelegate delegate in the component arguments. Stored within a VASWeakRef object to avoid retain cycles of the delegate.
extern NSString * const kVASRuleComponentDelegateRefKey;  // VASWeakRef<id<VASRuleFiredDelegate>>

@protocol VASRuleComponent;

#pragma mark - VASRuleFiredDelegate

/// Classes implementing the VASRuleFiredDelegate protocol will receive delegate callbacks from the associated VASRuleComponent objects as specified by the VASRuleComponent delegate property.
@protocol VASRuleFiredDelegate <NSObject>

/**
 Called by the rule component to notify the delegate of the firing. Called on an arbitrary background queue.
 @param rule    The VASRuleComponent responsible for firing.
 */
- (void)fireRuleEvent:(id<VASRuleComponent>)rule;

@end

#pragma mark - VASRuleComponent

/// The VASRuleComponent protocol provides extensions to the VASComponent protocol allowing for rule-based interactions as defined within the native ad JSON. Classes adopting this protocol must provide implementations for the properties and methods defined.
@protocol VASRuleComponent <VASComponent>

/// Indicates if the rule has been fired.
@property (readonly) BOOL hasFired;

/// Contains the event identifier for the rule.
@property (readonly) NSString *eventId;

/// Contains the event arguments for the rule.
@property (readonly, copy) NSDictionary<NSString *, id> *eventArgs;

/// Delegate to call when the rule fires.
@property (readonly, weak) id<VASRuleFiredDelegate> delegate;

/// Fires the rule if it has not already been fired. This method is automatically called by the rule when the criteria have been satisfied.
- (void)fire;

/// Resets the state of the rule.
- (void)reset;

@end

NS_ASSUME_NONNULL_END
