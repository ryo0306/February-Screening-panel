#pragma once
#include "ScreenMake.h"

class Object
{
public:
  Object(Color color_,Vec2f pos_, Vec2f size_);
  void Update();
  void Draw();
  Vec2f GetPos(){ return pos; }
  Vec2f GetSize(){ return size; }
private:
  Vec2f pos;
  Vec2f size;
  Color color;
};