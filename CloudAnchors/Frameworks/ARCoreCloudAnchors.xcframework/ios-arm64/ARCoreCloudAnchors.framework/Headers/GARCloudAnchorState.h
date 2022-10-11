/*
 * Copyright 2020 Google LLC. All Rights Reserved.
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

#import <Foundation/Foundation.h>

/** Possible values of GARAnchor.cloudState. */
typedef NS_ENUM(NSInteger, GARCloudAnchorState) {
  /** This anchor is not a Cloud Anchor. */
  GARCloudAnchorStateNone = 0,

  /** This anchor has started the process of hosting or resolving, but it is not complete. */
  GARCloudAnchorStateTaskInProgress = 1,

  /**
   * This anchor has been hosted or has resolved successfully. The cloudIdentifier property should
   * now be valid.
   */
  GARCloudAnchorStateSuccess = 2,

  /** Internal error. No recommended mitigation. */
  GARCloudAnchorStateErrorInternal = -1,

  /**
   * The operation failed due to an authentication or authorization error. This may occur due to a
   * number of reasons:
   * - The Google Cloud project may not have enabled the ARCore API.
   * - If the session was created with an API Key, the API Key may be invalid or deleted, or
   *   restricted to exclude the app's bundle Id.
   * - If the session was not created with an API Key, a token may not have been provided, or the
   *   provided token may be invalid.
   * - The requested operation may not be permitted.
   */
  GARCloudAnchorStateErrorNotAuthorized = -2,

  /**
   * The ARCore Cloud Anchor service was unreachable. This can happen because of a number of
   * reasons. A request sent to the server could have timed out with no response, there could be a
   * bad network connection, DNS unavailability, firewall issues, or anything that could affect the
   * device's ability to connect to the ARCore Cloud Anchor service.
   * @deprecated This error will no longer occur in ARCore SDK 1.12 or later. For hosted anchors,
   * the new ErrorHostingServiceUnavailable state will be used instead.
   */
  GARCloudAnchorStateErrorServiceUnavailable
      __attribute__((deprecated("Deprecated in ARCore SDK 1.12. "
                                "See the CHANGELOG to learn more."))) = -3,

  /**
   * The application has exhausted the request quota allotted to its **Google Cloud** project. The
   * developer should request additional quota for the project from the **Google Developers
   * Console**.
   */
  GARCloudAnchorStateErrorResourceExhausted = -4,

  /**
   * Hosting failed, because the server could not successfully process the dataset for the given
   * anchor. The developer should try again after the device has gathered more data from the
   * environment.
   */
  GARCloudAnchorStateErrorHostingDatasetProcessingFailed = -5,

  /**
   * Resolving failed, because the ARCore Cloud Anchor service could not find the provided cloud
   * anchor ID.
   */
  GARCloudAnchorStateErrorCloudIdNotFound = -6,

  /**
   * The server could not match the visual features provided by ARCore against the localization
   * dataset of the requested cloud anchor ID. This means that the anchor being requested was likely
   * not created in the user's surroundings.
   * @deprecated This error will no longer occur in ARCore SDK 1.12 or later.
   */
  GARCloudAnchorStateErrorResolvingLocalizationNoMatch
      __attribute__((deprecated("Deprecated in ARCore SDK 1.12. "
                                "See the CHANGELOG to learn more."))) = -7,

  /**
   * The anchor could not be resolved because the SDK used to host the anchor was newer than and
   * incompatible with this one.
   */
  GARCloudAnchorStateErrorResolvingSdkVersionTooOld = -8,

  /**
   * The anchor could not be resolved because the SDK used to host the anchor was older than and
   * incompatible with this one.
   */
  GARCloudAnchorStateErrorResolvingSdkVersionTooNew = -9,

  /**
   * The ARCore Cloud Anchor service was unreachable. This can happen because of a number of
   * reasons. For example, the device is in airplane mode or has no working network connection. A
   * request sent to the server could have timed out with no response, there could be a
   * bad network connection, DNS unavailability, firewall issues, or anything that could affect the
   * device's ability to connect to the ARCore Cloud Anchor service.
   */
  GARCloudAnchorStateErrorHostingServiceUnavailable = -10,
};
