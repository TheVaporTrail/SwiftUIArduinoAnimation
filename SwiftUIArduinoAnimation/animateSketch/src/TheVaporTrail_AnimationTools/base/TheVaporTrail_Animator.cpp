// TheVaporTrail_Animator.cpp

#include "TheVaporTrail_Animator.h"


TheVaporTrail_Animator::TheVaporTrail_Animator(void)
{
	_length = 0;
	_precision = 0;
}

TheVaporTrail_Animator::~TheVaporTrail_Animator(void)
{
}

void TheVaporTrail_Animator::clear()
{
}

void TheVaporTrail_Animator::show()
{
}

void TheVaporTrail_Animator::setAlpha(uint8_t alpha)
{
}

void TheVaporTrail_Animator::setPixel(uint16_t position, uint32_t color)
{
}

uint32_t TheVaporTrail_Animator::getPixel(uint16_t position)
{
	return 0;
}

void TheVaporTrail_Animator::setColor(uint32_t position, uint32_t color)
{
}

void TheVaporTrail_Animator::addAnimation(TheVaporTrail_Animation* animation)
{
    if (_count < MAX_ANIMATIONS)
    {
        _animationList[_count] = animation;
        _count++;
        animation->setAnimator(this);
    }
    
    if (_currentAnimation == NULL)
    {
        _currentAnimation = animation;
        _current = 0;
    }
	
	
}

void TheVaporTrail_Animator::render(void)
{
	if (_currentAnimation != NULL)
		_currentAnimation->render();
}

void TheVaporTrail_Animator::advance(void)
{
	if (_currentAnimation != NULL)
		_currentAnimation->advance();
}


void TheVaporTrail_Animator::next(void)
{
    _current = (_current + 1) % _count;
    _currentAnimation = _animationList[_current];
}
