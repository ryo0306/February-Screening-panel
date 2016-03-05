#pragma once
#include "ScreenMake.h"

class Icon
{
public:
  Icon(Vec2f pos_, Vec2f size_);
  void SetUp(Color backColor_);
  void Draw();
  void Update();
  void SetPos(Vec2f pos_){ pos = pos_; }
  bool GetActive(){ return active; };
  Vec2f GetPos(){ return pos;}
  Vec2f GetSize(){ return size;}
  void SetActive(bool active_){ active = active_; }
private:
  Vec2f pos;
  Vec2f size;
  Color backColor;
  Color frameColor;
  bool active;
};