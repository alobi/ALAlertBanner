/**
 ALAlertBannerManager.h
 
 Created by Anthony Lobianco on 8/12/13.
 Copyright (c) 2013 Anthony Lobianco. All rights reserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **/

#import <Foundation/Foundation.h>
#import "ALAlertBannerView.h"

@interface ALAlertBannerManager : NSObject

/**
 Length of time in seconds that a banner should show before auto-hiding. 
 
 Default value is 3.5 seconds. A value <= 0 will disable auto-hiding.
 */
@property (nonatomic) NSTimeInterval secondsToShow;

/**
 The length of time it takes a banner to transition on-screen. 
 
 Default value is 0.25 seconds.
 */
@property (nonatomic) NSTimeInterval showAnimationDuration;

/**
 The length of time it takes a banner to transition off-screen. 
 
 Default value is 0.2 seconds.
 */
@property (nonatomic) NSTimeInterval hideAnimationDuration;

/**
 Banner opacity, between 0 and 1. 
 
 Default value is 0.93f.
 */
@property (nonatomic, assign) CGFloat bannerOpacity;

/**
 Tapping on a banner will dismiss it early. 
 
 Default value is YES. If you supply a tappedHandler in one of the appropriate methods, this will be set to NO for that specific banner.
 */
@property (nonatomic, assign) BOOL allowTapToDismiss;

/**
 The global shared instance that manages the presentation and dismissal of alert banners.
 */
+ (ALAlertBannerManager *)sharedManager;

/**
 The default methods to display a banner. 
 */
- (ALAlertBannerView *)showAlertBannerInView:(UIView *)view style:(ALAlertBannerStyle *)style position:(ALAlertBannerPosition)position title:(NSString *)title;

- (ALAlertBannerView *)showAlertBannerInView:(UIView *)view style:(ALAlertBannerStyle *)style position:(ALAlertBannerPosition)position title:(NSString *)title subtitle:(NSString *)subtitle;

/** 
 Optional method to set the secondsToShow duration on a per-banner basis.
 */
- (ALAlertBannerView *)showAlertBannerInView:(UIView *)view style:(ALAlertBannerStyle *)style position:(ALAlertBannerPosition)position title:(NSString *)title subtitle:(NSString *)subtitle hideAfter:(NSTimeInterval)secondsToShow;

/**
 Optional methods to handle a tap on a banner. 
 
 By default, supplying a tap handler will disable allowTapToDismiss on this particular banner. If you want to reinstate this behavior alongside the tap handler, you can call `[[ALAlertBannerManager sharedManager] hideAlertBanner:alertBanner];` in tappedBlock().
 */
- (ALAlertBannerView *)showAlertBannerInView:(UIView *)view style:(ALAlertBannerStyle *)style position:(ALAlertBannerPosition)position title:(NSString *)title subtitle:(NSString *)subtitle tappedHandler:(void(^)(ALAlertBannerView *alertBanner))tappedBlock;

- (ALAlertBannerView *)showAlertBannerInView:(UIView *)view style:(ALAlertBannerStyle *)style position:(ALAlertBannerPosition)position title:(NSString *)title subtitle:(NSString *)subtitle hideAfter:(NSTimeInterval)secondsToShow tappedHandler:(void(^)(ALAlertBannerView *alertBanner))tappedBlock;

/**
 Immediately hide a specific alert banner.
 */
- (void)hideAlertBanner:(ALAlertBannerView *)alertBanner;

/**
 Returns an array of all banners within a certain view.
 */
- (NSArray *)alertBannersInView:(UIView *)view;

/**
 Immediately hides all alert banners in all views.
 */
- (void)hideAllAlertBanners;

/**
 Immediately hides all alert banners in a certain view.
 */
- (void)hideAlertBannersInView:(UIView *)view;

@end
