#include "Swipe.h"

void Swipe::SetUp()
{
  startPos = Vec2f(0, 0); 
  endPos = Vec2f(0, 0);
  range =Vec2f(0,0);
  swiping = false;
}

void Swipe::Update()
{
  mousePos = env.mousePosition();

  // １フレーム前の位置を取得
  putRange = range;

  if (env.isPushButton(Mouse::LEFT))
  {
    startPos = mousePos;
    swiping = true;
  }
  

  if (swiping)
  {
    endPos = mousePos;
  }


  if (env.isPullButton(Mouse::LEFT))
  {
    startPos = endPos;
    swiping = false;
  }

  range.x() = endPos.x() - startPos.x();
  range.y() = endPos.y() - startPos.y();

  //DEBUG:
  drawLine(startPos.x(), startPos.y(), endPos.x(), endPos.y(),5,Color::red);
}



Vec2f Swipe::GetOneFrameDifference()
{ 
  Vec2f temp = range - putRange;
  if (abs(range.x()) - abs(rangeLimit.x()) < 0)
    temp.x() = 0;
  if (abs(range.y()) - abs(rangeLimit.y()) < 0)
    temp.y() = 0;

    return temp;
}


/*

exe内でのスクショ
#include "lib/png.hpp"
u_char* bits = new u_char[画面の横幅　* 画面の高さ * 4];

glReadPixels(0, 0, 画面の横幅, 画面の高さ, GL_RGBA, GL_UNSIGNED_BYTE, bits);

WritePng("どこにどんな名前で保存するか", 保存するサイズ（横）保存するサイズ（高）, bits);

delete bits;
*/
