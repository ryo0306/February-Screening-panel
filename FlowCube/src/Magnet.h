#pragma once
#include "Wall.h"
#define MAGNET_POWER 2

class Magnet : public Wall
{
public:
  Magnet(Vec2f pos_);
  void SetUp();
  void Update();
 
private:
};