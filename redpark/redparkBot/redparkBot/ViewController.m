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

@synthesize log;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    
    rscMgr = [[RscMgr alloc] init];
    [rscMgr setDelegate:self];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}


#pragma mark -
#pragma mark RedPark Cable methods
- (void)cableConnected:(NSString *)protocol
{
    self.log.text = [NSString stringWithFormat:@"%@cableConnected!",self.log.text];
    [rscMgr setBaud:9600];
    [rscMgr open];
}

- (void)cableDisconnected
{
    
}

- (void)portStatusChanged
{
    
}

- (void)readBytesAvailable:(UInt32)length
{
    self.log.text = [NSString stringWithFormat:@"%@[",self.log.text];
    int bytesRead = [rscMgr read:rxBuffer Length:length];
    NSLog(@"Read %d bytes from serial cable", bytesRead);
    for ( int i = 0; i < length; ++i )
    {
        self.log.text = [NSString stringWithFormat:@"%@%c",self.log.text,((int)rxBuffer[i])];
    }
    self.log.text = [NSString stringWithFormat:@"%@]",self.log.text];
}

- (BOOL)rscMessageReceived:(UInt8 *)msg TotalLength:(int)len
{
  return FALSE;
}

- (void)didReceivePortConfig
{
    
}
              
              
@end
