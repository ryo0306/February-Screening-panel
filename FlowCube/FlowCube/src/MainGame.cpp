#include "MainGame.h"

//-------------------------------------------//
//                 初期化                    //
//-------------------------------------------//
void MainGame::SetUp()
{
  goals.clear();
  pendulums.clear();
  magnets.clear();
  walls.clear();
  pauseSize = Vec2f(80, 80);
  pausePos = Vec2f(-Window::WIDTH / 2, Window::HEIGHT / 2 - pauseSize.y());
  file_path = "res/stage" + std::to_string(num) + ".txt";
  map.ReadFile(file_path);
  read.SetStageNum(num);
  read.SearchData();
  data = read.GetData();
  ObjectSetting();
  player.SetUp(startPos, data.startMove);
  pause = false;
  isEnd = false;
  clear = false;
  twindow.pos = data.windowPos;
  pauseα = 0.4f;
  fontPos[0] = Vec2f(-125,100);
  fontPos[1] = Vec2f(-200,-100);
  tutorialWindow.SetUp(twindow, data.fontSize, Color::white);
  for (int i = 0; i < data.str.size(); i++)
  {
    tutorialWindow.SetMessage(data.str[i]);
  }
  for (int i = 0; i < 2; i++)
  {
    fontColor[i] = Color::white;
  }
 
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void MainGame::Update()
{

  mousePos = env.mousePosition();

  if (!clear)
  {
    BgmUpdate();
    if (!pause)
    {
      ObjectUpdate();
      CheckDead();
    }
    else
    {
      PauseUpdate();
    }
    ChoicePause();
  }
  Result();
}


//-------------------------------------------//
//               全体の描画                   //
//-------------------------------------------//
void MainGame::Draw()
{
  env.bgColor(Color::white);
  for (auto& w : walls)
  {
    w.Draw();
  }
  for (auto& m : magnets)
  {
    m.Draw();
  }
  for (auto& p : pendulums)
  {
    p.Draw();
  }
  player.Draw();
  for (auto& g : goals)
  {
    g.Draw();
  }
  tutorialWindow.Draw();

  // ポーズ時の描画
  if (pause)
  {
    drawFillBox(-Window::WIDTH / 2, -Window::HEIGHT / 2, Window::WIDTH, Window::HEIGHT, Color(0, 0, 0, 0.4f));
    font.size(50);
    font.draw("ゲームに戻る", fontPos[0], fontColor[0]);
    font.draw("ステージセレクトへ",fontPos[1], fontColor[1]);
  }
  // UI
  drawFillBox(pausePos.x(),pausePos.y(), pauseSize.x(), pauseSize.y(), Color(0.5f,0.5f,0.5f,pauseα));
  drawFillBox(pausePos.x() + 10, pausePos.y() + 10, 20, 60, Color(1.0f, 1.0f, 1.0f, pauseα));
  drawFillBox(pausePos.x() + 40, pausePos.y() + 10, 20, 60, Color(1.0f, 1.0f, 1.0f, pauseα));

  // リザルト
  if (clear)
  {
    drawFillBox(-Window::WIDTH / 2, -Window::HEIGHT / 2, Window::WIDTH, Window::HEIGHT, Color(0, 0, 0, 0.6f));
    font.size(100);
    font.draw("ステージクリア！！", Vec2f(-400, 0), Color::white);
    font.size(50);
    font.draw("Press  Enter", Vec2f(150, -Window::HEIGHT / 2), Color::white);
  }
}

//-------------------------------------------//
//            オブジェクトを設置               //
//-------------------------------------------//
void MainGame::ObjectSetting()
{
  for (int x = 0; x < MapSize::WIDTH_; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT_; y++)
    {
      switch (map.GetMapData(x,y))
      {
      case MapObject::NONE:
        break;
      case MapObject::WALL:
        walls.push_back(Wall(Vec2f(x*MAPCHIP_SIZE - Window::WIDTH / 2, y*MAPCHIP_SIZE - Window::HEIGHT / 2)));
        break;
      case MapObject::PENDULUM:
        pendulums.push_back(Pendulum(Vec2f(x*MAPCHIP_SIZE - Window::WIDTH / 2, y*MAPCHIP_SIZE - Window::HEIGHT / 2)));
        break;
      case MapObject::MAGNET:
        magnets.push_back(Magnet(Vec2f(x*MAPCHIP_SIZE - Window::WIDTH / 2, y*MAPCHIP_SIZE - Window::HEIGHT / 2)));
        break;
      case MapObject::START:
        startPos = Vec2f(x*MAPCHIP_SIZE - Window::WIDTH / 2, y*MAPCHIP_SIZE - Window::HEIGHT / 2);
        break;
      case MapObject::GOAL:
        goals.push_back(Goal(Vec2f(x*MAPCHIP_SIZE - Window::WIDTH / 2, y*MAPCHIP_SIZE - Window::HEIGHT / 2)));
        break;
      default:
        break;
      }
    }
  }
}


