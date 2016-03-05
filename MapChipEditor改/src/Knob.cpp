#include "Knob.h"

void Knob::SetUp(float max_, float min_, float smax_, float smin_,Vec2f pos0_)
{
  size = Vec2f(20, 40);
  scrollPos.x() = (pos0_.x() - size.x());
  //scrollPos.y() = pos0_.y();
  max = max_;
  min = min_;
  smax = smax_;
  smin = smin_;
  amountChnage = max - min;
  sAmountChnage = smax - smin;
  scrollPos.y() = smax;
  active = false;
}


void Knob::Update(float& scrollObject_)
{
  mousePos = env.mousePosition();
  if (Collision::BoxtoMouse(scrollPos, size, mousePos, Vec2f(1, 1)))
  {
    if (env.isPushButton(Mouse::LEFT))
    {
      putPos = scrollPos - mousePos;
      active = true;
    }
  }


  if (active)
  {
    scrollPos.y() = mousePos.y() + putPos.y();
  }


  if (env.isPullButton(Mouse::LEFT))
  {
    active = false;
  }
  MoveLimit();

  scrollObject_ = (smax-scrollPos.y()) * (amountChnage / sAmountChnage);

}


void Knob::Draw()
{
  drawFillBox(scrollPos.x(), scrollPos.y(), size.x(), size.y(), Color::white);
  drawBox(scrollPos.x(), scrollPos.y(), size.x(), size.y(), 5, Color::black);
}


void Knob::MoveLimit()
{
  if (scrollPos.y() > smax - size.y())
  {
    scrollPos.y() = smax - size.y();
  }
  if (scrollPos.y() < smin)
  {
    scrollPos.y() = smin;
  }
}