#include "MainGame.h"
#include "StageSelect.h"
#include "Title.h"
#include "Result.h"
#include "ResourceManager.h"

enum SceneKey
{
  TITLE,
  STAGESELECT,
  MAINGAME,
  RESULT,
};

int main() {

  env;


  MainGame main;
  StageSelect select;
  Title title;
  Result result;
  title.SetUp();
  SceneKey scene = SceneKey::TITLE;
  int stagenum = 1;
  while (env.isOpen()) {
    env.begin();

    switch (scene)
    {
    case TITLE:
      title.Draw();
      title.Update();

        if (title.isEndCheak())
        {
          select.SetUp();
          scene = SceneKey::STAGESELECT;
        }
      break;
    case STAGESELECT:
      
        select.Update();
      select.Draw();
      
        if (select.isEndCheak())
        {
          stagenum = select.GetStageNum();
          main.SetStageNum(select.GetStageNum());
          main.SetUp();
          scene = SceneKey::MAINGAME;
        }
      break;
    case MAINGAME:
      main.Draw();

      main.Update();
        if (main.isEndCheak())
        {
          select.SetUp();
          select.SetStageNum(stagenum);
          scene = SceneKey::STAGESELECT;
        }
      break;
    default:
      break;
    }
    env.end();
  }
}
