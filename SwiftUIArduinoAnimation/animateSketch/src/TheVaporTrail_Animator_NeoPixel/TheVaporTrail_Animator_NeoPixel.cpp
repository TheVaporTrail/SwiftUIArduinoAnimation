// TheVaporTrail_Animator.cpp

#include "TheVaporTrail_Animator_NeoPixel.h"


TheVaporTrail_Animator_NeoPixel::TheVaporTrail_Animator_NeoPixel(Adafruit_NeoPixel* neopixel)
{
	_neopixel = neopixel;
	_length = _neopixel->numPixels();
}

TheVaporTrail_Animator_NeoPixel::~TheVaporTrail_Animator_NeoPixel(void)
{
}

void TheVaporTrail_Animator_NeoPixel::setPixel(uint16_t position, uint32_t color)
{
	_neopixel->setPixelColor(position, color);
}

uint32_t TheVaporTrail_Animator_NeoPixel::getPixel(uint16_t position)
{
	return _neopixel->getPixelColor(position);
}

void TheVaporTrail_Animator_NeoPixel::setColor(uint32_t position, uint32_t color)
{
}

