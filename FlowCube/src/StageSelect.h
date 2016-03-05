#pragma once
#include "SceneBase.h"
#include "UiBox.h"
#include "Easing.h"
#include "StageRead.h"
#include "Player.h"
#include "Swipe.h"
#include "StageNum.h"

#define STAGENUM 10
#define STAGEMAX 9
#define SCENECHANGE_TIME 300
#define UIRANGE (Window::WIDTH*0.6)

class StageSelect: public SceneBase
{
public:
  StageSelect();
  StageSelect(SceneChanger* changer) : SceneBase(changer) {}
  void SetUp(int stageNum_);
  void Update();
  void Draw();
  void BgmUpdate();
  void BackGroundUpdate();
  
private:

  void Input();
  void Motion();
  void ChangeSceneMotion();

  StageData data[STAGEMAX];
  StageRead read;
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