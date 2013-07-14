//
//  ExaminationData.m
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import "ExaminationData.h"

@implementation ExaminationData

@synthesize bodyPart, imageDistance, imageClose, doctorName, doctorResponseTime;

- (id)init
{
    self = [super init];
    if (self) {
        self.done = NO;
    }
    return self;
}


@end
