// TheVaporTrail_Animator_NeoPixel.h

#ifndef THEVAPORTRAIL_ANIMATOR_NEOPIXEL_H
#define THEVAPORTRAIL_ANIMATOR_NEOPIXEL_H

#include "../TheVaporTrail_AnimationTools/base/TheVaporTrail_Animator.h"
#include <Adafruit_NeoPixel.h>

class TheVaporTrail_Animator_NeoPixel: public TheVaporTrail_Animator {

	public:
		TheVaporTrail_Animator_NeoPixel(Adafruit_NeoPixel* _neopixel);
		~TheVaporTrail_Animator_NeoPixel(void);
	
		inline void clear(void) { _neopixel->clear(); }
		inline void show(void)  { _neopixel->show(); }

		void setPixel(uint16_t position, uint32_t color);
		uint32_t getPixel(uint16_t position);
	
		void setColor(uint32_t position, uint32_t color);

	private:
		Adafruit_NeoPixel* _neopixel;
};



#endif // THEVAPORTRAIL_ANIMATOR_NEOPIXEL_H