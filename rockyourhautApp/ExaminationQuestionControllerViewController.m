//
//  ExaminationQuestionControllerViewController.m
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/14/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import "ExaminationQuestionControllerViewController.h"

@interface ExaminationQuestionControllerViewController ()

@end

@implementation ExaminationQuestionControllerViewController

@synthesize ageLabel, customText;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)ageChanged:(id)sender {
    double value = [(UIStepper*)sender value];
    
    [ageLabel setText:[NSString stringWithFormat:@"%d", (int)value]];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [customText resignFirstResponder];
    return YES;
}

@end
