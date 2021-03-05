// TheVaporTrail_Animator.h

#ifndef THEVAPORTRAIL_ANIMATOR_H
#define THEVAPORTRAIL_ANIMATOR_H

#include "TheVaporTrail_Types.h"

class TheVaporTrail_Animation;
class TheVaporTrail_Animator;


#include "TheVaporTrail_Animation.h"

#define MAX_ANIMATIONS 10

class TheVaporTrail_Animator {

	public:
		TheVaporTrail_Animator(void);
		~TheVaporTrail_Animator(void);
	
		virtual void clear(void);
		
		virtual void show(void);

		virtual void setAlpha(uint8_t alpha);
	
		virtual void setPixel(uint16_t position, uint32_t color);
		
		virtual uint32_t getPixel(uint16_t position);
	
		virtual void setColor(uint32_t position, uint32_t color);
		
		void addAnimation(TheVaporTrail_Animation* animation);
		
		virtual void render(void);
		
		virtual void advance(void);

		inline uint16_t length(void) { return _length; }

		void next(void);


	protected:
		uint8_t _precision;
		uint16_t _length;
		
	private:
		TheVaporTrail_Animation* _currentAnimation;
		TheVaporTrail_Animation* _nextAnimation;
		TheVaporTrail_Animation* _animationList[MAX_ANIMATIONS];
		uint8_t _count;
		uint8_t _current;
		
};



#endif // THEVAPORTRAIL_ANIMATOR_H
