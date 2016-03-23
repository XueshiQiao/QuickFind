//
//  QuickFind.h
//  QuickFind
//
//  Created by Joey on 11/29/14.
//  Copyright (c) 2014 www.joeyio.com. All rights reserved.
//

#import <AppKit/AppKit.h>

@class QuickFind;

static QuickFind *sharedPlugin;

@interface QuickFind : NSObject

+ (instancetype)sharedPlugin;
- (id)initWithBundle:(NSBundle *)plugin;

@property (nonatomic, strong, readonly) NSBundle* bundle;
@end