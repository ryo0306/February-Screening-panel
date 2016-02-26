#pragma once
#include "ScreenMake.h"

enum  SceneKey
{
  NONE,
  TITLE,
  STAGESELECT,
  MAINGAME,
};

class SceneChanger {
public:
  virtual ~SceneChanger(){};
  virtual void ChangeScene(SceneKey NextScene) = 0;//指定シーンに変更する
};

