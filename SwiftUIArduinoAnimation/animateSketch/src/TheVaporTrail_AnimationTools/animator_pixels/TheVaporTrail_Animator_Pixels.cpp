// TheVaporTrail_Animator_Pixels.cpp

#include "TheVaporTrail_Animator_Pixels.h"

#define INITIAL_LED_COUNT 32

TheVaporTrail_Animator_Pixels::TheVaporTrail_Animator_Pixels(void)
{
	_length = INITIAL_LED_COUNT;
}

TheVaporTrail_Animator_Pixels::~TheVaporTrail_Animator_Pixels(void)
{
}

void TheVaporTrail_Animator_Pixels::setPixelCount(uint32_t pixelCount)
{
    _length = pixelCount;
}

void TheVaporTrail_Animator_Pixels::setPixel(uint16_t position, uint32_t color)
{
	pixels[position % _length] = color;
}

uint32_t TheVaporTrail_Animator_Pixels::getPixel(uint16_t position)
{
    return pixels[position];
}

void TheVaporTrail_Animator_Pixels::setColor(uint32_t position, uint32_t color)
{
}

void TheVaporTrail_Animator_Pixels::getPixels(uint32_t* pixelsOut)
{
    for (int i = 0; i < _length; i++)
        pixelsOut[i] = pixels[i];

}
void TheVaporTrail_Animator_Pixels::clear(void)
{
    for (int i = 0; i < _length; i++)
        pixels[i] = 0;
}

void TheVaporTrail_Animator_Pixels::show(void)
{
    
}
