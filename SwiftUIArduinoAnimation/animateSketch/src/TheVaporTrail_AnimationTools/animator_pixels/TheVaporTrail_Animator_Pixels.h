// TheVaporTrail_Animator_Data.h

#ifndef THEVAPORTRAIL_ANIMATOR_PIXELS_H
#define THEVAPORTRAIL_ANIMATOR_PIXELS_H

#include "../base/TheVaporTrail_Animator.h"

#define MAX_LED_COUNT 1000

class TheVaporTrail_Animator_Pixels: public TheVaporTrail_Animator {

	public:
		TheVaporTrail_Animator_Pixels();
		~TheVaporTrail_Animator_Pixels(void);
	
        void clear(void);
        void show(void);

		void setPixel(uint16_t position, uint32_t color);
		uint32_t getPixel(uint16_t position);
	
		void setColor(uint32_t position, uint32_t color);
    
        void getPixels(uint32_t* pixels);
        void setPixelCount(uint32_t pixelCount);

	private:
        uint32_t pixels[MAX_LED_COUNT];
};



#endif // THEVAPORTRAIL_ANIMATOR_PIXELS_H
