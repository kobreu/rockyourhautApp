//
//  BodyPartViewController.h
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CurrentExamination.h"

@interface BodyPartViewController : UIViewController

@property (nonatomic, retain) IBOutlet UIButton *headButton;
@property (nonatomic, retain) IBOutlet UIButton *leftArmButton;
@property (nonatomic, retain) IBOutlet UIButton *rightArmButton;
@property (nonatomic, retain) IBOutlet UIButton *torsoButton;
@property (nonatomic, retain) IBOutlet UIButton *penisButton;
@property (nonatomic, retain) IBOutlet UIButton *leftLegButton;
@property (nonatomic, retain) IBOutlet UIButton *rightLegButton;

- (IBAction)bodyPartSelected:(id)sender;


@end
