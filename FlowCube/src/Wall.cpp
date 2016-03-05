#include "Wall.h"


Wall::Wall(Vec2f pos_)
{
  pos = pos_;
  SetUp();
}

//-------------------------------------------//
//                  ������                   //
//-------------------------------------------//
void Wall::SetUp()
{
  color = Color::navy;
  //TODO:define�ɂ���B
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
}

//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
void Wall::Update()
{

}


void Wall::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
}