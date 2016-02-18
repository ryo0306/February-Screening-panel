#pragma once
#include "SceneBase.h"
#include "Easing.h"
#include "UiBox.h"
#include "Player.h"
#include "LogoRead.h"
#include <vector>
#include <list>
#include <fstream>

class Title : public SceneBase
{
public:
  Title();
  void SetUp();
  void Update();
  void BgmUpdate();
  void LogoUpdate();
  void Draw();
  void Input();
  void BackGroundUpdate();
private:
  Font font = Font("res/meiryo.ttc");
  UiBox uibox[45];
  std::vector <Player> players;
  Vec2f logoPos[45];
  Random rand;
  bool active[45];
  float animationTime[45];
  float angle[45];
  int time;
  int num;
  int popcount;
  Media bgm = Media("res/titlebgm.wav");
};