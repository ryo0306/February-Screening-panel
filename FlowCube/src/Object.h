#pragma once
#include "ScreenMake.h"
#include "common.h"

class Object
{
public:
  Object(){};
  virtual void SetUp(){};
  virtual void Update(){};
  virtual void Draw(){};
  virtual Vec2f GetPos(){ return pos; }
  virtual Vec2f GetSize(){ return size; }
  virtual void SetPos(Vec2f pos_){ pos = pos_; }
  virtual void SetSize(Vec2f size_){ size = size_; }
protected:
  Vec2f pos;
  Vec2f size;
};