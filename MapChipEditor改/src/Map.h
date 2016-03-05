#pragma once
#include "ScreenMake.h"
#include "Object.h"
#include "Collision.h"
#include "OptionWindow.h"
#include <vector>
#include <fstream>
#include "Common.h"

struct ObjectStatus
{
  int num;
  std::vector<Object> onj;
};

struct ReadData
{
  int num;
  Vec2f pos;
  Vec2f size;
};

enum MapSize
{
  WIDTH_ = 32,
  HEIGHT_ = 18,
};

enum EditMode
{
  Move,
  ObjectEdit,
  Option,
};

class Map
{
public:
  Map(){}
  void FileRead(std::string path_);
  void Draw();
  void Edit();
  void ChangeSize();
  void WindowManager();
  void IconManager();
  void CreateAction();
  void CriateObject(Vec2f pos_, Vec2f size_,int ObjectNum_);
  void DeleteAction();
  void WrightData(std::string path_);
  Vec2f SizeCheck();
private:
  // mapÇégÇ¡Çƒeditì‡Ç≈í«â¡Ç≈Ç´ÇÈÇÊÇ§Ç…Ç∑ÇÈÅH
  ObjectStatus objects[ObjectNum-1];
  Vec2f mousePos;
  Color frameColor[MapSize::WIDTH_][MapSize::HEIGHT_];
  int mapSize;
  int objectNum;
  Vec2f worldMapPos;
  Vec2f putWorldMapPos;
  EditMode mode;
  bool moveActive;
  OptionWindow oWindow;
  MapObject selectObject;


  bool Creating;
  Vec2f startPos;
  Vec2f endPos;
  Vec2f mousePosOnMapChip;
};