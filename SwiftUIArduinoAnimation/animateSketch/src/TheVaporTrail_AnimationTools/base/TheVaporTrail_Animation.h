// TheVaporTrail_Animation.h

#ifndef THEVAPORTRAIL_ANIMATION_H
#define THEVAPORTRAIL_ANIMATION_H

#include "TheVaporTrail_Types.h"

class TheVaporTrail_Animation;
class TheVaporTrail_Animator;

#include "TheVaporTrail_Animator.h"

class TheVaporTrail_Animation {

	public:
		TheVaporTrail_Animation(void);
		~TheVaporTrail_Animation(void);
		
		void setAnimator(TheVaporTrail_Animator* animator);
		
		virtual void init(void);
	
		virtual void reset(void); 

		virtual void render(void);
	
		virtual void advance(void);
		
	private:
		TheVaporTrail_Animator* _animator;


	protected:
	
		uint16_t length(void);
		
		void setPixel(uint16_t position, uint32_t color);
			
		uint32_t setPixel(uint16_t position);
	
		void setColor(uint32_t position, uint32_t color);

};



#endif // THEVAPORTRAIL_ANIMATION_H
