#pragma once
#include "ScreenMake.h"


class SceneBase
{
public:
  SceneBase(){}
  virtual void SetUp(){}
  virtual void Update(){}
  virtual void Draw(){}
  virtual bool isEndCheak(){ return isEnd; }




protected:
  bool isEnd;

  Media seSelect = Media("res/se_select.wav");
private:
};