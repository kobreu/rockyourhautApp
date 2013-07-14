//
//  TakePictureViewController.h
//  rockyourhautApp
//
//  Created by Bettina Ebert on 13.07.13.
//  Copyright (c) 2013 Korbinian Breu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>

@interface TakePictureViewController : UIViewController
<UIImagePickerControllerDelegate,
UINavigationControllerDelegate>
{
}

@property BOOL newMedia;
@property (strong, nonatomic) IBOutlet UIImageView *imageView;
@property (nonatomic, retain) IBOutlet UIToolbar *toolbar;

@property (nonatomic, strong) IBOutlet UIButton *cameraButton;

@property (nonatomic, strong) IBOutlet UILabel *cameraLabel;


- (IBAction)useCamera:(id)sender;
- (IBAction)useCameraRoll:(id)sender;

@property (nonatomic, retain) IBOutlet UILabel *text;

@end
