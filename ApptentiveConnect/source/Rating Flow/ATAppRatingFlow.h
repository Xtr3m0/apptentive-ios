//
//  ATAppRatingFlow.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 7/8/11.
//  Copyright 2011 Apptentive, Inc. All rights reserved.
//

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>
#elif TARGET_OS_MAC
#import <Cocoa/Cocoa.h>
#endif

/*! A workflow for a user either giving feedback on or rating the current
 application. */
@interface ATAppRatingFlow : NSObject
#if TARGET_OS_IPHONE
<SKStoreProductViewControllerDelegate, UIAlertViewDelegate>
#endif
{
}

#if TARGET_OS_IPHONE
/*!
 Deprecated. Use the Rating Flow Interaction instead.
 Call `engage:fromViewController:` for certain events in your app.
 Then, set up a rating flow interaciton via the Apptentive website.
 */
- (BOOL)showRatingFlowFromViewControllerIfConditionsAreMet:(UIViewController *)viewController DEPRECATED_ATTRIBUTE;

#elif TARGET_OS_MAC
- (void)showRatingFlowIfConditionsAreMet;

/*! 
 Call when the application is done launching. If we should be able to
 prompt for a rating, pass YES.
 */
- (void)appDidLaunch:(BOOL)canPromptForRating;
#endif

/*!
 Deprecated. Log events using the `engage:fromViewController:` method instead.
 The new engagements events are more powerful, and can be used to selectively
 display interactions based on a wide range of individual event types.
 */
- (void)logSignificantEvent DEPRECATED_ATTRIBUTE;

/*!
 Call to open your app's page on the App Store or Mac App Store.
 This method can be used to power, for example, a "Rate this app" button in your settings screen.
 It opens the app store directly, without the normal Apptentive Ratings Flow.
 If the app store is manually opened, the Rating Flow will not prompt again for this version.
 Depending on the iOS version, the App Store will either be opened via the App Store app or as
 a Store Kit view inside your app.
 */
- (void)openAppStore;

@end
