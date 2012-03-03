//
//  ViewController.m
//  iOSduino_midi
//
//  Created by David House on 3/2/12.
//  Copyright (c) 2012 Random Accident. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    // Load up the PGMidi component
    midi = [[PGMidi alloc] init];
    [midi enableNetwork:YES];
    [midi retain];
    
    currentBank = 0;
}

- (void)dealloc
{
    [midi release];
    [super dealloc];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    if ( interfaceOrientation == UIInterfaceOrientationLandscapeLeft ||
            interfaceOrientation == UIInterfaceOrientationLandscapeRight )
        return YES;
    else
        return NO;
}


- (IBAction)noteDown:(id)sender
{
    // calculate note from TAG and Current Bank
    UIButton *btn = (UIButton *)sender;
    UInt8 note = (btn.tag - 1) + (currentBank * 12);
    const UInt8 noteOn[] = { 0x90, note, 127 };
    [midi sendBytes:noteOn size:sizeof(noteOn)];
}

- (IBAction)noteUp:(id)sender
{
    // calculate note from TAG and Current Bank
    UIButton *btn = (UIButton *)sender;
    UInt8 note = (btn.tag - 1) + (currentBank * 12);
    const UInt8 noteOff[] = { 0x80, note, 0 };
    [midi sendBytes:noteOff size:sizeof(noteOff)];    
}

- (IBAction)bankSelect:(id)sender
{
    UISegmentedControl *seg = (UISegmentedControl *)sender;
    currentBank = seg.selectedSegmentIndex;
}



@end
