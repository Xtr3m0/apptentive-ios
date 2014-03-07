//
//  ATDeviceUpdater.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 10/2/12.
//  Copyright (c) 2012 Apptentive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ATAPIRequest.h"

NSString *const ATDeviceLastUpdatePreferenceKey;
NSString *const ATDeviceLastUpdateValuePreferenceKey;

@protocol ATDeviceUpdaterDelegate;

@interface ATDeviceUpdater : NSObject <ATAPIRequestDelegate> {
@private
	NSObject<ATDeviceUpdaterDelegate> *__weak delegate;
	ATAPIRequest *request;
}
@property (nonatomic, weak) NSObject<ATDeviceUpdaterDelegate> *delegate;
+ (BOOL)shouldUpdate;

- (id)initWithDelegate:(NSObject<ATDeviceUpdaterDelegate> *)delegate;
- (void)update;
- (void)cancel;
- (float)percentageComplete;
@end

@protocol ATDeviceUpdaterDelegate <NSObject>
- (void)deviceUpdater:(ATDeviceUpdater *)deviceUpdater didFinish:(BOOL)success;
@end
