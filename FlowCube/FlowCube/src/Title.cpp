#include "Title.h"

Title::Title()
{
  isEnd = false;
}

//-------------------------------------------//
//                 èâä˙âª                     //
//-------------------------------------------//
void Title::SetUp()
{
  isEnd = false;
  time = 1;
  num = 0;
  popcount = rand(20, 120);
  for (int i = 0; i < 45; i++)
  {
    uibox[i].SetUp(0, Color::white);
    uibox[i].SetSize(Vec2f(25, 25));
    uibox[i].SetClear(true);
    uibox[i].SetPos(Vec2f(Window::WIDTH / 2 + 150, 0));
    active[i] = false;
    animationTime[i] = 0.0f;
    angle[i] = 0;
  }
  std::ifstream file("res/logo.txt");
  for (int i = 0; i < 45; i++)
  {
    file >> logoPos[i].x() >> logoPos[i].y();
  }
  /*logoPos[0] = (Vec2f(-250, 100));
  logoPos[1] = (Vec2f(-250, 75));
  logoPos[2] = (Vec2f(-250, 50));
  logoPos[3] = (Vec2f(-250, 25));
  logoPos[4] = (Vec2f(-250, 0));
  logoPos[5] = (Vec2f(-225, 100));
  logoPos[6] = (Vec2f(-200, 100));
  logoPos[7] = (Vec2f(-175, 100));
  logoPos[8] = (Vec2f(-225, 50));
  logoPos[9] = (Vec2f(-200, 50));

  logoPos[10] = (Vec2f(-125, 100));
  logoPos[11] = (Vec2f(-125, 75));
  logoPos[12] = (Vec2f(-125, 50));
  logoPos[13] = (Vec2f(-125, 25));
  logoPos[14] = (Vec2f(-125, 0));

  logoPos[15] = (Vec2f(-50, 100));
  logoPos[16] = (Vec2f(-50, 75));
  logoPos[17] = (Vec2f(-50, 50));
  logoPos[18] = (Vec2f(-50, 25));
  logoPos[19] = (Vec2f(-50, 0));
  logoPos[20] = (Vec2f(-25, 100));
  logoPos[21] = (Vec2f(-25, 0));
  logoPos[22] = (Vec2f(0, 100));
  logoPos[23] = (Vec2f(0, 0));

  logoPos[24] = (Vec2f(25, 100));
  logoPos[25] = (Vec2f(25, 75));
  logoPos[26] = (Vec2f(25, 50));
  logoPos[27] = (Vec2f(25, 25));
  logoPos[28] = (Vec2f(25, 0));

  logoPos[29] = (Vec2f(75, 100));
  logoPos[30] = (Vec2f(75, 75));
  logoPos[31] = (Vec2f(100, 50));
  logoPos[32] = (Vec2f(100, 25));
  logoPos[33] = (Vec2f(125, 0));
  logoPos[34] = (Vec2f(150, 25));
  logoPos[35] = (Vec2f(150, 50));
  logoPos[36] = (Vec2f(175, 75));
  logoPos[37] = (Vec2f(175, 100));
  logoPos[38] = (Vec2f(200, 50));
  logoPos[39] = (Vec2f(200, 25));
  logoPos[40] = (Vec2f(225, 0));
  logoPos[41] = (Vec2f(250, 25));
  logoPos[42] = (Vec2f(250, 50));
  logoPos[43] = (Vec2f(275, 75));
  logoPos[44] = (Vec2f(275, 100));*/
}


//-------------------------------------------//
//               ëSëÃÇÃçXêV                   //
//-------------------------------------------//
void Title::Update()
{
  BgmUpdate();
  Input();
  LogoUpdate();
  BackGroundUpdate();

  time++;
}


//-------------------------------------------//
//               ëSëÃÇÃï`âÊ                   //
//-------------------------------------------//
void Title::Draw()
{
  // îwåi
  for (auto & p : players)
  {
    p.Draw();
  }
  // ÉçÉS
  for (int i = 0; i < 45; i++)
  {
    uibox[i].Draw();
  }
  font.size(60);
  font.draw("~PRESS  ENTER~", Vec2f(-250, -150), Color::white);
}

//-------------------------------------------//
//               BgmÇÃçXêV                   //
//-------------------------------------------//
void Title::BgmUpdate()
{
  if (!bgm.isPlaying())
  {
    bgm.play();
  }
}


//-------------------------------------------//
//               ÉçÉSÇÃçXêV                   //
//-------------------------------------------//
void Title::LogoUpdate()
{

  if (num < 45)
  {
    if (time % 3 == 0)
    {
      active[num] = true;
      num++;
    }
  }

  for (int i = 0; i < 45; i++)
  {
    if (active[i])
    {
      Vec2f putPos;
      putPos.x() = EasingBounceInOut(animationTime[i], Window::WIDTH / 2 + 150, logoPos[i].x());
      putPos.y() = EasingBounceInOut(animationTime[i], 0, logoPos[i].y());
      putPos.y() = putPos.y() + 10 * cos(angle[i]);
      uibox[i].SetPos(putPos);
      angle[i] += 0.05f;
      animationTime[i] += 0.005f;
    }

    if (animationTime[i] > 1)
    {
      animationTime[i] = 1;
    }
  }
}

//-------------------------------------------//
//                   ì¸óÕ                    //
//-------------------------------------------//
void Title::Input()
{
  if (env.isPushKey(GLFW_KEY_ENTER))
  {
    bgm.stop();
    seSelect.play();
    isEnd = true;
  }
}


//-------------------------------------------//
//               îwåiÇÃçXêV                   //
//-------------------------------------------//
void Title::BackGroundUpdate()
{

  if (players.size() < 10)
    if (time % popcount == 0)
    {
      float size = rand(10, 50);
      players.push_back(Player());
      players[players.size() - 1].SetUp(Vec2f(Window::WIDTH / 2, rand(-Window::HEIGHT / 2, Window::HEIGHT / 2)), Vec2f(-rand(1, 5), 0));
      players[players.size() - 1].SetDemo(true);
      players[players.size() - 1].SetSize(Vec2f(size, size));
      popcount = rand(20, 120);
    }
  if (players.size() > 0)
    for (auto& p : players)
    {
      if (p.GetPos().x() < -Window::WIDTH / 2 - p.GetSize().x() / 2)
      {
        float size = rand(10, 50);
        p.SetUp(Vec2f(Window::WIDTH / 2, rand(-Window::HEIGHT / 2, Window::HEIGHT / 2)), Vec2f(-rand(1, 5), 0));
        p.SetDemo(true);
        p.SetSize(Vec2f(size, size));
      }
    }
  for (auto & p : players)
  {
    p.Update();
  }
}


