///
/// @file
/// @brief VASCore
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <UIKit/UIKit.h>

/// Project version number for VASCore.
FOUNDATION_EXPORT double VASCoreVersionNumber;

/// Project version string for VASCore.
FOUNDATION_EXPORT const unsigned char VASCoreVersionString[];

// All public headers of VASCore.

#import <VerizonAdsCore/VASAds.h>
#import <VerizonAdsCore/VASRequestMetadataKeys.h>
#import <VerizonAdsCore/VASRequestMetadataBuilder.h>
#import <VerizonAdsCore/VASRequestMetadata.h>
#import <VerizonAdsCore/VASBid.h>
#import <VerizonAdsCore/VASPlugin.h>
#import <VerizonAdsCore/VASEvents.h>
#import <VerizonAdsCore/VASWaterfallProvider.h>
#import <VerizonAdsCore/VASAdAdapter.h>
#import <VerizonAdsCore/VASContentFilter.h>
#import <VerizonAdsCore/VASDataStore.h>
#import <VerizonAdsCore/VASAdSession.h>
#import <VerizonAdsCore/VASAdSessionEvent.h>
#import <VerizonAdsCore/VASAdSessionChangeEvent.h>
#import <VerizonAdsCore/VASConfiguration.h>
#import <VerizonAdsCore/VASConfigurationProvider.h>
#import <VerizonAdsCore/VASEnvironmentInfo.h>
#import <VerizonAdsCore/VASSDKInfo.h>
#import <VerizonAdsCore/VASCreativeInfo.h>
#import <VerizonAdsCore/VASErrorInfo.h>
#import <VerizonAdsCore/VASLogLevel.h>
#import <VerizonAdsCore/VASLogger.h>
#import <VerizonAdsCore/VASBundleUtil.h>
#import <VerizonAdsCore/VASHTTPUtil.h>
#import <VerizonAdsCore/VASCoreErrors.h>
#import <VerizonAdsCore/VASAdAdapterRegistration.h>
#import <VerizonAdsCore/VASCoreConfigurationKeys.h>
#import <VerizonAdsCore/VASCoreEventTopics.h>
#import <VerizonAdsCore/VASWaterfallResult.h>
#import <VerizonAdsCore/VASWaterfallItemResult.h>
#import <VerizonAdsCore/VASAdContent.h>
#import <VerizonAdsCore/VASAdContentFetchResult.h>
#import <VerizonAdsCore/VASWaterfall.h>
#import <VerizonAdsCore/VASWaterfallItem.h>
#import <VerizonAdsCore/VASComponent.h>
#import <VerizonAdsCore/VASViewComponent.h>
#import <VerizonAdsCore/VASComponentFactory.h>
#import <VerizonAdsCore/VASRuleComponent.h>
#import <VerizonAdsCore/VASPrivacyKeys.h>
#import <VerizonAdsCore/VASVideoPlayer.h>
#import <VerizonAdsCore/VASCommon.h>
#import <VerizonAdsCore/VASClickEvent.h>
#import <VerizonAdsCore/VASImpressionEvent.h>
#import <VerizonAdsCore/VASVerizonSSPReporter.h>
#import <VerizonAdsCore/VASVerizonSSPConfigProvider.h>
#import <VerizonAdsCore/VASVerizonSSPConfigProviderErrors.h>
#import <VerizonAdsCore/VASVerizonSSPConfigProviderKeys.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallProvider.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallProviderErrors.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallProviderKeys.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallProviderRequestMetadataKeys.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallItemSuperAuction.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallDemandSourceProtocol.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallItem.h>
#import <VerizonAdsCore/VASVerizonSSPWaterfallItemMediation.h>
#import <VerizonAdsCore/VASSideloadingWaterfallProvider.h>
#import <VerizonAdsCore/VASSideloadingWaterfallProviderErrors.h>
#import <VerizonAdsCore/VASSideloadingWaterfallItem.h>
