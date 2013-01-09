//
//  ViewController.m
//  TopDemoApp
//
//  Created by fangweng on 12-12-26.
//  Copyright (c) 2012年 fangweng. All rights reserved.
//

#import "ViewController.h"
#import "TopSDKBundle.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize userIds;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
    [_requestInputText release];
    [_authBtn release];
    [_userIdText release];
    [_uploadPicBtn release];
    [_sendRequestBtn release];
    [_tqlBtn release];
    [_responseView release];
    [super dealloc];
}
- (void)viewDidUnload {
    [self setRequestInputText:nil];
    [self setAuthBtn:nil];
    [self setUserIdText:nil];
    [self setUploadPicBtn:nil];
    [self setSendRequestBtn:nil];
    [self setTqlBtn:nil];
    [self setResponseView:nil];
    [super viewDidUnload];
}
- (IBAction)dismissInput:(id)sender {
    
    [sender resignFirstResponder];
}

- (IBAction)authAction:(id)sender {
    TopIOSClient *iosClient = [TopIOSClient getIOSClientByAppKey:@"12642644"];
    
    [iosClient auth:self cb:@selector(authCallback:)];
}

- (IBAction)tqlRequest:(id)sender {
    
    TopIOSClient *iosClient = [TopIOSClient getIOSClientByAppKey:@"12642644"];
    
    NSMutableDictionary *params = [[NSMutableDictionary alloc] init];
    
    NSString *uid = [_userIdText text];
    
    [params setValue:@"select num_iid,title,nick,pic_url,cid,price,type,delist_time,post_fee from item where num_iid=17795332215" forKey:@"ql"];
    
    //异步模式
    //[iosClient tql:@"GET" params:params target:self cb:@selector(showApiResponse:) userId:uid needMainThreadCallBack:true];
    
    //同步模式
    TopApiResponse * response = [iosClient tql:@"GET" params:params userId:uid];
    
    [_responseView setText:[response content]];
    
    //再增加一个对于sechedule的测试
    [params removeAllObjects];
    [params setValue:@"select num_iid,title,nick,pic_url,cid,price,type,delist_time,post_fee from item where num_iid=17795332215" forKey:@"ql"];
    [params setValue:@"2012-10-10 13:00:20" forKey:@"schedule"];
    [params setValue:@"http://10.13.201.118:7777" forKey:@"callbackurl"];
    
    response = [iosClient schedule:@"GET" params:params userId:uid];
    
    if ([response error])
        NSLog(@"schedule api call result : %@",[response error]);
    else
        NSLog(@"schedule api call result : %@",[response content]);
    
}

- (IBAction)uploadPicAction:(id)sender {
    
    NSString *uid = [_userIdText text];
    //NSString *uid = @"2026680875";
    
    NSMutableDictionary *params = [[NSMutableDictionary alloc]init];
    
    [params setObject:@"taobao.item.img.upload" forKey:@"method"];
    [params setObject:@"17795332215" forKey:@"num_iid"];
    
    
    NSURL *url = [[NSURL alloc] initWithString:@"http://upload.wikimedia.org/wikipedia/commons/d/de/POL_apple.jpg"];
    NSData *image_data = [NSData dataWithContentsOfURL:url];
    
    TopAttachment *image = [[TopAttachment alloc]init];
    [image setData:image_data];
    [image setName:@"apple.jpg"];
    
    
    [params setObject:image forKey:@"image"];
    
    TopIOSClient *iosClient =[TopIOSClient getIOSClientByAppKey:@"12642644"];
    
    
    [iosClient api:@"POST" params:params target:self cb:@selector(showApiResponse:) userId:uid needMainThreadCallBack:true];
    
}

- (IBAction)sendRequestAction:(id)sender {
    
    [_responseView setText:nil];
    
    NSString *requestStr = _requestInputText.text;
    NSString *uid = [_userIdText text];
    
    if (requestStr && [requestStr length] > 0)
    {
        NSMutableDictionary *params = [[NSMutableDictionary alloc]init];
        
        NSEnumerator *er = [[requestStr componentsSeparatedByString:@"&"] objectEnumerator];
        
        id anObject;
        
        while (anObject = [er nextObject]) {
            
            NSArray *arr = [(NSString *)anObject componentsSeparatedByString:@"="];
            
            if ([arr count] != 2)
            {
                continue;
            }
            
            [params setObject:[arr objectAtIndex:1] forKey:[arr objectAtIndex:0]];
        }
        
        
        TopIOSClient *iosClient =[TopIOSClient getIOSClientByAppKey:@"12642644"];
        
        [iosClient api:@"GET" params:params target:self cb:@selector(showApiResponse:) userId:uid needMainThreadCallBack:true];
        
    }
    else {
        
        [self message:@"必须填入请求地址."];
    }
    
}

-(void) message:(NSString *)content
{
    UIAlertView *message = [[UIAlertView alloc] initWithTitle:@"Infomation"
                                                      message:content
                                                     delegate:nil
                                            cancelButtonTitle:@"OK"
                                            otherButtonTitles:nil];
    
    [message show];
}

-(void)showApiResponse:(id)data
{
    if ([data isKindOfClass:[TopApiResponse class]])
    {
        TopApiResponse *response = (TopApiResponse *)data;
        
        if ([response content])
        {
            NSLog(@"%@",[response content]);
            [_responseView setText:[response content]];
        }
        else {
            NSLog(@"%@",[(NSError *)[response error] userInfo]);
        }
        
        NSDictionary *dictionary = (NSDictionary *)[response reqParams];
        
        for (id key in dictionary) {
            
            NSLog(@"key: %@, value: %@", key, [dictionary objectForKey:key]);
            
        }
    }
    
}

-(void) authCallback:(id)data
{
    if ([data isKindOfClass:[TopAuth class]])
    {
        TopAuth *auth = (TopAuth *)data;
        
        [userIds addObject:[auth user_id]];
        
        NSLog(@"%@",[auth user_id]);
        
        [_userIdText setText:[auth user_id]];
    }
    else
    {
        NSLog(@"%@",data);
    }
    
}

@end
