//
//  SummaryViewController.m
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/14/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import "SummaryViewController.h"

@interface SummaryViewController ()

@end

@implementation SummaryViewController

@synthesize timeLabel, doctorLabel;

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
    timeLabel.text = [CurrentExamination sharedInstance].examinationData.doctorResponseTime;
    doctorLabel.text = [CurrentExamination sharedInstance].examinationData.doctorName;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
