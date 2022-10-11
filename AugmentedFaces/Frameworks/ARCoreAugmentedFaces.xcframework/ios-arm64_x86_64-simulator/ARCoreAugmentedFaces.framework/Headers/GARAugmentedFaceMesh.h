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

NS_ASSUME_NONNULL_BEGIN

/**
 * Object that holds face mesh and transform data for a detected face.
 */
@interface GARAugmentedFaceMesh : NSObject

/**
 * Number of vertices in the Augmented Faces mesh.
 *
 * The #vertexCount will not change.
 * Currently, there are 468 vertices, although this might change in the future.
 */
@property(nonatomic, readonly) NSUInteger vertexCount;

/**
 * A float buffer of 3D vertex locations in (x, y, z) packing.
 *
 * These vertices are relative to the center transform of the face. Units are in meters.
 */
@property(nonatomic, readonly) const simd_float3 *vertices;

/**
 * A float buffer of UV texture coordinates in (u, v) packing.
 *
 * There is a pair of texture coordinates for each vertex.
 * The textureCoordinates will not change.
 */
@property(nonatomic, readonly) const simd_float2 *textureCoordinates;

/**
 * A buffer of 3D normals in (x, y, z) packing.
 *
 * Each (x, y, z) is a unit vector of the normal to the surface at each vertex. There is
 * exactly one normal vector for each vertex. These normals are relative to center transform of
 * the face.
 */
@property(nonatomic, readonly) const simd_float3 *normals;

/**
 * Number of triangles in the face mesh.
 *
 * This is equivalent to the number of elements in #triangleIndices divided by 3.
 * The count will not change.
 */
@property(nonatomic, readonly) NSUInteger triangleCount;

/**
 * A buffer of triangles' indices in consecutive (i0, i1, i2) triplets.
 *
 * Every three consecutive values are indices that represent a triangle. The front face of each
 * triangle is defined by the face where the vertices are in counter clockwise winding order.
 *
 * The triangleIndices will not change.
 */
@property(nonatomic, readonly) const uint16_t *triangleIndices;

/// @cond
/**
 * Created by GARAugmentedFace.
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
