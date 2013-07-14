//
//  ExaminationQuestionControllerViewController.h
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/14/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ExaminationQuestionControllerViewController : UIViewController

@property (nonatomic, strong) IBOutlet UILabel *ageLabel;

- (IBAction)ageChanged:(id)sender;

@end
