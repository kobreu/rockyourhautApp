//
//  MainViewController.h
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CurrentExamination.h"

@interface MainViewController : UIViewController

@property (nonatomic, retain) IBOutlet UIImageView *dermaCareLogo;

@property (nonatomic, strong) IBOutlet UIImageView *notificationImage;
@property (nonatomic, strong) IBOutlet UILabel *notificationLabel;


- (IBAction)initImage;
@end
