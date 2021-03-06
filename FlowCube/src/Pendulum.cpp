#include "Pendulum.h"

PendulumObject::PendulumObject(Vec2f pos_, PendulumKey Key_)
{
  key = Key_;
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                 初期化                    //
//-------------------------------------------//
void PendulumObject::SetUp()
{
  color = Color::magenta;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void PendulumObject::Update()
{

}


void PendulumObject::Draw()
{

  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
  if (key)
    drawCircle(pos.x() + size.x() / 2, pos.y() + size.y() / 2, size.x() / 2, size.y() / 2, 20, 5, Color::white);
}
