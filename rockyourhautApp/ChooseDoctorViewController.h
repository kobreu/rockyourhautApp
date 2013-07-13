//
//  ChooseDoctorViewController.h
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <mobile.connect.checkout/mobile.connect.checkout.h>
#import <mobile.connect/mobile.connect.h>

@interface ChooseDoctorViewController : UIViewController

@property (strong, nonatomic) PWPaymentProvider *provider;
@property (strong, nonatomic) PWPaymentPageProvider *pageProvider;

@property (strong, nonatomic) IBOutlet UIButton *doctor1;
@property (strong, nonatomic) IBOutlet UIButton *doctor2;
@property (strong, nonatomic) IBOutlet UIButton *doctor3;
@property (strong, nonatomic) IBOutlet UIButton *doctor4;

@property (strong, nonatomic) IBOutlet UIImageView *doctorImage;
@property (strong, nonatomic) IBOutlet UIImageView *chatImageView;
@property (strong, nonatomic) IBOutlet UILabel *doctorName;
@property (strong, nonatomic) IBOutlet UILabel *jobName;


- (IBAction)openPayment:(id)sender;

- (IBAction)changeDoctor:(id)sender;

@end
