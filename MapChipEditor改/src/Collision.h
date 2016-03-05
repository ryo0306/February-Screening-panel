#pragma once
#include "ScreenMake.h"

namespace Collision
{

  bool BoxtoBox(Vec2f pos1_, Vec2f size1_, Vec2f pos2_, Vec2f size2_);
  bool BoxtoMouse(Vec2f pos1_, Vec2f size1_, Vec2f pos2_, Vec2f size2_);
}