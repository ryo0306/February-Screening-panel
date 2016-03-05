#include "Icon.h"

Icon::Icon(Vec2f pos_, Vec2f size_)
{
  pos = pos_;
  size = size_;
  active = false;
}

void Icon::SetUp(Color backColor_)
{
  backColor = backColor_;
}

void Icon::Update()
{

  if (active)
  {
    frameColor = Color::red;
  }
  else
  {
    frameColor = Color::white;
  }

}


void Icon::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), backColor);
  drawBox(pos.x(), pos.y(), size.x(), size.x(), 5, frameColor);
}
