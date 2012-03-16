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


@interface ViewController : UIViewController <RscMgrDelegate>
{
    RscMgr *rscMgr;
    UInt8 rxBuffer[BUFFER_LEN];
    UInt8 txBuffer[BUFFER_LEN];
}

@property (nonatomic,retain) IBOutlet UITextView *log;

@end
