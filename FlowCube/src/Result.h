#pragma once
#include "SceneBase.h"

class Result : public SceneBase
{
public:
  Result();
  void SetUp();
  void Update();
  void Draw();
private:
  Font font = Font("res/meiryo.ttc");
};