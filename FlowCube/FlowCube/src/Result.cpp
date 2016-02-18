#include "Result.h"

Result::Result()
{

}

void Result::SetUp()
{
  isEnd = false;
}

void Result::Update()
{
  if (env.isPushKey(GLFW_KEY_ENTER))
  {
    isEnd = true;
  }
}

void Result::Draw()
{
  env.bgColor(Color::black);
  font.size(100);
  font.draw("ステージクリア！！", Vec2f(-400, 0),Color::white);
  font.size(50);
  font.draw("Press  Enter", Vec2f(150, -Window::HEIGHT/2), Color::white);
}