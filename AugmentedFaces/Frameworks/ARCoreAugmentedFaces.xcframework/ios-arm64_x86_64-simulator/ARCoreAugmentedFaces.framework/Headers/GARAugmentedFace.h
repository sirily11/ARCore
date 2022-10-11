/*
 * Copyright 2019 Google LLC. All Rights Reserved.
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
#import <simd/simd.h>

@class GARAugmentedFaceMesh;

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines face regions to query the transforms for. Left and right are defined relative to the
 * person that the mesh belongs to. To retrieve the center transform use |centerTransform|.
 */
typedef NS_ENUM(NSUInteger, GARAugmentedFaceRegionType) {
  /** The region at the tip of the nose. */
  GARAugmentedFaceRegionTypeNose = 0,

  /** The region at the detected face's left side of the forehead. */
  GARAugmentedFaceRegionTypeForeheadLeft = 1,

  /** The region at the detected face's right side of the forehead. */
  GARAugmentedFaceRegionTypeForeheadRight = 2,
};

/**
 * Object that holds face mesh and transform data for detected face.
 */
@interface GARAugmentedFace : NSObject

/**
 * 3D mesh representation of detected face.
 */
@property(nonatomic, readonly) GARAugmentedFaceMesh *mesh;

/**
 * The transform from camera to the center of the face, defined to have the origin located behind
 * the nose and between the two cheek bones. +Z is forward out of the nose, +Y is upwards, and +X is
 * towards the face's left. The units are in meters.
 */
@property(nonatomic, readonly) simd_float4x4 centerTransform;

/// @cond
/**
 * Created by GARAugmentedFaceFrame.
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

/**
 * Transform from camera to to specified GARAugmentedFaceRegionType region
 */
- (simd_float4x4)transformForRegion:(GARAugmentedFaceRegionType)regionType;

@end

NS_ASSUME_NONNULL_END
