//
//  ViewController.m
//  ASCDemo
//
//  Created by Joseph Lee on 2020/7/8.
//  Copyright © 2020 Alo7. All rights reserved.
//

#import "ViewController.h"
#import <ASC_EXT/ASC_EXT.h>
#import "AFNetworking.h"

@interface ViewController ()<ASCSessionDelegate, ASCSessionPlayerDelegate>

@property(strong, nonatomic) ASCSession *session;

@property(copy, nonatomic) NSString *appId;
@property(copy, nonatomic) NSString *appSec;
@property(copy, nonatomic) NSString *iFlyAppId;
@property(copy, nonatomic) NSString *ssAppKey;
@property(copy, nonatomic) NSString *ssAppSec;
@property(copy, nonatomic) NSString *studentId;
@property(copy, nonatomic) NSString *lessonId;
@property(copy, nonatomic) NSString *interactiveURLString;
@property(copy, nonatomic) NSString *lessonMode;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
    return UIInterfaceOrientationPortrait;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

- (IBAction)click:(id)sender {
    NSDictionary *context = @{
        iflytekAppId: [self noEmptyValueForTextField:_iFlyAppIdTextField orDefaultValue:_iFlyAppId],
        singsoundKey: [self noEmptyValueForTextField:_ssAppKeyTextField orDefaultValue:_ssAppKey],
        singsoundSecret: [self noEmptyValueForTextField:_ssAppSecTextField orDefaultValue:_ssAppSec],
    };

    [ASCSDK initialize:context];

    self.session = [[ASCSession alloc] initLessonId:[_lessonIdTextField.text intValue]];
    self.session.userId = _studentIdTextField.text;
    self.session.mode = [[self noEmptyValueForTextField:_lessonModeTextField orDefaultValue:_lessonMode] intValue];
    self.session.delegate = self;
    self.session.playerDelegate = self;
    
    __weak typeof(self) weakSelf = self;
    [self requestTokenWithCallback:^(NSString *token) {
        weakSelf.session.token = token;
        [ASCSDK startBySession:weakSelf.session fromViewController:weakSelf];
    }];
}

- (void)requestTokenWithCallback:(void (^)(NSString *token))callback {
    NSDictionary *parameter = @{
        @"app_id": [self noEmptyValueForTextField:_appKeyTextField orDefaultValue:_appId],
        @"app_secret": [self noEmptyValueForTextField:_appSecTextField orDefaultValue:_appSec]
    };

    NSString * requestURLStr = @"https://api.alo7.com/system/token";

    NSURLRequest *request = [[[AFHTTPRequestSerializer serializer] requestWithMethod:@"GET" URLString:requestURLStr parameters:parameter error:nil] copy];
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    AFURLSessionManager *manager = [[AFURLSessionManager alloc] initWithSessionConfiguration:configuration];

    NSURLSessionDataTask *dataTask = [manager dataTaskWithRequest:request uploadProgress:nil downloadProgress:nil completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
        if (error) {
            NSLog(@"Error: %@", error);
            callback(nil);
        } else {
            NSLog(@"%@ %@", response, responseObject);
            NSString *token = (NSString *)[(NSDictionary *)responseObject objectForKey:@"token"];
            if (token && ![token isEqual:[NSNull null]]) {
                callback(token);
            } else {
                callback(nil);
            }
        }
    }];

    [dataTask resume];
}

- (NSString *)noEmptyValueForTextField:(UITextField *)textField orDefaultValue:(NSString *)value {
    if (!textField.text || [textField.text length] <= 0) {
        return value;
    }

    return textField.text;
}

-(void)ascSession:(ASCSession *)session didOccurError:(ASCErrorCode)errorCode {
    
}

- (void)ascSession:(ASCSession *)session playEvent:(ASCEventType)event{

}

- (void)onBufferedPositionUpdate:(ASCSession *)session position:(int64_t)position {
    
}

- (void)onCurrentPositionUpdate:(ASCSession *)session position:(int64_t)position {
    
}

@end
