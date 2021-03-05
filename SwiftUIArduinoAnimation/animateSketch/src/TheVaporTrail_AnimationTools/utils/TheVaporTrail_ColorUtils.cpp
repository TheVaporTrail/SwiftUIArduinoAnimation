// TheVaporTrail_ColorUtils.cpp

#include "TheVaporTrail_ColorUtils.h"

//=================================================================================
//
//    Utilities
//
//=================================================================================

//---------------------------------------------------------------------------------
//    Calculate Color
//---------------------------------------------------------------------------------
uint32_t CalcColor(uint16_t hue, uint16_t range /*= 0xff*/, uint8_t brightness /*= 0xff*/)
{
  uint16_t phase = range/3;
  uint16_t r, g, b;

  hue = hue % range;
  
  if (hue < phase)
  {
    r = phase - hue;
    g = 0;
    b = hue;
  }
  else if (hue < 2*phase)
  {
    hue -= phase;
    r = 0;
    g = hue;
    b = phase - hue;
  }
  else
  {
    hue -= 2*phase;
    if (hue > phase)
        hue = phase;
    r = hue;
    g = phase - hue;
    b = 0;
  }

  r = ((uint32_t)r * brightness)/phase;
  g = ((uint32_t)g * brightness)/phase;
  b = ((uint32_t)b * brightness)/phase;

  return (uint32_t)r << 16 | (uint32_t)g << 8 | b;
}

