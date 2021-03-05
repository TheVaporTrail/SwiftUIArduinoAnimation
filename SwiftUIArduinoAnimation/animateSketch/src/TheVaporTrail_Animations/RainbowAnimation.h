// RainbowAnimation.h

#ifndef RAINBOWANIMATION_H
#define RAINBOWANIMATION_H

#include "../TheVaporTrail_AnimationTools/base/TheVaporTrail_Animation.h"

class RainbowAnimation: public TheVaporTrail_Animation {

	public:
		RainbowAnimation(void);
		~RainbowAnimation(void);
		
		void reset(void) override;
	
		void render(void) override;
	
		void advance(void) override;
		
	private:
		uint16_t _position;
};



#endif // RAINBOWANIMATION_H
