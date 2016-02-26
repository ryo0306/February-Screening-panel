#include "StageSelect.h"
//TODO:�ǂݍ��݂����s���Ă���B


StageSelect::StageSelect()
{
}
//-------------------------------------------//
//                  ������                   //
//-------------------------------------------//
void StageSelect::SetUp(int stageNum_)
{
  stageNum = stageNum_;
  uibox[9].SetUp(1, Color::red);
  uibox[8].SetUp(2, Color::magenta);
  uibox[7].SetUp(3, Color::yellow);
  uibox[6].SetUp(4, Color::lime);
  uibox[5].SetUp(5, Color::green);
  uibox[4].SetUp(6, Color::navy);
  uibox[3].SetUp(7, Color::cyan);
  uibox[2].SetUp(8, Color::white);
  uibox[1].SetUp(9, Color::gray);
  uibox[0].SetUp(0, Color::black);
  angle = (2 * M_PI) / STAGENUM;
  centerPos = Vec2f(uibox[0].GetSize().x()/2, -Window::HEIGHT / 2 -300);
  rotateAngle = 0;
  motionActive = false;
  motionTime = 0;
  rotateDirection = 1;
  putAngle = 0;
  putAngle2 = 0;
  sceneChange = false;
  isEnd = false;
  deleteMode = false;
  changeTime = SCENECHANGE_TIME;
  change = false;
  changeAngle = 0;
  angleSpeed = 0;
  faid�� = 0;
  faidStart = false;
  range = UIRANGE;
  popcount = rand(20, 120);
  time = 0;
  motionspeed = 0.08f;

  for (int i = 0; i < STAGEMAX; i++)
  {
    read.SetStageNum(i+1);
    read.SearchData();
    data[i] = read.GetData();
  }
  uibox[9].SetClear(true);
  for (int i = STAGEMAX-1; i >= 1; i--)
  {
    uibox[i].SetClear(data[(STAGEMAX-1) - i].clear);
  }

  swipe.SetUp();
  swipe.SetRangeLimit(Vec2f(100,100));
  rotateAngle = (stageNum-1) *angle;
}

//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
void StageSelect::Update()
{
  BgmUpdate();

  if (!motionActive&&!sceneChange)
  {
    Input();
  }
  BackGroundUpdate();
  ChangeSceneMotion();
  Motion();

  swipe.Update();
  time++;
}

//------------------------------------//
//              �`��                  //
//------------------------------------//


void StageSelect::Draw()
{
  env.bgColor(Color::black);
  for (auto & p : players)
  {
    p.Draw();
  }
  for (int i = 0; i < STAGENUM; i++)
  {
    uibox[i].Draw(); 
  }

  font.size(50);
  std::string stage_c = std::to_string(stageNum);
  font.draw("�X�e�[�W" + stage_c, Vec2f(-125 - (12 * (stageNum / 10)), Window::HEIGHT / 2 - 120), Color::white);
  font.size(30);
  font.draw("��,��: �X�e�[�W�I��   ENTER: ���� ", Vec2f(-Window::WIDTH / 2, Window::HEIGHT / 2 - 30), Color::white);
  drawFillBox(-Window::WIDTH / 2, -Window::HEIGHT / 2, Window::WIDTH, Window::HEIGHT, Color(1,1,1,faid��));
}


//--------------------------------//
//          ��]����               //
//--------------------------------//

void StageSelect::Motion()
{
  
  // �ʒu��ݒ�
  for (int i = 0; i < STAGENUM; i++)
  {
    int j = i + 3;
    Vec2f putPos;
    uibox[i].Update();
    uibox[i].SetSelectActive(false);
    putPos.x() = centerPos.x() + range* cos(j*angle + angle / 2 + rotateAngle + changeAngle) - UIBOX_SIZE / 2;
    putPos.y() = centerPos.y() + range* sin(j*angle + angle / 2 + rotateAngle + changeAngle) - UIBOX_SIZE / 2;
    if (stageNum == uibox[i].GetNum())
    {
      uibox[i].SetSelectActive(true);
    }
    uibox[i].SetPos(putPos);
  }
  

  //  ��]����
  if (motionActive)
  {
    putAngle2 = putAngle;
    putAngle = EasingCircInOut(motionTime, 0, rotateDirection*angle);
    float put_move = putAngle - putAngle2;
    rotateAngle += put_move;
    if (motionTime > 1)
    {
      putAngle2 = 0;
      putAngle = 0;
      motionActive = false;
      motionTime = 0;
    }
    motionTime += motionspeed;
  }
}

