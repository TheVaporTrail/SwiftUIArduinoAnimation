//
//  AnimateWrapper.m
//  IntegrationTest
//
//  Created by David Kaufman on 2/24/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AnimateWrapper.h"
#import "Animate.hpp"

@implementation AnimateWrapper

- (void) setup {
    animate_setup();
}

- (uint32_t*) render {
    static uint32_t pixels[1000];

    animate_render(pixels);
    return pixels;
}

- (void) step {
    animate_step();
}

- (void) setPixelCount: (uint32_t) pixelCount {
    animate_set_pixel_count(pixelCount);
}

@end
