///
/// @file VASMacros.m
/// @brief Interface for VASMacros.
///
/// @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VASMacros : NSObject

/**
 A convenience method of `replaceExpression:withinSource:usingMacros:defaultValue:` that does not incorporate a default value.
 
 @param expression  The regex pattern string to use for replacement.
 @param source      The source string to scan for macros.
 @param macros      The map of macros with replacement values.
 @return the string with macros replaced
 */
+ (NSString *)replaceExpression:(NSRegularExpression *)expression
                   withinSource:(NSString *)source
                    usingMacros:(nullable NSDictionary<NSString *, NSString *> *)macros;

/**
 Replace all occurrences within the source string of the keys in the macros dictionary with each associated value. Uses the regex expression to identify the macros to replace. If no matching macro string is found in the replacement map then the macro is not replaced. If a corresponding replacement is not found, the defaultValue is used if provided.
 
 @param expression  The regex pattern string to use for replacement.
 @param source      The source string to scan for macros.
 @param macros      The map of macros with replacement values.
 @param defaultValue    The replacement value for all matches that do not contain a match in the macros map; otherwise null to indicate that the macro should not be replaced if a match is not found in the macros map.
 @return the string with macros replaced
 */
+ (NSString *)replaceExpression:(NSRegularExpression *)expression
                   withinSource:(NSString *)source
                    usingMacros:(nullable NSDictionary<NSString *, NSString *> *)macros
                   defaultValue:(nullable NSString *)defaultValue;

@end

NS_ASSUME_NONNULL_END
