//
//  ATBackend.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 3/19/11.
//  Copyright 2011 Planetary Scale LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ATFeedback;

/*! Handles all of the backend activities, such as sending feedback. */
@interface ATBackend : NSObject {
}
@property (nonatomic, retain) NSString *apiKey;
@property (nonatomic, retain) NSString *appID;

+ (ATBackend *)sharedBackend;
- (void)sendFeedback:(ATFeedback *)feedback;
- (NSString *)supportDirectoryPath;
@end