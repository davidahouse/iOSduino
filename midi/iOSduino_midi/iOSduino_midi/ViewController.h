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

@property (nonatomic,retain) IBOutlet UISwitch *notesOn;

- (IBAction)playSound:(id)sender;
- (IBAction)armUp:(id)sender;
- (IBAction)armDown:(id)sender;

@end
