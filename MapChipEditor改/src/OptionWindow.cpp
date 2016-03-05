#pragma once
#include "OptionWindow.h"

OptionWindow::OptionWindow()
{

}

void OptionWindow::SetUp(Vec2f pos_, Vec2f size_, Color backColor_)
{
  pos = pos_;
  size = size_;
  backColor = backColor_;
  iconPos = Vec2f(50, 0);
  for (int i = 0; i < ObjectNum; i++)
  {
    icons.push_back(Icon(Vec2f(pos.x() + iconPos.x(), pos.y() + iconPos.y() + i* ICON_SIZE * 2),
      Vec2f(ICON_SIZE, ICON_SIZE)));
  }
  tagSize = Vec2f(50, 50);
  tagPos = Vec2f(pos.x() - tagSize.x(), pos.y() + size.y() - tagSize.y());
  icons[0].SetUp(Color::white);
  icons[1].SetUp(Color::navy);
  icons[2].SetUp(Color::magenta);
  icons[3].SetUp(Color::blue);
  icons[4].SetUp(Color::lime);
  icons[5].SetUp(Color::yellow);
  icons[6].SetUp(Color::red);
  nob.SetUp(pos.y() + iconPos.y() + (ObjectNum -2)* ICON_SIZE * 2, pos.y() + iconPos.y() , pos.y() + size.y(), pos.y(), Vec2f(pos.x() + size.x(), pos.y()));
}
void OptionWindow::Update()
{
  mousePos = env.mousePosition();
  nob.Update(iconPos.y());
  for (int i = 0; i < ObjectNum; i++)
  {
    icons[i].SetPos(Vec2f(pos.x() + iconPos.x(), pos.y() + iconPos.y() + (ObjectNum - i)* ICON_SIZE * 2  -Window::HEIGHT * 2));
    icons[i].Update();
  }
  

  if (Collision::BoxtoMouse(tagPos, tagSize, mousePos, Vec2f(1, 1)))
  {
    if (env.isPullButton(Mouse::LEFT))
    {
      active = !active;
     
    }
  }

  if (active)
  {
    pos.x() = Window::WIDTH / 2 - size.x();
  }
  else
  {
    pos.x() = Window::WIDTH / 2;
  }

  tagPos = Vec2f(pos.x() - tagSize.x(), pos.y() + size.y() - tagSize.y());
  
}


void OptionWindow::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), backColor);
  drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, frameColor);
  
  for (auto& i : icons)
  {
    i.Draw();
  }
  nob.Draw();
  drawPoint(pos.x() + iconPos.x(), pos.y() + iconPos.y(), 10, Color::lime);
  drawFillBox(tagPos.x(), tagPos.y(), tagSize.x(), tagSize.y(), Color::gray);
  drawBox(tagPos.x(), tagPos.y(), tagSize.x(), tagSize.y(),5, Color::black);
}