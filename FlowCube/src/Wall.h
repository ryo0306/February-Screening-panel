#pragma once
#include "Object.h"

class Wall : public Object
{
public:
  Wall(){}
  Wall(Vec2f pos_);
  virtual void SetUp();
  virtual void Update();
  virtual void Draw();
protected:
  Color color;
};