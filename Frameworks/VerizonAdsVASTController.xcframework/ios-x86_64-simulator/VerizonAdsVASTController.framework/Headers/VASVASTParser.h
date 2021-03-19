///
/// @file
/// @internal
/// @brief Definition for the VASVASTParser.
///
/// @copyright Copyright (c) 2018 Verizon. All rights reserved.
///

#import <Foundation/Foundation.h>
#import <VerizonAdsCore/VerizonAdsCore.h>
#import "VASVASTModel.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const kVASVASTParserErrorDomain;

typedef NS_ENUM(NSInteger, VASVASTParserErrorCode) {
    VASVASTParserErrorNoData = 1,
    VASVASTParserErrorIncompleteData,
    VASVASTParserErrorXMLParse,
    VASVASTParserErrorVASTRequest,
    VASVASTParserErrorOverThreeWrappers
};

@interface VASVASTParser : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithVASAds:(VASAds *)vasAds NS_DESIGNATED_INITIALIZER;
- (void)parseWithData:(NSData *)vastData completion:(void (^)(VASVASTModel * _Nullable, VASErrorInfo * _Nullable))block;
- (void)parseWithURL:(NSURL *)url completion:(void (^)(VASVASTModel *, VASErrorInfo *))block;
+ (NSTimeInterval)timeIntervalFromString:(NSString *)timeString;

@end

NS_ASSUME_NONNULL_END
