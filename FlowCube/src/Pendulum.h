#pragma once
#include "Wall.h"
#include "PendulumAction.h"

class PendulumObject : public Wall
{
public:
  PendulumObject(Vec2f pos_, PendulumKey key_);
  void SetUp();
  void Update();
  void Draw();
  PendulumKey Getkey(){ return key; }
  
private:
  PendulumKey key;
};