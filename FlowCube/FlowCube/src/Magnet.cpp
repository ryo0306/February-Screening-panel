#include "Magnet.h"

Magnet::Magnet(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                 ������                    //
//-------------------------------------------//
void Magnet::SetUp()
{
  color = Color::blue;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
void Magnet::Update()
{

}
