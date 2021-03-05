//
//  Animate.hpp
//  IntegrationTest
//
//  Created by David Kaufman on 2/24/21.
//  Copyright © 2021 TheVaporTrail. All rights reserved.
//

#ifndef Animate_hpp
#define Animate_hpp

#include <stdio.h>
#include "TheVaporTrail_Animator.h"


void animate_setup(void);
void animate_set_pixel_count(uint32_t pixelCount);
void animate_render(uint32_t *pixels);
void animate_step(void);

#endif /* Animate_hpp */


