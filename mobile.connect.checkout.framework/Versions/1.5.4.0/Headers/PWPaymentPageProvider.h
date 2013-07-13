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
#import "PWPaymentPageResponse.h"


/**
 * Abstract class for displaying an in-App payment page. Do not use this class directly, use the appropriate factories to get a subclass. This is part of the payworks.connect.checkout framework.
 */
@interface PWPaymentPageProvider : NSObject

/**
 * Opens an in-App payment page for collecting user input and submitting a transaction. The delegate gets informed of success or failure of a transaction. If the user closes the payment page prematurely the failure block is called with a respective error (PWTransactionStatePaymentPageClosedErrorCode).
 * @param registered A Block executed when the transaction was registered successfully. Registering a transaction assigns it a unique mobile identifier in the system but the transaction is not processed. This block can be used to persist this [PWTransaction mobileIdentifier] for future reference and thus checking the transaction status later on. This block needs to return true for the payment to proceed. If it returns false, the transaction is cancelled.
 * @param success A Block executed when the transaction was processed successfully
 * @param failure A Block executed when the transaction processing failed
 */
-(void)openPaymentPageForSubmittingTransactionWhenRegistered:(BOOL(^)(PWTransaction *transaction)) registered onSuccess:(void(^)(PWPaymentPageResponse *response))success onFailure:(void(^)(PWPaymentPageResponse *response, NSError *error)) failure;

/**
 * Closes the in-App payment page for collecting user input and submitting a transaction. The delegate is not informed if this method is being called.
 * @param animated Specifies whether the payment page should be dismissed using an animation or immediately without an animation.
 */
-(void)dismissPaymentPageAnimated: (BOOL) animated;
@end
