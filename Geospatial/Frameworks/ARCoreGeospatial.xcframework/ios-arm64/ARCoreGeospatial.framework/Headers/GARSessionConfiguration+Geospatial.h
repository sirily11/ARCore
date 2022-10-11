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

#import <ARCoreGeospatial/GARGeospatialMode.h>
#import <ARCoreGARSession/GARSessionConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/** Category adding Geospatial functionality to `GARSessionConfiguration`. */
@interface GARSessionConfiguration (Geospatial)

/**
 * The processing mode for the Geospatial API. The default mode is `GARGeospatialModeDisabled`.
 * If the mode is changed, existing Geospatial anchors will stop tracking.
 *
 * Remember to set a credential for authentication with Google Cloud before configuring, or
 * you may receive auth errors. See `GARSession#sessionWithAPIKey:bundleIdentifier:error:` and
 * `GARSession#setAuthToken:`, as well as documentation on the
 * <a href="https://developers.google.com/ar/develop/ios/geospatial/developer-guide">ARCore
 * developers page</a>.
 *
 * Configuring may result in the following error codes:
 *
 *  - `GARSessionErrorCodeLocationPermissionNotGranted` - Geospatial mode requires location
 * permission (at least when-in-use) with full accuracy.
 *  - `GARSessionErrorCodeConfigurationNotSupported` - Geospatial mode not supported on this device
 * or OS version. Use `GARSession#isGeospatialModeSupported:` to determine this before attempting to
 * configure the session.
 */
@property(nonatomic) GARGeospatialMode geospatialMode;

@end

NS_ASSUME_NONNULL_END
