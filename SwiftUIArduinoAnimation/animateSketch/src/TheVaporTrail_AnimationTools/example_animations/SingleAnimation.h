// SingleAnimation.h

#ifndef SINGLEANIMATION_H
#define SINGLEANIMATION_H

#include "../base/TheVaporTrail_Animation.h"

class SingleAnimation: public TheVaporTrail_Animation {

	public:
		SingleAnimation(void);
		~SingleAnimation(void);
		
		void reset(void) override;
	
		void render(void) override;
	
		void advance(void) override;
		
	private:
		uint32_t _color;
		uint16_t _position;
		uint16_t _width;
};



#endif // SINGLEANIMATION_H
