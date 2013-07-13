//
//  CurrentExamination.m
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import "CurrentExamination.h"


@implementation CurrentExamination

@synthesize examinationData;

+ (CurrentExamination *)sharedInstance
{
    static CurrentExamination *sharedInstance;
    
    @synchronized(self)
    {
        if (!sharedInstance)
            sharedInstance = [[CurrentExamination alloc] init];
        
        return sharedInstance;
    }
}


@end
