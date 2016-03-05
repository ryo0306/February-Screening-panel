#pragma once
#include "ScreenMake.h"
#define UIBOX_SIZE 200
#define SPEED 0.01f

class UiBox
{
public:

  UiBox();
  void SetUp(int num_, Color color_);
  void Update();
  void Draw();
  Vec2f GetPos(){ return pos; }
  Vec2f GetSize(){ return size; }
  void SetPos(Vec2f pos_){ pos = Vec2f(pos_.x() - size.x()/2 ,pos_.y()); }
  void SetSize(Vec2f size_){ size = size_; }
  void SetSelectActive(bool selectNow_){ selectNow = selectNow_; }
  int GetNum(){ return num; }
  void SetClear(bool clear_){ clear = clear_; }
private:
  int num;
  float ƒ¿;
  float ƒ¿Speed;
  bool selectNow;
  bool clear;
  Vec2f pos;
  Vec2f size;
  Color color;
  Font font = Font("res/meiryo.ttc");
};