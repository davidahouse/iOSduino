//
//  ViewController.h
//  iOSduino_light
//
//  Created by David House on 2/27/12.
//  Copyright (c) 2012 Random Accident. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (nonatomic,retain) IBOutlet UIView* lightOutput;

- (IBAction)sliderChanged:(id)sender;

@end
