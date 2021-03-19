///
///  @file
///  @brief Definitions for VASNativeComponent.
///
///  @copyright Copyright (c) 2019 Verizon. All rights reserved.
///

#import <UIKit/UIKit.h>
#import <VerizonAdsCore/VASComponent.h>
#import <VerizonAdsSupport/VASFileStorageCache.h>

NS_ASSUME_NONNULL_BEGIN

/**
 All Native components must conform to this protocol for accessing native components.
 */
@protocol VASNativeComponent <VASComponent>

/// The type of the component.
@property (readonly) NSString *type;

/**
 When called, a component should queue all files for download that it requires using the passed VASFileStorageCache and calling queueFileForDownload. The parent component will then initiate the download of collected files.
 
 Always executed on a background queue.
 
 @param fileCache   File cache for loading files.
 */
- (void)queueFilesForDownloadWithCache:(VASFileStorageCache *)fileCache;

/**
 Provides the value of the specified style attribute if available. The default value is returned if the style attribute is not specified.
 
 @param attributeName the name of the style attribute
 @param defaultValue the default value to use if the style attribute is not specified
 @return the style attribute value or the default value provided
 */
- (nullable id)styleAttributeValueForName:(NSString *)attributeName defaultValue:(nullable id)defaultValue;

/**
 Applies the style attributes of this component to the provided View instance.
 
 @param view the view to style
 @param defaultStyle  a map of style attributes to apply to the specified View if the ad did not specify a style for this component
 */
- (void)applyStyleToView:(UIView *)view defaultStyle:(nullable NSDictionary<NSString *, id> *)defaultStyle;

/**
 Apply the specified style to the View for this component, overriding any style attributes defined by the ad.
 
 @param style a map of style attributes to apply to the specified view
 @param view the view to style
 */
- (void)overrideStyle:(NSDictionary<NSString *, id> *)style forView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
