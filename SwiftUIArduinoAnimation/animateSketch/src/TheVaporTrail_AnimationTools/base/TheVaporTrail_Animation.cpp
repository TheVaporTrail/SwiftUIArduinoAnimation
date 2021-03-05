// TheVaporTrail_Animation.cpp

#include "TheVaporTrail_Animation.h"


TheVaporTrail_Animation::TheVaporTrail_Animation(void)
{
}

TheVaporTrail_Animation::~TheVaporTrail_Animation(void)
{
}

void TheVaporTrail_Animation::setAnimator(TheVaporTrail_Animator* animator)
{
	_animator = animator;
}

void TheVaporTrail_Animation::init(void)
{
}

void TheVaporTrail_Animation::reset(void)
{
}

void TheVaporTrail_Animation::render(void)
{
}

void TheVaporTrail_Animation::advance(void)
{
}


void TheVaporTrail_Animation::setPixel(uint16_t position, uint32_t color)
{
	_animator->setPixel(position, color);
};

uint16_t TheVaporTrail_Animation::length(void)
{
	return _animator->length();
}
