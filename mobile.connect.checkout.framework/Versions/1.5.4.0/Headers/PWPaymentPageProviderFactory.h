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
#import <mobile.connect/mobile.connect.h>
#import "PWPaymentPageSettings.h"
#import "PWPaymentPageProvider.h"

/**
 * Factory class for generating a PWPaymentPageProvider for a given PWPaymentProvider, PWPaymentParams and PWPaymentPageSettings.
 * Use the defaultFactory property to get a factory. This is part of the payworks.connect.checkout framework.
 */
@interface PWPaymentPageProviderFactory : NSObject

/**
 * Factory method to generate a PWPaymentPageProvider used for displaying an in-App payment page
 * @param provider A PWPaymentProvider which is used for performing the transaction once all the data from the user is collected
 * @param paymentParameters The PWPaymentParams describing the transaction to be performed. This includes amount, currency, subject etc. Payment scheme specific data is ignored, e.g. prepopulating with a credit card number
 * @param settings The PWPaymentPageSettings used for this payment page. These settings are provided to customize the appearance and functionality of the payment page. If set to nil, the default settings will be used
 * @return Returns a PWPaymentPageProvider for displaying in-App payment pages. Return nil if either the passd in provider or the payment parameters are nil.
 */
-(PWPaymentPageProvider*) paymentPageProviderForPaymentProvider:(PWPaymentProvider*) provider paymentParams:(PWPaymentParams*) paymentParameters andSettings:(PWPaymentPageSettings*) settings;
/**
 * Method to get the default factory for creating a PWPaymentPageProvider
 */
+(PWPaymentPageProviderFactory*)defaultFactory;
@end
