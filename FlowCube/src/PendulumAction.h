#pragma once
#include "ScreenMake.h"
// 仮で置く
// 重力が変化するようなら引数に入れる
#define GRAVITY (-0.2f)

enum PendulumKey
{
  PRIGHT = -1,
  PLEFT = 1,
};

namespace Pendulum
{
  // 重力あり
  // Vec2f pos_        物体の位置
  // Vec2f sPos_       支点の位置
  // float rotate_     現在の角度
  // float rotateS_    初角速度
  // flaot length_     物体と支点の距離
  Vec2f Gravity(Vec2f pos_, Vec2f sPos_, float& rotate_, float& rotateS_, float length_);

  // 重力なし
  // Vec2f pos_        物体の位置
  // Vec2f sPos_       支点の位置
  // float rotate_     現在の角度
  // float rotateS_    初角速度
  // flaot length_     物体と支点の距離
  Vec2f AnGravity(Vec2f pos_, Vec2f sPos_, float& rotate_, float& rotateS_, float length_);

}