//-------------------------------------------//
//            オブジェクトの更新               //
//-------------------------------------------//
void MainGame::ObjectUpdate()
{

  for (auto& w : walls)
  {
    if (Collision::BoxtoBox(player.GetPos(), player.GetSize(), w.GetPos(), w.GetSize()))
    {
            player.SetActive(false);
    }
  }

  for (auto& p : pendulums)
  {
    if (Collision::BoxtoBox(player.GetPos(), player.GetSize(), p.GetPos(), p.GetSize()))
    {
      player.SetActive(false);
    }

    if (env.isPushButton(Mouse::LEFT))
    {
      if (Collision::BoxtoMouse(p.GetPos(), p.GetSize(), mousePos, Vec2f(1, 1)))
      {

        player.PendulumActionPush();
      }
    }
    
    if (env.isPullButton(Mouse::LEFT))
    {
      player.PendulumActionPull();
    }
  }
  player.PendulumUpdate();
  for (auto& g : goals)
  {
    if (player.CheckActive())
    {
      if (Collision::BoxtoBox(player.GetPos(), player.GetSize(), g.GetPos(), g.GetSize()))
      {
        clear = true;
        bgm.stop();
      }
    }
  }

  for (auto& m : magnets)
  {
    if (Collision::BoxtoBox(player.GetPos(), player.GetSize(), m.GetPos(), m.GetSize()))
    {
      player.SetActive(false);
    }
    if (env.isPressButton(Mouse::LEFT))
    {
      if (Collision::BoxtoMouse(m.GetPos(), m.GetSize(), mousePos, Vec2f(1, 1)))
      {
        Vec2f putMove;
        float putAngle;
        putAngle = atan2(player.GetPos().y() - mousePos.y(), player.GetPos().x() - mousePos.x());
        putMove.x() = data.magnetPower*cos(putAngle +M_PI);
        putMove.y() = data.magnetPower*sin(putAngle + M_PI);
        player.AddPos(putMove);
        break;
      }
    }

    if (env.isPullButton(Mouse::LEFT))
    {
      player.AddPos(Vec2f(0, 0));
    }
  }

  player.Update();
}

//-------------------------------------------//
//               BGMの更新                   //
//-------------------------------------------//
void MainGame::BgmUpdate()
{
  if (!bgm.isPlaying())
  {
    bgm.play();
  }
}

//-------------------------------------------//
//               クリア後の更新               //
//-------------------------------------------//
void MainGame::Result()
{
  if (clear)
  {
    if (!result.isPlaying())
    {
      result.play();
    }
    if (env.isPushKey(GLFW_KEY_ENTER))
    {
      result.stop();
      seSelect.play();
      data.clear = true;
      read.SetData(data);
      clear = true;
      isEnd = true;
    }
  }
}

//-------------------------------------------//
//          pauseに触れた時の更新             //
//-------------------------------------------//
void MainGame::ChoicePause()
{

  if (Collision::BoxtoMouse(pausePos, pauseSize, mousePos, Vec2f(1, 1)))
  {
    if (env.isPushButton(Mouse::LEFT))
    {
      seSelect.play();
      pause = !pause;
    }
    pauseα = 1.0f;
  }
  else
  {
    pauseα = 0.4f;
  }
}


//-------------------------------------------//
//               ポーズ時の更新               //
//-------------------------------------------//
void MainGame::PauseUpdate()
{
  fontColor[0] = Color::white;
  fontColor[1] = Color::white;

  if (Collision::BoxtoMouse(fontPos[0], Vec2f(300, 50), mousePos, Vec2f(1, 1)))
  {
    fontColor[0] = Color::red;
    if (env.isPushButton(Mouse::LEFT))
    {
      seSelect.play();
      pause = false;
    }
  }
  if (Collision::BoxtoMouse(fontPos[1], Vec2f(450, 50), mousePos, Vec2f(1, 1)))
  {
    fontColor[1] = Color::red;
    if (env.isPushButton(Mouse::LEFT))
    {
      seSelect.play();
      bgm.stop();
      isEnd = true;
    }
  }
}

//-------------------------------------------//
//               死んだときの更新              //
//-------------------------------------------//
void MainGame::CheckDead()
{
  if (player.CheakDead())
  {
    SetUp();
  }
}