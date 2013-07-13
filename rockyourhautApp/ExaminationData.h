//
//  ExaminationData.h
//  rockyourhautApp
//
//  Created by Korbinian Breu on 7/13/13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    LEFTARM,
    RIGHTARM,
    LEFTLEG,
    RIGHTLEG,
    TORSO,
    HEAD,
    PENIS
} BodyPart;

@interface ExaminationData : NSObject

@property(nonatomic) BodyPart bodyPart;
@property(nonatomic, retain) UIImage *imageDistance;
@property(nonatomic, retain) UIImage *imageClose;


@end
