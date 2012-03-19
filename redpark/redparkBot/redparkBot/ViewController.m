//
//  ViewController.m
//  redparkBot
//
//  Created by David House on 3/14/12.
//  Copyright (c) 2012 Random Accident. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize statusLabel, readBytes, writeBytes, cableStatus, writeErrors, switchStatus, motorStatus;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    rscMgr = [[RscMgr alloc] init];
    [rscMgr setDelegate:self];
    
    [NSTimer scheduledTimerWithTimeInterval:.5 target:self selector:@selector(tick:) userInfo:nil repeats:YES];
    currentBehavior = @"Explore";
    statusLabel.text = currentBehavior;
    inBytes = 0;
    outBytes = 0;
    outErrors = 0;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.b
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

#pragma mark -
#pragma mark State Machine
- (void)tick:(NSTimer *)timer
{
    NSLog(@"tick...");
    
    if ( [currentBehavior isEqualToString:@"Explore"] )
    {
        // if switch was pressed, then BACKUP!
        if ( switchDetected == 1 )
        {
            switchDetected = 0;
            backupCounter = 0;
            currentBehavior = @"Backup";
            statusLabel.text = currentBehavior;

            // tell robot to stop
            [self motorControl:90 right:90];
        }
        else 
        {
            // tell robot to move forward
            [self motorControl:0 right:180];
        }
    }
    else if ( [currentBehavior isEqualToString:@"Backup"] )
    {
        backupCounter++;
        if (backupCounter > 6)
        {
            exploreCounter = 0;
            currentBehavior = @"Explore";
            statusLabel.text = currentBehavior;
        }
        else 
        {
            // tell robot to backup and turn slightly
            [self motorControl:180 right:30];
        }
    }
}


#pragma mark -
#pragma mark RedPark Cable methods
- (void)cableConnected:(NSString *)protocol
{
    [rscMgr setBaud:9600];
    [rscMgr open];
    cableStatus.text = @"Cable: Connected!";
}

- (void)cableDisconnected
{
    cableStatus.text = @"Cable: Disconnected!";
}

- (void)portStatusChanged
{
    
}

- (void)readBytesAvailable:(UInt32)length
{
    int bytesRead = [rscMgr read:rxBuffer Length:length];
    NSLog(@"Read %d bytes from serial cable", bytesRead);
    for ( int i = 0; i < length; ++i )
    {
        if ( (int)rxBuffer[i] == 49 )
        {
            switchDetected = 1;
        }
        else 
        {
            switchDetected = 0;
        }
        self.switchStatus.text = [NSString stringWithFormat:@"%d",(int)rxBuffer[i]];
        
        inBytes++;
        self.readBytes.text = [NSString stringWithFormat:@"%d",inBytes];
    }
}

- (BOOL)rscMessageReceived:(UInt8 *)msg TotalLength:(int)len
{
  return FALSE;
}

- (void)didReceivePortConfig
{
    
}

- (void)motorControl:(int)left right:(int)right
{
    int writeLen = 2;
    txBuffer[0] = left;
    txBuffer[1] = right;
    self.motorStatus.text = [NSString stringWithFormat:@"Left: %d Right: %d",left,right];
    int written = [rscMgr write:txBuffer Length:writeLen];
    if ( written != writeLen )
    {
        outErrors++;
        writeErrors.text = [NSString stringWithFormat:@"%d",outErrors];
    }
    else 
    {
        outBytes += writeLen;
        writeBytes.text = [NSString stringWithFormat:@"%d",outBytes];
    }
}

              
@end
