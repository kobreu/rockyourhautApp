//
//  ChooseDoctorViewController.m
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import "ChooseDoctorViewController.h"

@interface ChooseDoctorViewController ()

@end

@implementation ChooseDoctorViewController

@synthesize provider, pageProvider, doctor1, doctor2, doctor3, doctor4, doctorImage, doctorName, jobName, chatImageView, responseTime, payButton, expressPayButton;

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
    provider = [PWPaymentProvider getProviderWithName:@"payworks"
                                       andCredentials:@"YOUR PROFILE TOKEN",@"YOUR APPLICATION IDENTIFIER",nil];
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(BOOL)shouldAutorotate
{
    return NO;
}


- (void) changeDoctor:(id)sender {
    NSArray *imageNames = [NSArray arrayWithObjects: @"doctor1.jpg", @"doctor3.jpg",  @"doctor2.jpg", @"doctor4.jpg", nil];
    NSArray *doctorNames = [NSArray arrayWithObjects: @"Prof. Dr. Klaus Brinkmann", @"Dr. Erika Berger", @"Dr. Jochen Sommer", @"Dr. Tassilo Tetzlaff" , nil];
    NSArray *jobNames = [NSArray arrayWithObjects: @"Dermatologe", @"Dermatologin", @"Dermatologe", @"Dermatologe", nil];
        NSArray *responseTimes = [NSArray arrayWithObjects: @"15", @"30", @"30", @"45", nil];
    
    NSArray *online = [NSArray arrayWithObjects: [NSNumber numberWithBool:YES], [NSNumber numberWithBool:YES], [NSNumber numberWithBool:NO], [NSNumber numberWithBool:YES], nil];
    
    NSInteger index = 0;
    
    if (sender == doctor1) {
        index = 0;
    } else if(sender == doctor2) {
        index = 1;
    } else if(sender == doctor3) {
        index = 2;
    } else if(sender == doctor4) {
        index = 3;
    }
    
    UIImage *image = [UIImage imageNamed:[imageNames objectAtIndex:index]];
    
    UIImage *chatImage = nil;
    if([[online objectAtIndex:index] boolValue] == YES) {
        chatImage = [UIImage imageNamed:@"online_03.png"];
    } else {
        chatImage = [UIImage imageNamed:@"offline_03.png"];
    }
    
    doctorImage.image = image;
    doctorName.text = [doctorNames objectAtIndex:index];
    jobName.text = [jobNames objectAtIndex:index];
    chatImageView.image = chatImage;
    responseTime.text = [responseTimes objectAtIndex:index];
    
    [CurrentExamination sharedInstance].examinationData.doctorName = doctorName.text;
    [CurrentExamination sharedInstance].examinationData.doctorResponseTime = responseTime.text;

}

- (void)openPayment:(id)sender {
    double amount = 10.0;
    // Define how much the customer should be asked to pay
    PWPaymentParams *params = [provider.paymentParamsFactory createGenericPaymentParamsWithAmount:10.0 currency:EUR error:nil];
    
    if(sender == payButton) {
        amount = 5;
    } else if(sender == expressPayButton) {
        amount = 15;
    }
    
    
    
    
    NSError *error;
    params = [provider.paymentParamsFactory createCreditCardPaymentParamsWithAmount:amount currency:EUR subject:@"subject" ccNumber:@"4200000000000000" name:@"name" expiryYear:@"2013" expiryMonth:@"12" CVV:@"921" latitude:0 longitude:0 horizontalAccuracy:0 error:&error];
    
    PWPaymentPageSettings *settings = [[PWPaymentPageSettings alloc] init];
    // Set your Company or Shop name
    settings.customDescription = @"Swipe & Buy";
    
    // E.g. make direct debit available for Germany (DE) and Austria (AT)
    NSArray *countries = [NSArray arrayWithObjects:@"DE", @"AT",nil];
    settings.directDebitCountries = countries;
    
    // Set the vat Amount to 1.60 EUR
    settings.vatAmount = (19.0/100.0);
    
    // Set Custom Buttons Colors
    settings.confirmationButtonColor = [UIColor orangeColor];
    
    // Set Custom Logo if needed, otherwise the app logo is used
    settings.customLogo = [UIImage imageNamed:@"Icon@2x.png"];

    self.pageProvider = [[PWPaymentPageProviderFactory defaultFactory] paymentPageProviderForPaymentProvider:provider paymentParams:params andSettings:settings];
    
    [self.pageProvider openPaymentPageForSubmittingTransactionWhenRegistered:^BOOL(PWTransaction *transaction) {
        //self.transaction = transaction;
        return YES;
    } onSuccess:^(PWPaymentPageResponse *response) {
        // only executed if transaction was successful and money is transfered
        // trigger a SEGUE
        [self performSegueWithIdentifier: @"summary" sender: self];
    } onFailure:^(PWPaymentPageResponse  *response, NSError *error) {
        // Executed on failure of transaction for any reason
        // Also called if payment page was closed
        [self performSegueWithIdentifier: @"summary" sender: self];

    }];
}

@end
