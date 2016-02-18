#pragma once
#include "ScreenMake.h"
#include <fstream>

struct StageData
{
  Vec2f startMove;
  float magnetPower;
  bool clear;
  std::vector <std::string> str;
  Vec2f windowPos;
  int fontSize;
};

class StageRead
{
public:
  StageRead();
  void SetStageNum(int num_){ num = num_; }
  void SearchData();
  StageData GetData(){ return putData; }
  void SetData(StageData data_);
private:
  int num;
  std::string path;
  StageData putData;
};