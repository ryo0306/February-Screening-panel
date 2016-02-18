#pragma once
#include "SceneBase.h"
#include "UiBox.h"
#include "Easing.h"
#include "StageRead.h"
#include "Player.h"
#include "Swipe.h"

#define STAGENUM 10
#define STAGEMAX 9
#define SCENECHANGE_TIME 300
#define UIRANGE (Window::WIDTH*0.6)

class StageSelect: public SceneBase
{
public:
  StageSelect();
  void SetUp();
  void Update();
  void Draw();
  int GetStageNum(){ return stagenum; }
  void BgmUpdate();
  void BackGroundUpdate();
  void SetStageNum(int num_){ 
    stagenum = num_; 
    motionspeed = 1.1f;
    for (int i = 0; i < num_ - 1;i++)
    {
      motionActive = true;
      Motion();
    }
    motionTime = 0;
    motionspeed = 0.08f;
  }
private:

  void Input();
  void Motion();
  void ChangeSceneMotion();

  StageData data[STAGEMAX];
  StageRead read;
  int stagenum;
  UiBox uibox[STAGENUM];
  std::vector <Player> players;
  Swipe swipe;

  Font font = Font("res/meiryo.ttc");
  float angle;
  float rotateAngle;
  Vec2f centerPos;
  bool motionActive;
  float motionTime;
  int rotateDirection;
  float putAngle;
  float putAngle2;
  bool sceneChange;
  bool deleteMode;
  bool change;
  int changeTime;
  float angleSpeed;
  float changeAngle;
  float range;
  float faidƒ¿;
  bool faidStart;
  int popcount;
  int time;
  Random rand;
  Media bgm = Media("res/selectbgm.wav");
  float motionspeed;
};