// swift-tools-version: 5.5

import PackageDescription

let package = Package(
  name: "ARCore",
  platforms: [
    .iOS(.v11)
  ],
  products: [
    .library(name: "ARCoreBase", targets: ["Base"]),
    .library(name: "ARCoreGARSession", targets: ["GARSession"]),
    .library(name: "ARCoreCloudAnchors", targets: ["CloudAnchors"]),
    .library(name: "ARCoreGeospatial", targets: ["Geospatial"]),
    .library(name: "ARCoreAugmentedFaces", targets: ["AugmentedFaces"]),
  ],
  dependencies: [
    .package(
      url: "https://github.com/firebase/firebase-ios-sdk.git", "8.0.0"..<"10.0.0"),
    .package(
      url: "https://github.com/google/GoogleDataTransport.git", .upToNextMajor(from: "9.1.4")),
    .package(
      url: "https://github.com/google/gtm-session-fetcher.git", .upToNextMajor(from: "2.0.0")),
    .package(
      url: "https://github.com/firebase/nanopb.git",
      "2.30909.0"..<"2.30910.0"
    ),
  ],
  targets: [
    .binaryTarget(
      name: "ARCoreBase",
      path: "Base/Frameworks/ARCoreBase.xcframework"
    ),
    .target(
      name: "Base",
      dependencies: [
        "ARCoreBase",
        .product(name: "GoogleDataTransport", package: "GoogleDataTransport"),
        .product(name: "nanopb", package: "nanopb"),
      ],
      path: "Base",
      sources: ["dummy.m"],
      publicHeadersPath: "Sources"
    ),
    .binaryTarget(
      name: "ARCoreGARSession",
      path: "GARSession/Frameworks/ARCoreGARSession.xcframework"
    ),
    .target(
      name: "GARSession",
      dependencies: [
        "ARCoreGARSession",
        "Base",
        .product(name: "FirebaseRemoteConfig", package: "firebase-ios-sdk"),
        .product(name: "GoogleDataTransport", package: "GoogleDataTransport"),
        .product(name: "nanopb", package: "nanopb"),
      ],
      path: "GARSession",
      sources: ["dummy.m"],
      resources: [
        .copy("Resources/ARCoreResources")
      ],
      publicHeadersPath: "Sources"
    ),
    .binaryTarget(
      name: "ARCoreCloudAnchors",
      path: "CloudAnchors/Frameworks/ARCoreCloudAnchors.xcframework"
    ),
    .target(
      name: "CloudAnchors",
      dependencies: [
        "ARCoreCloudAnchors",
        "GARSession",
        .product(name: "GTMSessionFetcherCore", package: "gtm-session-fetcher"),
        .product(name: "nanopb", package: "nanopb"),
      ],
      path: "CloudAnchors",
      sources: ["dummy.m"],
      publicHeadersPath: "Sources"
    ),
    .binaryTarget(
      name: "ARCoreGeospatial",
      path: "Geospatial/Frameworks/ARCoreGeospatial.xcframework"
    ),
    .target(
      name: "Geospatial",
      dependencies: [
        "ARCoreGeospatial",
        "GARSession",
      ],
      path: "Geospatial",
      sources: ["dummy.m"],
      publicHeadersPath: "Sources"
    ),
    .binaryTarget(
      name: "ARCoreAugmentedFaces",
      path: "AugmentedFaces/Frameworks/ARCoreAugmentedFaces.xcframework"
    ),
    .target(
      name: "AugmentedFaces",
      dependencies: [
        "ARCoreAugmentedFaces",
        "Base",
        .product(name: "GoogleDataTransport", package: "GoogleDataTransport"),
        .product(name: "nanopb", package: "nanopb"),
      ],
      path: "AugmentedFaces",
      sources: ["dummy.m"],
      resources: [
        .copy("Resources/ARCoreFaceResources")
      ],
      publicHeadersPath: "Sources"
    ),
  ]
)
