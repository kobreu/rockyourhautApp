//
//  TakePictureViewControllerShort.h
//  rockyourhautApp
//
//  Created by Bettina Ebert on 13.07.13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>

@interface TakePictureViewControllerShort : UIViewController
<UIImagePickerControllerDelegate,
UINavigationControllerDelegate>
{
}

@property BOOL newMedia;
@property (strong, nonatomic) IBOutlet UIImageView *imageView;
@property (nonatomic, retain) IBOutlet UIToolbar *toolbar;
- (IBAction)useCamera:(id)sender;
- (IBAction)useCameraRoll:(id)sender;

@property (nonatomic, retain) IBOutlet UILabel *text;
@end
