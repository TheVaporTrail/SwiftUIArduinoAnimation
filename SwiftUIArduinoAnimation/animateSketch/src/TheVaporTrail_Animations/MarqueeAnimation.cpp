// MarqueeAnimation.cpp

#include "MarqueeAnimation.h"

MarqueeAnimation::MarqueeAnimation(void)
{
	_color = 0xff0000;
	_position = 0;
    _spacing = 4;
}

MarqueeAnimation::~MarqueeAnimation(void)
{
}

void MarqueeAnimation::reset(void)
{
	_position = 0;
}

void MarqueeAnimation::render(void)
{
	uint32_t l = length();
	for (uint32_t i = 0; i < l; i += _spacing)
		setPixel(i + _position, _color);
}

void MarqueeAnimation::advance(void)
{
	_position += 1;
	
	if (_position >= _spacing)
		_position = 0;
}