//--------------------------------//
//           ����                 //
//--------------------------------//

void StageSelect::Input()
{
  if (!(stageNum > STAGEMAX))
    if (env.isPushKey(GLFW_KEY_RIGHT))
    {
      motionActive = true;
      rotateDirection = 1;
      stageNum++;
    }
  if (!(stageNum <= 1))
    if (env.isPushKey(GLFW_KEY_LEFT))
    {
      motionActive = true;
      rotateDirection = -1;
      stageNum--;
    }
 
  if (!(stageNum > STAGEMAX))
  if (swipe.GetOneFrameDifference().x() < -5)
  {
    motionActive = true;
    rotateDirection = 1;
    stageNum++;
  }


  if (!(stageNum <= 1))
  if (swipe.GetOneFrameDifference().x() > 5)
  {
    motionActive = true;
    rotateDirection = -1;
    stageNum--;
  }

  

  if (env.isPushKey(GLFW_KEY_DELETE))
  {
    // delete
  }

  //TODO:�ǂ������N���b�N������ɕς���
  //TODO:�z��̓��݊O���Ă邩�璼��
  if (data[stageNum - 1].clear)
  if (env.isPushKey(GLFW_KEY_ENTER))
  {
    env.flushInput();
    seSelect.play();
    sceneChange = true;
    //DEBUG:
  }
}


//-------------------------------------------//
//              �V�[���؂�ւ�                //
//-------------------------------------------//
void StageSelect::ChangeSceneMotion()
{
  if (sceneChange)
  {
    angleSpeed += M_PI/5000;
    changeAngle += angleSpeed;
    faid�� += 0.004;
    //centerPos.y() += 2.5;
    //range -= 2;
    if (range < 0)
    {
      range = 0;
    }
    for (int i = 0; i < STAGEMAX+1; i++)
    {
     // uibox[i].SetSize(Vec2f(uibox[i].GetSize().x() -1.0f,uibox[i].GetSize().y()-1.0f));
    }

    if (changeTime == 100)
    {
      std::swap(uibox[9], uibox[10 - stageNum]);
    }

    if (centerPos.y() > 0)
    {
      faidStart = true;
    }

    if (changeTime <= 0)
    {
      sceneChanger->ChangeScene(SceneKey::MAINGAME);
      bgm.stop();
    }

    if (env.isPushKey(GLFW_KEY_ENTER))
    {
      bgm.stop();
      seSelect.play();
      sceneChanger->ChangeScene(SceneKey::MAINGAME);
    }
    changeTime--;
  }
  if (faidStart)
  {
    //faid�� += 0.008;
  }
}


//-------------------------------------------//
//               BGM�̍X�V                   //
//-------------------------------------------//
void StageSelect::BgmUpdate()
{
  if (!bgm.isPlaying())
  {
    bgm.play();
  }
}



//-------------------------------------------//
//               �w�i�̍X�V                   //
//-------------------------------------------//
void StageSelect::BackGroundUpdate()
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
        p.SetSize(Vec2f(size, size));
        p.SetDemo(true);
      }
    }

  for (auto & p : players)
  {
    p.Update();
  }
}

//main��
//select�ŃX�e�[�W���𔻒f�Z�[�u�f�[�^
//main�ɐ�����n���B
//main��mainGame�ɐ�����n��
//maingame���ɂ���X�e�[�W�f�[�^��ǂݍ���