#include "Pendulum.h"

Pendulum::Pendulum(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                 ������                    //
//-------------------------------------------//
void Pendulum::SetUp()
{
  color = Color::magenta;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
void Pendulum::Update()
{

}
