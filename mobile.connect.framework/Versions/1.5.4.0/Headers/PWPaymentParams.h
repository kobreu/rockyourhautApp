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

/**
 * Class to encapsulate the parameters needed for performing payments
 *
 * @warning Do not subclass directly. Each type of transaction (credit card etc.) will use its own subclass of PWPaymentParams.
 */

// enum containing the different currencies
typedef enum {
    EUR, // Euro
    GBP, // United Kingdom, Pounds
    PLN, // Poland, Zlotych
    HKD, // Hong Kong, Dollars
    SGD, // Singapore, Dollars
    BRL, // Brazilian Real
    INR, // Indian Rupee
    AUD, // Australien Dollar
    ZAR, // South African Rand
    CHF, // Swiss Franc
    DKK, // Danish Krone
    NOK, // Norwegian Krone
    SEK, // Swedish Krone
    BGN, // Bulgarian LEV
    LVL, // Latvian Lati
    LTL, // Lithuanian Litai
    RON, // Romanian new Leu
    CZK, // Czech Koruna
    HUF,  // Hungarian Forint
    USD,  // United States Dollar
    AED   // United Arab Emirates dirham
} PWCurrency;

// enum containing the different capture methods for payment details
typedef enum {
    PWUnknownCaptureMethod,
    PWManualEntry,
    PWMagneticSwiper,
    PWEMV
} PWCaptureMethod;

@interface PWPaymentParams : NSObject

/** @name Properties */
/** A property that can be set with a custom transaction ID. It is stored together with the transaction for later reference (optional). */
@property (nonatomic, strong) NSString *customIdentifier;
/** The subject of the transaction (optional). This can be empty and will be cut if it is longer than 100 characters.*/
@property (nonatomic, strong) NSString *subject;
/** The amount of the transaction in the specified currency */
@property (nonatomic) double amount;
/** The currency used, as defined by the associated enum PWCurrency. At the moment only EUR is supported. */
@property (nonatomic) PWCurrency currency;
/** @name Properties for Risk Checks (optional) */
/** The given name of the holder */
@property (nonatomic, strong) NSString *givenName;
/** The family name of the holder */
@property (nonatomic, strong) NSString *familyName;
/** Address of the holder: Street name and number */
@property (nonatomic, strong) NSString *street;
/** Address of the holder: zip code */
@property (nonatomic, strong) NSString *zip;
/** Address of the holder: City */
@property (nonatomic, strong) NSString *city;
/** Address of the holder: State */
@property (nonatomic, strong) NSString *state;
/** Address of the holder: Country, according to ISO 3166-1 */
@property (nonatomic, strong) NSString *countryCode;
/** E-mail Address of the holder  */
@property (nonatomic, strong) NSString *email;
/** IP Address of the holder */
@property (nonatomic, strong) NSString *IPaddress;

/** @name Geo location properties (optional) */
/** The latitude of the transaction in degrees. Same format as CLLocationCoordinate2D.latitude. I.e. The latitude in degrees. Positive values indicate latitudes north of the equator. Negative values indicate latitudes south of the equator.*/
@property (nonatomic) double latitude;
/** The longitude in degrees. Measurements are relative to the zero meridian, with positive values extending east of the meridian and negative values extending west of the meridian. */
@property (nonatomic) double longitude;
/** The radius of uncertainty for the location, measured in meters. (Same format as  CLLocation.horizontalAccuracy)*/
@property (nonatomic) double horizontalAccuracy;

/** The way the payment paramters have been captured. */
@property (nonatomic) PWCaptureMethod captureMethod;

/** Helper method to convert PWCurrency to string 
 * @param currency currency to converted to string
 */
+(NSString *) currencyString:(PWCurrency) currency;
/** Helper method to convert String to PWCurrency 
 * @param currency String description of the currency
 */
+(PWCurrency) currencyEnum:(NSString *) currency;
/** Helper method to convert PWCaptureMethod to string 
 * @param captureMethod PWCaptureMethod to converted to string
 */
+(NSString *) captureMethodString:(PWCaptureMethod) captureMethod;

@end
