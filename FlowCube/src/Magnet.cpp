#include "Magnet.h"

Magnet::Magnet(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                 初期化                    //
//-------------------------------------------//
void Magnet::SetUp()
{
  color = Color::blue;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void Magnet::Update()
{

}
