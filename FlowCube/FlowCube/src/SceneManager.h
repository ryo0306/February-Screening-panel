#pragma once
#include "ScreenMake.h"
#include "Task.h"
#include "SceneBase.h"
#include "Title.h"
#include "StageSelect.h"
#include "MainGame.h"


class SceneManager : public SceneChanger, Task
{
public:

  SceneManager();
  void SetUp();
  void Update();
  void Draw();
  void ChangeScene(SceneKey nextScene_);

private:
  int stageNum;
  SceneBase* scene;
  SceneKey nextScene;
};

