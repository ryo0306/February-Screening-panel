#pragma once
#include "ScreenMake.h"

class Task
{
public:

  virtual ~Task(){}
  virtual void SetUp(){}
  virtual void Update(){}
  virtual void Draw(){}
private:
};