#include "SceneManager.h"

SceneManager::SceneManager() :
nextScene(SceneKey::NONE) 
{
  scene =new Title(this);
}

//������
void SceneManager::SetUp()
{
  // ���̑���͂��܂�悭�Ȃ�
  scene->SetUp(1);
}


//�X�V
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

//�`��
void SceneManager::Draw(){
  scene->Draw(); 
}

// ���� nextScene �ɃV�[����ύX����
void SceneManager::ChangeScene(SceneKey nextScene_){
 nextScene = nextScene_;    //���̃V�[�����Z�b�g����
}