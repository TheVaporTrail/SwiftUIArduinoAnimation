//
//  AnimateWrapper.h
//  IntegrationTest
//
//  Created by David Kaufman on 2/24/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

#ifndef AnimateWrapper_h
#define AnimateWrapper_h
#import <Foundation/Foundation.h>

@interface AnimateWrapper : NSObject
- (void) setup;
- (void) step;
- (uint32_t*) render;
- (void) setPixelCount: (uint32_t) pixelCount;
@end

#endif /* AnimateWrapper_h */
