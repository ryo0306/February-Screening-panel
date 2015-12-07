#pragma once
#include "lib/framework.hpp"
#define env App::get()


enum Window
{
  WIDTH = 500,
  HEIGHT = 250,
};

class App
{
public:
  static AppEnv& get()
  {
    static AppEnv s_env(Window::WIDTH, Window::HEIGHT);
    return s_env;
  }
private:
  App(){}
};