//
//  Animate.cpp
//  IntegrationTest
//
//  Created by David Kaufman on 2/24/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

#include "Animate.hpp"

#include "TheVaporTrail_Animator_Pixels.h"
#include "MarqueeAnimation.h"
#include "SingleAnimation.h"
#include "RainbowAnimation.h"

//----------------------------------------
// Animator initialization
//----------------------------------------
TheVaporTrail_Animator_Pixels animator = TheVaporTrail_Animator_Pixels();

//----------------------------------------
// Animations
//----------------------------------------
MarqueeAnimation marquee = MarqueeAnimation();
SingleAnimation single = SingleAnimation();
RainbowAnimation rainbow = RainbowAnimation();

//----------------------------------------
// Global
//----------------------------------------
uint32_t count = 0;


//----------------------------------------
// Functions
//----------------------------------------


void animate_setup(void)
{
    animator.addAnimation(&marquee);
    animator.addAnimation(&rainbow);
    animator.addAnimation(&single);
}

void animate_render(uint32_t *pixels)
{
    animator.clear();

    animator.render();
    
    animator.show();
    
    animator.getPixels(pixels);

}

void animate_step(void)
{
    animator.advance();
    
    count++;
    
    if (count >= 25)
    {
        count = 0;
        animator.next();
    }
}

void animate_set_pixel_count(uint32_t pixelCount)
{
 	animator.setPixelCount(pixelCount);
}
