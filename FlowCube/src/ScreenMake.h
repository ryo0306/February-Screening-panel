#pragma once
#include "lib/framework.hpp"
#include <iostream>
#define env App::Get()

// Windowのサイズ
enum Window {
  WIDTH = 960,
  HEIGHT = 540
};

//  シングルトン

class App
{
public:
  static AppEnv& Get()
  {
    static AppEnv s_env(Window::WIDTH, Window::HEIGHT, false, true);
    return s_env;
  }
private:
  App(){}
};