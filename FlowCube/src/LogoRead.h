#pragma once
#include "ScreenMake.h"

class LogoRead
{
public:
  LogoRead(){};
  void SetFilePath(std::string path_);
  void SearchData();
  Vec2f GetData(){return putData;};
private:
  std::string path;
  Vec2f putData;
};