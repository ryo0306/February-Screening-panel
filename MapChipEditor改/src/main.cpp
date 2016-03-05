#include "ScreenMake.h"
#include "Map.h"

int main() {

  env;
  Map map;

  map.FileRead("res/stage1.txt");
  while (env.isOpen()) {
    env.begin();

    map.Edit();
    map.Draw();
    

    if (env.isPressKey(GLFW_KEY_LEFT_CONTROL) && env.isPushKey(GLFW_KEY_S))
    {
      map.WrightData("res/stage1.txt");
    }

    env.end();
  }


  return 0;
}
