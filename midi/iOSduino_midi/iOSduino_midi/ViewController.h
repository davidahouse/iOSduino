//
//  ViewController.h
//  iOSduino_midi
//
//  Created by David House on 3/2/12.
//  Copyright (c) 2012 Random Accident. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PGMidi.h"

@interface ViewController : UIViewController
{
    PGMidi *midi;
    int currentBank;
}

- (IBAction)noteDown:(id)sender;
- (IBAction)noteUp:(id)sender;
- (IBAction)bankSelect:(id)sender;

@end
