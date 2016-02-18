#include "TutorialWindow.h"

void TutorialWindow::SetMessage(std::string message_)
{
  messages.push_back(std::string(message_));
}

//-------------------------------------------//
//                 初期化                    //
//-------------------------------------------//
void TutorialWindow::SetUp(TWindow window_, float fontSize_, Color fontColor_)
{
  messages.clear();
  window = window_;
  fontSize = fontSize_;
  fontColor = fontColor_;
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void TutorialWindow::Update()
{

}


//-------------------------------------------//
//               全体の描画                   //
//-------------------------------------------//
void TutorialWindow::Draw()
{
  drawFillBox(window.pos.x(), window.pos.y(), fontSize*11 , fontSize * messages.size(), window.backColor);
  drawBox(window.pos.x(), window.pos.y(), fontSize * 10, fontSize * messages.size(), 10, window.freamColor);

  font.size(fontSize);
  for (size_t i = 0; i < messages.size(); i++)
  {
    font.draw(messages[messages.size()-1-i], Vec2f(window.pos.x() , window.pos.y() + (i*fontSize)), fontColor);
  }
}