#include "Object.h"

Object::Object(Color color_, Vec2f pos_, Vec2f size_)
{
  color = color_;
  pos = pos_;
  size = size_;
}


void Object::Update()
{

}

void Object::Draw()
{
  drawFillBox(pos.x(), pos.y(), size.x(), size.y(), color);
  drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white);
}