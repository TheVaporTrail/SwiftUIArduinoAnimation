// MarqueeAnimation.h

#ifndef MARQUEEANIMATION_H
#define MARQUEEANIMATION_H

#include "../TheVaporTrail_AnimationTools/base/TheVaporTrail_Animation.h"

class MarqueeAnimation: public TheVaporTrail_Animation {

	public:
		MarqueeAnimation(void);
		~MarqueeAnimation(void);
		
		void reset(void) override;
	
		void render(void) override;
	
		void advance(void) override;
		
	private:
		uint32_t _color;
		uint16_t _position;
        uint16_t _spacing;
};



#endif // MARQUEEANIMATION_H