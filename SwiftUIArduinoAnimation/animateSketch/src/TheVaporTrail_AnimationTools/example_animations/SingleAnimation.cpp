// SingleAnimation.cpp

#include "SingleAnimation.h"

SingleAnimation::SingleAnimation(void)
{
	_color = 0x00ffff;
	_position = 0;
	_width = 1;
}

SingleAnimation::~SingleAnimation(void)
{
}

void SingleAnimation::reset(void)
{
	_position = 0;
}

void SingleAnimation::render(void)
{
    #define OFFSET 10
    
	setPixel(_position, _color);
    
    //setPixel(_position + OFFSET, 0x00ff00);
}

void SingleAnimation::advance(void)
{
	_position += 1;
	
	if (_position >= length())
		_position = 0;
}

