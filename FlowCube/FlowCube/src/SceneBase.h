#pragma once
#include "ScreenMake.h"
#include "SceneChanger.h"
#include "Task.h"
using namespace std;


class SceneBase : public Task
{
public:
  SceneBase(){}
  SceneBase(SceneChanger* changer)
  {
    sceneChanger = changer;
  }
  virtual void SetUp(int stageNum_){}
  virtual void Update(){}
  virtual void Draw(){}
  virtual bool isEndCheak(){ return isEnd; }
  virtual int GetStageNum(){ return stageNum; }
  //�V�[���̐؂�ւ���
  //sceneChanger->ChangeScene(�ς������V�[��);
  SceneChanger* sceneChanger;
protected:
  bool isEnd;
  Media seSelect = Media("res/se_select.wav");
  int stageNum;
private:
};