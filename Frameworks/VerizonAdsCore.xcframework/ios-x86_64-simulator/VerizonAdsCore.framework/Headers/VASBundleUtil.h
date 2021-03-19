///
/// @file
/// @brief Definitions for VASBundleUtil.
///
/// @copyright Copyright (c) 2020 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Utility for loading a resource bundle from a file that was added to an application that we're linked with.
 This may be useful in other contexts, but it's particularly important for Static Frameworks trying to load their associated resource bundles. In this case, resource bundles will be embedded as a resource of the application, so there is some additional logic required to locate a resource bundle by file name reference and load it as a bundle.
 */
@interface VASBundleUtil : NSObject

/// @cond
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

/**
 Return a resource bundle by locating the bundle as a resource (by file name) and then loading it as a bundle.
 Note that this searches in the bundle for the class, then the root of the main application, and then any frameworks attached. Searching in attached frameworks is important for environments like Unity where all vendor libraries and resources are loaded at run-time from their embedded UnityFramework.framework (which is a Dynamic Framework).
 @param name the resource bundle name (without the `.bundle` file name extension).
 @param aClass the class calling this helper (so we can search the class bundle).
 @return a resource bundle or `nil` if the bundle was not found or was unable to load.
 */
+ (nullable NSBundle *)bundleForResource:(NSString *)name
                                forClass:(Class)aClass;

@end

NS_ASSUME_NONNULL_END
