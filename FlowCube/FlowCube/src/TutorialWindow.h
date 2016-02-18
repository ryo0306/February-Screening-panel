#pragma once
#include "Object.h"

struct TWindow
{
  TWindow(){}
  TWindow(Vec2f pos_,
         Vec2f size_,
         Color backColor_,
         Color freamColor_)
  {
    pos = pos_;
    size = size_;
    backColor = backColor_;
    freamColor = freamColor_;
  }
  Vec2f pos;
  Vec2f size;
  Color backColor;
  Color freamColor;
};

class TutorialWindow : Object
{
public:
  TutorialWindow(){}
  void SetUp(TWindow window_,float fontSize_,Color fontColor_);
  void Update();
  void Draw();
  void SetMessage(std::string message_);
  
private:
  TWindow window;
  std::vector <std::string> messages;
  Font font = Font("res/meiryo.ttc");
  Color fontColor;
  int fontSize;
};