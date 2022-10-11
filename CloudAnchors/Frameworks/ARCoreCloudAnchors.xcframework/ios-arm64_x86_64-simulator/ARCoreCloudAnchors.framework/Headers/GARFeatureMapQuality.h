/*
 * Copyright 2018 Google LLC. All Rights Reserved.
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

/** Possible values returned by [GARSession estimateFeatureMapQualityForHosting:error:]. */
typedef NS_ENUM(NSInteger, GARFeatureMapQuality) {
  /**
   * The quality of feature points seen from the transform position in the preceding few seconds
   * is low. This state indicates that ARCore will likely have more difficulty resolving the Cloud
   * Anchor. Encourage the user to move the device, so that the desired position of the Cloud Anchor
   * to be hosted is seen from different angles.
   */
  GARFeatureMapQualityInsufficient = 0,

  /**
   * The quality of feature points seen from the transform position in the preceding few seconds
   * is likely sufficient for ARCore to successfully resolve a Cloud Anchor, although the accuracy
   * of the resolved transform will likely be reduced. Encourage the user to move the device, so
   * that the desired position of the Cloud Anchor to be hosted is seen from different angles.
   */
  GARFeatureMapQualitySufficient = 1,

  /**
   * The quality of feature points seen from the transform position in the preceding few seconds
   * is likely sufficient for ARCore to successfully resolve a Cloud Anchor with a high degree of
   * accuracy.
   */
  GARFeatureMapQualityGood = 2,
};
