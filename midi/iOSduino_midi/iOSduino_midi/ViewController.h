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
}

- (IBAction)playSound:(id)sender;
- (IBAction)goForward:(id)sender;
- (IBAction)goBackward:(id)sender;
- (IBAction)goLeft:(id)sender;
- (IBAction)goRight:(id)sender;
- (IBAction)stop:(id)sender;

@end
