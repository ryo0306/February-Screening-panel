#pragma once
#include "Wall.h"

class Pendulum : public Wall
{
public:
  Pendulum(Vec2f pos_);
  void SetUp();
  void Update();
  
private:
};