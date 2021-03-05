// RainbowAnimation.cpp

#include "RainbowAnimation.h"
#include "../TheVaporTrail_AnimationTools/utils/TheVaporTrail_ColorUtils.h"

RainbowAnimation::RainbowAnimation(void)
{
	_position = 0;
}

RainbowAnimation::~RainbowAnimation(void)
{
}

void RainbowAnimation::reset(void)
{
	_position = 0;
}

void RainbowAnimation::render(void)
{
    uint32_t l = length();
    for (uint32_t i = 0; i < l; i++)
    {
        uint32_t clr;
        uint32_t h;
        h = (i * 255)/l;
        clr = CalcColor(h + _position);
        setPixel(i, clr);
    }
}

void RainbowAnimation::advance(void)
{
	_position += 8;
	
	if (_position >= 255)
		_position = 0;
}

