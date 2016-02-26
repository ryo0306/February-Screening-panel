#include "Title.h"

Title::Title()
{
  isEnd = false;
}

//-------------------------------------------//
//                 èâä˙âª                     //
//-------------------------------------------//
void Title::SetUp(int stageNum_)
{
  stageNum = stageNum_;
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
    sceneChanger->ChangeScene(SceneKey::STAGESELECT);//
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


