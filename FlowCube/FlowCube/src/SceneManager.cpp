#include "SceneManager.h"

SceneManager::SceneManager() :
nextScene(SceneKey::NONE) 
{
  scene =new Title(this);
}

//初期化
void SceneManager::SetUp()
{
  // この代入はあまりよくない
  scene->SetUp(1);
}


//更新
void SceneManager::Update()
{
  if (nextScene != SceneKey::NONE)
  {
    stageNum = scene->GetStageNum();
    delete scene;

    switch (nextScene){
    case TITLE:
      scene = new Title(this);
      break;
    case STAGESELECT:
      scene = new StageSelect(this);
      break;
    case MAINGAME:
      scene = new MainGame(this);
      break;
    }

    nextScene = SceneKey::NONE;
    scene->SetUp(stageNum);
  }

  scene->Update();
}

//描画
void SceneManager::Draw(){
  scene->Draw(); 
}

// 引数 nextScene にシーンを変更する
void SceneManager::ChangeScene(SceneKey nextScene_){
 nextScene = nextScene_;    //次のシーンをセットする
}