#pragma once
#include "lib/framework.hpp"
#define env App::Get()


enum Window {
  WIDTH = 960,
  HEIGHT = 540
};


class App
{
public:
  static AppEnv& Get()
  {
    static AppEnv putEnv(Window::WIDTH, Window::HEIGHT);
    return putEnv;
  }
private:
  App(){}
};