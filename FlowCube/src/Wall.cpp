#include "Wall.h"


Wall::Wall(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                  初期化                   //
//-------------------------------------------//
void Wall::SetUp()
{
  color = Color::navy;
  //TODO:defineにする。
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void Wall::Update()
{

}


void Wall::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
}