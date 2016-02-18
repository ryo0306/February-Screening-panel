#include "UiBox.h"

UiBox::UiBox()
{
  pos = Vec2f(0,0);
  size = Vec2f(UIBOX_SIZE,UIBOX_SIZE);
  num = 0;
  clear = false;
}


//-------------------------------------------//
//                 ������                    //
//-------------------------------------------//
void UiBox::SetUp(int num_, Color color_)
{
  pos = Vec2f(0, 0);
  num = num_;
  color = color_;
  size = Vec2f(UIBOX_SIZE, UIBOX_SIZE);
  num = 0;
  clear = false;
  selectNow = false;
  �� = 0;
}

//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
void UiBox::Update()
{
  if (selectNow)
  {
    if (�� <= 0)
    {
      ��Speed = SPEED;
    }
    if (�� >= 0.5f)
    {
      ��Speed = -SPEED;
    }
    �� += ��Speed;
  }
  else
  {
    �� = 0;
  }
}


//-------------------------------------------//
//              �@ �S�̂̕`��                 //
//-------------------------------------------//
void UiBox::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color(1.0f,1.0f,1.0f,��));
  if (!clear)
  {
    drawLine(pos.x(), pos.y(), pos.x() + size.x(), pos.y() + size.y(), 10, Color::white);
    drawLine(pos.x(), pos.y() + size.y(), pos.x() + size.x(), pos.y(), 10, Color::white);
    drawLine(pos.x(), pos.y(), pos.x() + size.x(), pos.y() + size.y(), 5, Color::red);
    drawLine(pos.x(), pos.y() + size.y(), pos.x() + size.x(), pos.y(), 5, Color::red);
  }
  drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white);
}