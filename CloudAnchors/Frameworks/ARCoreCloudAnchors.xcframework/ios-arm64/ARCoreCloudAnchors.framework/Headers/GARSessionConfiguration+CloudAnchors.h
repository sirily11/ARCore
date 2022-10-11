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

#import <ARCoreCloudAnchors/GARCloudAnchorMode.h>
#import <ARCoreGARSession/GARSessionConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/** Category adding Cloud Anchor functionality to GARSessionConfiguration. */
@interface GARSessionConfiguration (CloudAnchors)

/**
 * The processing mode for Cloud Anchors. The default mode is |GARCloudAnchorModeDisabled|.
 * If the mode is changed, existing Cloud Anchors will have their |cloudState| set to
 * |GARCloudAnchorStateNone| and cease being updated except for tracking state changes.
 * Remember to set a credential for authentication with Google Cloud before configuring, or
 * you may receive auth errors.
 */
@property(nonatomic) GARCloudAnchorMode cloudAnchorMode;

@end

NS_ASSUME_NONNULL_END
