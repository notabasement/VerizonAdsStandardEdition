// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "VerizonAdsStandardEdition",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "VerizonAdsStandardEdition",
            targets: [
                "VerizonAdsOMSDK",
                "VerizonAdsVideoPlayer",
                "VerizonAdsCore",
                "VerizonAdsURIExperience",
                "VerizonAdsWebController",
                "VerizonAdsInlinePlacement",
                "VerizonAdsSupport",
                "VerizonAdsVerizonNativeController",
                "VerizonAdsInterstitialPlacement",
                "VerizonAdsWebView",
                "VerizonAdsStandardEdition",
                "VerizonAdsNativeVerizonNativeAdapter",
                "VerizonAdsInterstitialVASTAdapter",
                "VerizonAdsInlineWebAdapter",
                "VerizonAdsInterstitialWebAdapter",
                "VerizonAdsNativePlacement",
                "VerizonAdsVASTController"
            ]
        ),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(name: "VerizonAdsCore", path: "Frameworks/VerizonAdsCore.xcframework"),
        .binaryTarget(name: "VerizonAdsOMSDK", path: "Frameworks/VerizonAdsOMSDK.xcframework"),
        .binaryTarget(name: "VerizonAdsVideoPlayer", path: "Frameworks/VerizonAdsVideoPlayer.xcframework"),
        .binaryTarget(name: "VerizonAdsURIExperience", path: "Frameworks/VerizonAdsURIExperience.xcframework"),
        .binaryTarget(name: "VerizonAdsWebController", path: "Frameworks/VerizonAdsWebController.xcframework"),
        .binaryTarget(name: "VerizonAdsInlinePlacement", path: "Frameworks/VerizonAdsInlinePlacement.xcframework"),
        .binaryTarget(name: "VerizonAdsSupport", path: "Frameworks/VerizonAdsSupport.xcframework"),
        .binaryTarget(name: "VerizonAdsVerizonNativeController", path: "Frameworks/VerizonAdsVerizonNativeController.xcframework"),
        .binaryTarget(name: "VerizonAdsInterstitialPlacement", path: "Frameworks/VerizonAdsInterstitialPlacement.xcframework"),
        .binaryTarget(name: "VerizonAdsWebView", path: "Frameworks/VerizonAdsWebView.xcframework"),
        .binaryTarget(name: "VerizonAdsStandardEdition", path: "Frameworks/VerizonAdsStandardEdition.xcframework"),
        .binaryTarget(name: "VerizonAdsNativeVerizonNativeAdapter", path: "Frameworks/VerizonAdsNativeVerizonNativeAdapter.xcframework"),
        .binaryTarget(name: "VerizonAdsInterstitialVASTAdapter", path: "Frameworks/VerizonAdsInterstitialVASTAdapter.xcframework"),
        .binaryTarget(name: "VerizonAdsInlineWebAdapter", path: "Frameworks/VerizonAdsInlineWebAdapter.xcframework"),
        .binaryTarget(name: "VerizonAdsInterstitialWebAdapter", path: "Frameworks/VerizonAdsInterstitialWebAdapter.xcframework"),
        .binaryTarget(name: "VerizonAdsNativePlacement", path: "Frameworks/VerizonAdsNativePlacement.xcframework"),
        .binaryTarget(name: "VerizonAdsVASTController", path: "Frameworks/VerizonAdsVASTController.xcframework")
    ]
)
