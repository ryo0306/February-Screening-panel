#pragma once
#include "ScreenMake.h"
#include "Icon.h"
#include "Common.h"
#include "Knob.h"
#include <vector>
#define ICON_SIZE 100

class OptionWindow
{
public:
  OptionWindow();
  void SetUp(Vec2f pos_, Vec2f size_, Color backColor_);
  void Draw();
  void Update();
  bool GetIconsAcitive(bool num_){ return icons[num_].GetActive(); }
  Vec2f GetPos(){ return pos; }
  Vec2f GetSize(){ return size; }
  std::vector<Icon> icons;
  void ActiveAllClear()
  {
    for(auto& i : icons)
    { 
    i.SetActive(false); 
    }
  }
private:
  Vec2f pos;
  Vec2f size;
  Color backColor;
  Color frameColor;
  MapObject type;
  Knob nob;
  Vec2f iconPos;
  Vec2f mousePos;
  Vec2f putPos;
  Vec2f tagPos;
  Vec2f tagSize;
  bool active;
};