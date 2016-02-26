#pragma once
#include <string>
#include <fstream>
#include<sstream>
#include "ScreenMake.h"
#include "Collision.h"
#include "common.h"
#define OBJECT_NUM 7
//TODO?:EDITMODEと分けるべき

//TODO:オブジェクトを増やしたらOBJECT_NUMも増やす
enum MapObject
{
   NONEOBJECT,
   WALL,
   PENDULUM,
   MAGNET,
   START,
   GOAL,
};

enum MapSize
{
  WIDTH_ = 32,
  HEIGHT_ = 18,
};

class Map
{
public:
  Map()
  {
    for (int i = 0; i < MapSize::WIDTH_; i++){
      for (int j = 0; j < MapSize::HEIGHT_; j++){
        stage[i][j] = 0;
        frame_color[i][j] = Color::black;
        press[i][j] = false;
      }
    }
    edit = false;
   
  }

  void SetUp(){};
  void ReadFile(const std::string& file_);
  void Draw();
  void Edit(const std::string& file_);
  void ChangeMap(int x_, int y_);
  Vec2i GetMousePos();
  int GetMapData(int x, int y){ return stage[x][y]; }
private:
  bool edit;
  int stage[MapSize::WIDTH_][MapSize::HEIGHT_];
  Color frame_color[MapSize::WIDTH_][MapSize::HEIGHT_];
  Vec2f mouse_pos;
  Vec2i mouse_pos_on_map;
  bool press[MapSize::WIDTH_][MapSize::HEIGHT_];
};