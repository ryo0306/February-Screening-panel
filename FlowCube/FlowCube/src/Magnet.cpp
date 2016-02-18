#include "Magnet.h"

Magnet::Magnet(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                 èâä˙âª                    //
//-------------------------------------------//
void Magnet::SetUp()
{
  color = Color::blue;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               ëSëÃÇÃçXêV                   //
//-------------------------------------------//
void Magnet::Update()
{

}
