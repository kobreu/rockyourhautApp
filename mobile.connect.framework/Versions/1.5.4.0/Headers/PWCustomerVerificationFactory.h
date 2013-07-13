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
#import "PWCustomerVerification.h"
#import <UIKit/UIKit.h>

/**
 * Factory for creating PWCustomerVerification objects. Do not instantiate directly, subclass first.
 *
 * @warning Do not instantiate directly. Use the provided factory methods in the concrete subclass of a PWPaymentProvider.
 */
@interface PWCustomerVerificationFactory : NSObject


/**
 * Creates a PWCustomerVerification based on the data passed in. This verification can be persisted using a PWPaymentProvider
 * @param data The data to be persisted
 */
-(PWCustomerVerification*)createCustomerVerificationFromData:(NSData*) data;

/**
 * Creates a PWCustomerVerification based on the UIImage passed in. This verification can be persisted using a PWPaymentProvider
 * @param image The image to be persisted
 */

-(PWCustomerVerification*)createCustomerVerificationFromImage:(UIImage*) image;

@end
