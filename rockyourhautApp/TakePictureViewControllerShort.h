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
<<<<<<< HEAD
=======


@property (nonatomic, strong) IBOutlet UIButton *cameraButton;


>>>>>>> 55d549097b02785ab4666ef947d519f589ef4bb6
- (IBAction)useCamera:(id)sender;
- (IBAction)useCameraRoll:(id)sender;

@property (nonatomic, retain) IBOutlet UILabel *text;
@end
