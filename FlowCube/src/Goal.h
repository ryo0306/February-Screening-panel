#pragma once
#include "Object.h"

class Goal : public Object
{
public:
  Goal(){}
  Goal(Vec2f pos_);
  void SetUp();
  void Update();
  void Draw();
private:
  Color color;
};