//
//  BodyPartViewController.m
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import "BodyPartViewController.h"

@interface BodyPartViewController ()

@end

@implementation BodyPartViewController

@synthesize leftArmButton, rightArmButton, leftLegButton, rightLegButton, headButton, torsoButton, penisButton, bodyImage;

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

- (IBAction)bodyPartSelected: (id)sender {
    if(sender == leftArmButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = LEFTARM;
    } else if(sender == rightArmButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = RIGHTARM;
    } else if(sender == leftLegButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = LEFTLEG;
    } else if(sender == rightLegButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = RIGHTLEG;
    } else if(sender == headButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = HEAD;
    } else if(sender == penisButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = PENIS;
    } else if(sender == torsoButton) {
        [CurrentExamination sharedInstance].examinationData.bodyPart = TORSO;
    }
}

- (IBAction)genderSelected:(id)sender{
    UISegmentedControl *segmentedControl = (UISegmentedControl *) sender;
    
    if(segmentedControl.selectedSegmentIndex == 0)
    {
        bodyImage.image = [UIImage imageNamed:@"body.png"];
    }
    else if(segmentedControl.selectedSegmentIndex == 1)
    {
        bodyImage.image = [UIImage imageNamed:@"body_female.png"];
    }
}

@end
