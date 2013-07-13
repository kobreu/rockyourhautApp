//
//  CurrentExamination.h
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ExaminationData.h"

@interface CurrentExamination : NSObject

@property (nonatomic, retain) ExaminationData *examinationData;

+ (CurrentExamination *)sharedInstance;


@end
