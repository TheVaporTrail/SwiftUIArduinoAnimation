//========================================================================================
//
// TheVaporTrail Animate Framework test
//
//   Tests Animator & Animation classes
//
//----------------------------------------------------------------------------------------
// (c) 2021 David Kaufman
// Released under the MIT license
// https://github.com/TheVaporTrail/TheVaporTrail_SubPixel
//========================================================================================

#include <Adafruit_NeoPixel.h>

#include "src/TheVaporTrail_Animator_NeoPixel/TheVaporTrail_Animator_NeoPixel.h"

#include "src/TheVaporTrail_AnimationTools/example_animations/SingleAnimation.h"
#include "src/TheVaporTrail_Animations/RainbowAnimation.h"
#include "src/TheVaporTrail_Animations/MarqueeAnimation.h"

//----------------------------------------
// Adafruit NeoPixel initialization
//----------------------------------------
#define LED_PIN    2
#define LED_COUNT  32
#define LED_TYPE  (NEO_GRB + NEO_KHZ800)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, LED_TYPE);

//----------------------------------------
// Animator initialization
//----------------------------------------
TheVaporTrail_Animator_NeoPixel animator = TheVaporTrail_Animator_NeoPixel(&strip);

//----------------------------------------
// Animations
//----------------------------------------
SingleAnimation  single = SingleAnimation();
MarqueeAnimation marquee = MarqueeAnimation();
RainbowAnimation rainbow = RainbowAnimation();

//----------------------------------------
// Arduino Set-up
//----------------------------------------
void setup()
{
	strip.begin();

	animator.addAnimation(&single);
	animator.addAnimation(&marquee);
	animator.addAnimation(&rainbow);
}

//----------------------------------------
// Arduino Loop
//----------------------------------------
void loop()
{
	static uint32_t count = 0;
	
	animator.clear();

	animator.render();
	
	animator.show();

	delay(250);

	animator.advance();
	
	count++;
	if (count > 30)
	{
		count = 0;
		animator.next();
	}
}
