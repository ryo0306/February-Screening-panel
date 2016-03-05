#include "PendulumAction.h"


Vec2f Pendulum::Gravity(Vec2f pos_, Vec2f sPos_, float& rotate_, float& rotateS_, float length_)
{

  Vec2f putPos = pos_;
  // 現在の角度
  float rad = rotate_ * M_PI / 180;

  // 現在の重りの位置
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // 重りと支点との距離を算出
  float vx = putPos.x() - sPos_.x();
  float vy = putPos.y() - sPos_.y();

  //？
  float t = -(vy * GRAVITY) / (vx * vx + vy * vy);

  // 重力移動量を反映した重りの位置
  float gx = putPos.x() + t * vx;
  float gy = putPos.y() + GRAVITY + t * vy;

  // ２つの重りの位置の角度差
  float r = atan2(gy - sPos_.y(), gx - sPos_.x()) * 180 / M_PI;

  //現在の角度二つの重りの角度差との差を算出
  float sub = r - rotate_;
  //角度の誤差をfloorで修正
  sub -= floor(sub / 360.0) * 360.0;


  // 角度差を角速度に加算
  if (sub <-180.0)	sub += 360.0;
  if (sub > 180.0)	sub -= 360.0;
  rotateS_ += sub;

  // 摩擦
  //	rot_spd *= 0.995;

  // 角度に角速度を加算
  rotate_ += rotateS_;

  // 新しい重りの位置
  rad = rotate_ * M_PI / 180;
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // 重りの座標

  return putPos;
}


Vec2f Pendulum::AnGravity(Vec2f pos_, Vec2f sPos_, float& rotate_, float& rotateS_, float length_)
{

  Vec2f putPos = pos_;
  // 現在の角度
  float rad = rotate_ * M_PI / 180;

  // 現在の重りの位置
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // 重りと支点との距離を算出
  float vx = putPos.x() - sPos_.x();
  float vy = putPos.y() - sPos_.y();

  //？
  float t = -(vy * 0) / (vx * vx + vy * vy);

  // 重力移動量を反映した重りの位置
  float gx = putPos.x() + t * vx;
  float gy = putPos.y() + t * vy;

  // ２つの重りの位置の角度差
  float r = atan2(gy - sPos_.y(), gx - sPos_.x()) * 180 / M_PI;

  //現在の角度二つの重りの角度差との差を算出
  float sub = r - rotate_;
  //角度の誤差をfloorで修正
  sub -= floor(sub / 360.0) * 360.0;


  // 角度差を角速度に加算
  if (sub <-180.0)	sub += 360.0;
  if (sub > 180.0)	sub -= 360.0;
  rotateS_ += sub;

  // 摩擦
  //	rot_spd *= 0.995;

  // 角度に角速度を加算
  rotate_ += rotateS_;

  // 新しい重りの位置
  rad = rotate_ * M_PI / 180;
  putPos.x() = sPos_.x() + cos(rad) * length_;
  putPos.y() = sPos_.y() + sin(rad) * length_;

  // 重りの座標

  return putPos;
}

