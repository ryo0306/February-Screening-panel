#include "Pendulum.h"

Pendulum::Pendulum(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                 èâä˙âª                    //
//-------------------------------------------//
void Pendulum::SetUp()
{
  color = Color::magenta;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               ëSëÃÇÃçXêV                   //
//-------------------------------------------//
void Pendulum::Update()
{

}
