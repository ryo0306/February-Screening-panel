#include "StageRead.h"

StageRead::StageRead()
{

}


//-------------------------------------------//
//            �t�@�C���ǂݍ���                 //
//-------------------------------------------//
void StageRead::SearchData()
{
  putData.str.clear();
  path = "res/stagedata" + std::to_string(num) + ".txt";

  std::fstream file(path);
  assert(file);

  if (!file)
  {
    putData.startMove = Vec2f(0, 0);
    putData.magnetPower = 0;
    putData.clear = false;
    return;
  }

  file >> putData.startMove.x() >> putData.startMove.y()
       >> putData.magnetPower >> putData.clear
       >> putData.windowPos.x() >> putData.windowPos.y()
       >> putData.fontSize;

  int i = 0;
  while (!file.eof())
  {
    putData.str.push_back(std::string());
    file >> putData.str[i];
    i++;
  }
  
}

//-------------------------------------------//
//             �t�@�C����������               //
//-------------------------------------------//
void StageRead::SetData(StageData data_)
{
  //SearchData();
  putData = data_;
  std::fstream file(path);
  file << putData.startMove.x() <<" " <<putData.startMove.y()
  << " " << putData.magnetPower << " " << putData.clear;
}