//
// PAYWORKS GMBH ("COMPANY") CONFIDENTIAL
// Copyright (c) 2012 payworks GmbH, All Rights Reserved.
//
// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained 
// herein are proprietary to COMPANY and may be covered by European or foreign Patents, patents in process, and are protected by trade secret or copyright law.
// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
// Confidentiality and Non-disclosure agreements explicitly covering such access.
//
// The copyright notice above does not evidence any actual or intended publication or disclosure  of  this source code, which includes 
// information that is confidential and/or proprietary, and is a trade secret, of  COMPANY.   
// ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS 
// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Enum describing the possible payment schemes
typedef enum {
    PWPaymentPageSchemeVisa,
    PWPaymentPageSchemeMasterCard,
    PWPaymentPageSchemeDiners,
    PWPaymentPageSchemeChinaUnionPay,
    PWPaymentPageSchemeJCB,
    PWPaymentPageSchemeAmex,
    PWPaymentPageSchemeDirectDebitNational
} PWPaymentPageScheme;

// Enum describing the possible transaction types
typedef enum {
    PWPaymentPagePrauthorize,
    PWPaymentPageDebit
} PWPaymentPageTransactionType;

/**
 * Enum decribing whether and how a token should be requested for the
 * card data that the user enters
 * PWPaymentPageTokenCreateAlways: Always create a token
 * PWPaymentPageTokenCreatePrompt: Prompt the user whether he wishes the data to be stored (Not implemented yet).
 * PWPaymentPageTokenCreateNever (default): Do not create a token
 */
typedef enum {
    PWPaymentPageTokenCreateAlways,
    PWPaymentPageTokenCreatePrompt,
    PWPaymentPageTokenCreateNever
} PWPaymentPageTokenReqest;

/**
 * Class to encapsulate settings for the built-in in-App-Payment-Page. Use this to customize both the visual elements of the payment pages as well as functionality. This includes changing colors and texts, defining payment methods and specifying a value added tax that is included in the price. This is part of the payworks.connect.checkout framework.
 */
@interface PWPaymentPageSettings : NSObject

/// The custom logo to be shown on the top of each payment page
@property(nonatomic, strong) UIImage *customLogo;

/// The custom description to show on the payment page above the total amount
@property(nonatomic, strong) NSString* customDescription;

/// The type of transaction to be done. Usually you want to do a debit transaction. This means the transaction is processed and money transfer is initiated. If you decide to do a preauthorization only, the money transfer is not initiated. For this perform a capture using payworks.connect and the mobileIdentifier of the returend transaction. Default is a debit transaction. 
@property(nonatomic) PWPaymentPageTransactionType transactionType;

/// The value added tax in the currency specified in the transaction parameters. If 0 is entered no tax is shown. This is for showing the user how much tax is included in the total amount. Note: The amount relevant for performing the transaction is the one passed in the payment paramters.
@property(nonatomic) double vatAmount;

/**
 * The payment schemes to be shown (default: Visa, MasterCard, American Express and Direct Debit). Expected is an NSArray of NSNumbers representing different PWPaymentPageScheme enums, e.g.
____
 
    NSArray* defaultPaymentSchemes = [NSArray arrayWithObjects:[NSNumber numberWithInt:(int)PWPaymentPageSchemeMasterCard], [NSNumber numberWithInt:(int)PWPaymentPageSchemeVisa], [NSNumber numberWithInt:(int)PWPaymentPageSchemeAmex], [NSNumber numberWithInt:(int)PWPaymentPageSchemeDirectDebitNational], nil];
 
    settings.paymentSchemes = defaultPaymentSchemes;
 
____

 */
@property(nonatomic, strong) NSArray *paymentSchemes;

/**
 * The countries for which direct debit should be enabled, i.e. the countries from which bank account information can be enabled. If none are specified but the direct debit is added as a payment scheme, Germany is used as the country of the direct debit account holder. Array of NSStrings, e.g.

____
 
    NSArray *countries = [NSArray arrayWithObjects:@"DE", @"AT",nil];
    settings.directDebitCountries = countries;

____
 
 */
@property(nonatomic, strong) NSArray *directDebitCountries;


/**
 * Indicates whether a token should be created for the card data that the user enters
 */
@property(nonatomic) PWPaymentPageTokenReqest createToken;

/// The color of the confirmation buttons (default is green)
@property(nonatomic, strong) UIColor *confirmationButtonColor;

/// The color or the change payment method button (default is gray)
@property(nonatomic, strong) UIColor *changePaymentMethodButtonColor;

/// The language used for language specific labels in ISO 3166-1 language identifier. Currently available are EN and DE. If the language is not supported EN will be used
@property(nonatomic, strong) NSString *language;

@end
