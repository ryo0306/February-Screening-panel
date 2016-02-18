#include "UiBox.h"

UiBox::UiBox()
{
  pos = Vec2f(0,0);
  size = Vec2f(UIBOX_SIZE,UIBOX_SIZE);
  num = 0;
  clear = false;
}


//-------------------------------------------//
//                 初期化                    //
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
  α = 0;
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void UiBox::Update()
{
  if (selectNow)
  {
    if (α <= 0)
    {
      αSpeed = SPEED;
    }
    if (α >= 0.5f)
    {
      αSpeed = -SPEED;
    }
    α += αSpeed;
  }
  else
  {
    α = 0;
  }
}


//-------------------------------------------//
//              　 全体の描画                 //
//-------------------------------------------//
void UiBox::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color(1.0f,1.0f,1.0f,α));
  if (!clear)
  {
    drawLine(pos.x(), pos.y(), pos.x() + size.x(), pos.y() + size.y(), 10, Color::white);
    drawLine(pos.x(), pos.y() + size.y(), pos.x() + size.x(), pos.y(), 10, Color::white);
    drawLine(pos.x(), pos.y(), pos.x() + size.x(), pos.y() + size.y(), 5, Color::red);
    drawLine(pos.x(), pos.y() + size.y(), pos.x() + size.x(), pos.y(), 5, Color::red);
  }
  drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white);
}