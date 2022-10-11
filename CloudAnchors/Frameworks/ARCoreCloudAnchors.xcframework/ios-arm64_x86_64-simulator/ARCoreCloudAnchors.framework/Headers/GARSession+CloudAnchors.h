/*
 * Copyright 2022 Google LLC. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <ARKit/ARKit.h>

#include <simd/simd.h>

#import <ARCoreGARSession/GARAnchor.h>
#import <ARCoreCloudAnchors/GARFeatureMapQuality.h>
#import <ARCoreGARSession/GARSession.h>

NS_ASSUME_NONNULL_BEGIN

/** Category adding Cloud Anchor functionality to GARSession. */
API_AVAILABLE(ios(11.0))
@interface GARSession (CloudAnchors)

/**
 * Hosts a new Cloud Anchor based on an `ARAnchor`.
 *
 * The new anchor will have a cloud state of GARCloudAnchorStateTaskInProgress and its initial
 * transform will be set to that of the passed-in anchor. However, the two transforms may differ
 * over time.
 *
 * @param anchor The `ARAnchor` to host.
 * @param error Out parameter for an `NSError`. Possible errors:
 *              GARSessionErrorCodeInvalidArgument - invalid (`nil`) anchor.
 *              GARSessionErrorCodeNotTracking - bad current ARTrackingState.
 *              GARSessionErrorCodeResourceExhausted - tried to create too many Cloud Anchors.
 *              GARSessionErrorCodeIllegalState - current cloud anchor mode is disabled.
 * @return The new GARAnchor, or `nil` if there is an error.
 */
- (nullable GARAnchor *)hostCloudAnchor:(ARAnchor *)anchor error:(NSError **)error;

/**
 * This will create a new Cloud Anchor with a given lifetime in days, using the transform of the
 * provided anchor.
 *
 * The cloud state of the returned anchor will be set to GARCloudAnchorStateTaskInProgress and the
 * initial transform will be set to the transform of the provided anchor. However, the returned
 * anchor is completely independent of the original anchor, and the two transforms might diverge
 * over time.
 *
 * Hosting requires an active session for which the tracking state is ARTrackingStateNormal, as well
 * as a working internet connection. ARCore will continue to retry silently in the background if it
 * is unable to establish a connection to the ARCore Cloud Anchor service.
 *
 * @param anchor The `ARAnchor` with the desired transform to be used to create a hosted Cloud
 *     Anchor.
 * @param TTLDays The lifetime of the anchor in days. Must be positive. The maximum allowed value is
 *     1 if using an API Key to authenticate with the ARCore Cloud Anchor service, otherwise the
 *     maximum allowed value is 365.
 * @param error Out parameter for an `NSError`. Possible errors:
 *     GARSessionErrorCodeInvalidArgument - invalid (`nil`) anchor or invalid TTL.
 *     GARSessionErrorCodeNotTracking - bad current ARTrackingState.
 *     GARSessionErrorCodeResourceExhausted - tried to create too many Cloud Anchors.
 *     GARSessionErrorCodeIllegalState - current cloud anchor mode is disabled.
 * @return The new GARAnchor, or `nil` if there is an error.
 */
- (nullable GARAnchor *)hostCloudAnchor:(ARAnchor *)anchor
                                TTLDays:(NSInteger)TTLDays
                                  error:(NSError **)error;

/**
 * Estimates the quality of the visual features seen by ARCore in the preceding few seconds and
 * visible from the provided camera transform. Cloud Anchors hosted using higher quality features
 * will generally result in easier and more accurately resolved Cloud Anchor transforms.
 *
 * @param transform The camera transform to use in estimating the quality.
 * @param error Out parameter for an `NSError`. Possible errors:
 *        GARSessionErrorCodeNotTracking - bad current ARTrackingState.
 *        GARSessionErrorCodeIllegalState - current cloud anchor mode is disabled.
 * @return The estimated quality of the visual features seen by ARCore in the preceding few seconds
 *         and visible from the provided camera transform.
 */
- (GARFeatureMapQuality)estimateFeatureMapQualityForHosting:(simd_float4x4)transform
                                                      error:(NSError **)error
    NS_SWIFT_NAME(estimateFeatureMapQualityForHosting(_:))
#if __has_attribute(swift_error)
    __attribute__((swift_error(nonnull_error)))
#endif
    ;

/**
 * Resolves a Cloud Anchor with a given identifier.
 * The new anchor is immediately added to the session and returned, but without a valid transform.
 * You don’t need to wait for a call to resolve a Cloud Anchor to complete before
 * initiating another call. A session can be resolving up to 20 Cloud Anchors at a given time.
 * If resolving fails, the anchor will be automatically removed from the session.
 *
 * @param identifier The Cloud Anchor identifier for the anchor.
 * @param error Out parameter for an `NSError`. Possible errors:
 *              GARSessionErrorCodeInvalidArgument - invalid (`nil` or empty) identifier.
 *              GARSessionErrorCodeResourceExhausted - tried to create too many Cloud Anchors.
 *              GARSessionErrorCodeIllegalState - current cloud anchor mode is disabled.
 * @return The new GARAnchor, or `nil` if there is an error.
 */
- (nullable GARAnchor *)resolveCloudAnchorWithIdentifier:(NSString *)identifier
                                                   error:(NSError **)error
    NS_SWIFT_NAME(resolveCloudAnchor(_:));

@end

NS_ASSUME_NONNULL_END
