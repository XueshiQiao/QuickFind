//
//  QuickFind.h
//  QuickFind
//
//  Created by Joey on 11/29/14.
//  Copyright (c) 2014 www.joeyio.com. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface QuickFind : NSObject

+ (instancetype)sharedPlugin;

@property (nonatomic, strong, readonly) NSBundle* bundle;
@end