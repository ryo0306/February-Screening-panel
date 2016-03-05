#pragma once
#include "ScreenMake.h"
#include "Collision.h"

class Knob
{
public:
  Knob(){};
  // float max_     �Ώە��͈̔͂̍ő�l
  // float min_     �Ώە��͈̔͂̍ŏ��l
  void SetUp(float max_, float min_, float smax_, float smin_, Vec2f pos0_);
  void Draw();
  // float& scrollObject_  �X�N���[������Ώە�
  void Update(float& scrollObject_);
  void MoveLimit();
  void SetPos(Vec2f pos_){ scrollPos = pos_; }
  Vec2f GetSize(){ return size; }
private:
  Vec2f mousePos;
  float max;
  float min;
  float smax;
  float smin;
  float amountChnage;
  float sAmountChnage;
  float scrollPostoscrollPos;
  Vec2f scrollPos;
  Vec2f size;
  Vec2f putPos;
  bool active;
};