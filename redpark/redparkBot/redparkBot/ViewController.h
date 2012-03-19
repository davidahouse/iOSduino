//
//  ViewController.h
//  redparkBot
//
//  Created by David House on 3/14/12.
//  Copyright (c) 2012 Random Accident. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RscMgr.h"

#define BUFFER_LEN 1024
#define MAX_DANCE_MOVES 50

@interface ViewController : UIViewController <RscMgrDelegate>
{
    RscMgr *rscMgr;
    UInt8 rxBuffer[BUFFER_LEN];
    UInt8 txBuffer[BUFFER_LEN];
    int switchDetected;
    NSString *currentBehavior;
    int backupCounter;
    int exploreCounter;
    int inBytes;
    int outBytes;
    int outErrors;
}

@property (nonatomic,retain) IBOutlet UILabel *statusLabel;
@property (nonatomic,retain) IBOutlet UILabel *readBytes;
@property (nonatomic,retain) IBOutlet UILabel *writeBytes;
@property (nonatomic,retain) IBOutlet UILabel *cableStatus;
@property (nonatomic,retain) IBOutlet UILabel *writeErrors;
@property (nonatomic,retain) IBOutlet UILabel *switchStatus;
@property (nonatomic,retain) IBOutlet UILabel *motorStatus;

- (void)motorControl:(int)left right:(int)right;

@end
