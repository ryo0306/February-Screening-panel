#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "Map.h"
#include "Wall.h"
#include "Pendulum.h"
#include "Magnet.h"
#include "Goal.h"
#include "StageRead.h"
#include "TutorialWindow.h"
#include "StageNum.h"
#include <vector>
//TODOLIST:

//TODO1:¡Œ»İƒyƒ“ƒfƒ…ƒ‰ƒ€‚ğpush‚µ‚½‚Æ‚«‚É
//      Šp“x‚ª¬‚³‚¢‚Ù‚Ç‚Í‚â‚­‚È‚é‚µ‚­‚İ‚É
//      ‚È‚Á‚Ä‚¢‚é‚Ì‚Å¡‚·




class MainGame : public SceneBase
{
public:
  MainGame(){}
  MainGame(SceneChanger* changer) : SceneBase(changer) {}
  void SetUp(int stageNum_);
  void Update();
  void Draw();
  void BgmUpdate();
  void Result();
  void ChoicePause();
  void PauseUpdate();
  void CheckDead();
  bool CheckCear(){ return clear; }
private:
  void ObjectSetting();
  void ObjectUpdate();
  std::vector <Wall> walls;
  std::vector <PendulumObject> pendulums;
  std::vector <Magnet> magnets;
  std::vector <Goal> goals;
  Player player;
  Map map;
  TutorialWindow tutorialWindow;
  TWindow twindow;
  std::string file_path;
  StageRead read;
  StageData data;
  Vec2f startPos;
  Vec2f mousePos;
  bool pause;
  bool clear;
  Vec2f pausePos;
  Vec2f pauseSize;
  float pauseƒ¿;
  Font font = Font("res/meiryo.ttc");
  Color fontColor[2];
  Vec2f fontPos[2];
  Media bgm = Media("res/mainbgm.wav");
  Media result = Media("res/clear.wav");
};