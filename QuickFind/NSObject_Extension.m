//
//  NSObject_Extension.m
//  QuickFind
//
//  Created by chars on 16/3/23.
//  Copyright © 2016年 chars. All rights reserved.
//


#import "NSObject_Extension.h"
#import "QuickFind.h"

@implementation NSObject (Xcode_Plugin_Template_Extension)

+ (void)pluginDidLoad:(NSBundle *)plugin
{
    static dispatch_once_t onceToken;
    NSString *currentApplicationName = [[NSBundle mainBundle] infoDictionary][@"CFBundleName"];
    if ([currentApplicationName isEqual:@"Xcode"]) {
        dispatch_once(&onceToken, ^{
            sharedPlugin = [[QuickFind alloc] initWithBundle:plugin];
        });
    }
}
@end
