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

#import <CoreVideo/CoreVideo.h>
#import <UIKit/UIKit.h>
#import <simd/simd.h>

@class GARAugmentedFace;

NS_ASSUME_NONNULL_BEGIN

/**
 * Object that holds all relevant information for an Augmented Faces frame during which face
 * detection was run.
 */
@interface GARAugmentedFaceFrame : NSObject

/**
 * Contains a GARAugmentedFace if a face is detected in this frame, otherwise nil.
 */
@property(nonatomic, readonly, nullable) GARAugmentedFace *face;

/**
 * A buffer containing the image that was input to GARAugmentedFaceSession.
 */
@property(nonatomic, readonly) CVPixelBufferRef capturedImage;

/**
 * The time at which the frame was captured. This is simply the timestamp passed into
 * GARAugmentedFaceSession#updateWithPixelBuffer:timestamp:recognitionRotation:
 */
@property(nonatomic, readonly) NSTimeInterval timestamp;

/**
 * A 3D projection matrix that will result in the correct alignment of AR rendered content on top
 * of the captured camera image.
 *
 * @param viewPortSize The size of the view into which the AR content will be rendered.
 * @param presentationOrientation The orientation in which to display the AR content.
 *  UIDeviceOrientationUnknown, UIDeviceOrientationFaceUp and UIDeviceOrientationFaceDown map to
 *  UIDeviceOrientationPortrait.
 * @param mirrored Whether to provide a mirrored projection matrix. This will require you to flip
 *  the winding order for rendering.
 * @param zNear The near clipping distance in meters.
 * @param zFar The far clipping distance in meters. Must be positive and greater than the near
 *  distance.
 *
 * @remarks This method assumes camera images are rendered to aspect fill, not aspect fit.
 */
- (simd_float4x4)projectionMatrixForViewportSize:(CGSize)viewPortSize
                         presentationOrientation:(UIDeviceOrientation)presentationOrientation
                                        mirrored:(BOOL)mirrored
                                           zNear:(CGFloat)zNear
                                            zFar:(CGFloat)zFar;

/**
 * A transform that converts between image coordinates and coordinate space for displaying
 * 2D content on screen that is aligned with the AR rendered content.
 *
 * @param viewPortSize The size of the view used to render the camera image.
 * @param presentationOrientation The orientation in which to display the 2D content.
 *  UIDeviceOrientationUnknown, UIDeviceOrientationFaceUp and UIDeviceOrientationFaceDown map to
 *  UIDeviceOrientationPortrait.
 * @param mirrored Whether to provide a mirrored transform. Use this in conjunction with the value
 *   passed in
 *   GARAugmentedFaceFrame#projectionMatrixForViewportSize:presentationOrientation:mirrored:zNear:zFar:
 *
 * @remarks This method assumes camera images are rendered to aspect fill, not aspect fit.
 */
- (CGAffineTransform)displayTransformForViewportSize:(CGSize)viewPortSize
                             presentationOrientation:(UIDeviceOrientation)presentationOrientation
                                            mirrored:(BOOL)mirrored;

/// @cond
/**
 * Created upon request by GARAugmentedFaceSession.
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/// @endcond

@end

NS_ASSUME_NONNULL_END
