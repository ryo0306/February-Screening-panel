#include "Map.h"

//-------------------------------------------//
//     テキストファイルからdataを読み込み       //
//-------------------------------------------//
void Map::ReadFile(const std::string& file_)
{
  
  for (int i = 0; i < MapSize::WIDTH_; i++){
    for (int j = 0; j < MapSize::HEIGHT_; j++){
      stage[i][j] = 0;
      frame_color[i][j] = Color::black;
      press[i][j] = false;
    }
  }

  std::fstream ifs(file_);
  float dust;



  //ファイル読み込み失敗したら
  //assert(ifs);

  std::string row;
  
  int y = MapSize::HEIGHT_-1;
  while (std::getline(ifs, row)){
    int x = 0;
    for (auto map : row){
     
      if (map == '0')
        stage[x][y] = MapObject::NONEOBJECT;
      else if (map == '1')
        stage[x][y] = MapObject::WALL;
      else if (map == '2')
        stage[x][y] = MapObject::PENDULUM;
      else if (map == '3')
        stage[x][y] = MapObject::MAGNET;
      else if (map == '4')
        stage[x][y] = MapObject::START;
      else if (map == '5')
        stage[x][y] = MapObject::GOAL;
      else
        stage[x][y] = MapObject::NONEOBJECT;
      x += 1;
    }
    y -= 1;
  }
}


//-------------------------------------------//
//           マップチップの描画                //
//-------------------------------------------//
void Map::Draw()
{
 
  //DEBUG:
  mouse_pos = env.mousePosition();

  if (edit)
  {
    for (int x = 0; x < MapSize::WIDTH_; x++)
    {
      for (int y = 0; y < MapSize::HEIGHT_; y++)
      {
        if (Collision::BoxtoMouse(
          Vec2f(mouse_pos.x() + Window::WIDTH / 2,
          mouse_pos.y() + Window::HEIGHT / 2),
          Vec2f(1, 1),
          Vec2f(x*MAPCHIP_SIZE, y*MAPCHIP_SIZE),
          Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE)))
        {
          ChangeMap(x, y);
          frame_color[x][y] = Color::red;
        }
        else
        {
          frame_color[x][y] = Color::black;
        }
      }
    }
  }

  for (int x = 0; x < MapSize::WIDTH_; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT_; y++)
    {
      switch (stage[x][y])
      {
      case MapObject::NONEOBJECT:
        drawFillBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                    y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                    MAPCHIP_SIZE, MAPCHIP_SIZE,
                    Color::white);
          break;
        case MapObject::WALL:
          drawFillBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                      y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::navy);
          break;
        case MapObject::PENDULUM:
          drawFillBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                      y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::magenta);
          break;
        case MapObject::MAGNET:
          drawFillBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                      y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::blue);
          break;
        case MapObject::START:
          drawFillBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                      y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::yellow);
          break;
        case MapObject::GOAL:
          drawFillBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                      y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                      MAPCHIP_SIZE, MAPCHIP_SIZE,
                      Color::red);
          break;
      default:
        break;
      }
      if (edit)
      drawBox(x*MAPCHIP_SIZE - Window::WIDTH / 2,
                  y*MAPCHIP_SIZE - Window::HEIGHT / 2,
                  MAPCHIP_SIZE, MAPCHIP_SIZE,
                  5,frame_color[x][y]);
    }
  }
}


//-------------------------------------------//
//               エディットモード              //
//-------------------------------------------//
void Map::Edit(const std::string& file_)
{
  edit = true;

  if (env.isPressKey(GLFW_KEY_LEFT_CONTROL) && env.isPushKey(GLFW_KEY_S))
  {
    std::fstream ofs(file_, std::ios::out);
    if (ofs.fail())
      assert(1);

    for (int y = MapSize::HEIGHT_-1; y >= 0; y--)
    {
      for (int x = 0; x < MapSize::WIDTH_; x++)
      {
        if (stage[x][y] == 0)
        ofs << "0";
        else if (stage[x][y] == 1)
          ofs << "1";
        else if (stage[x][y] == 2)
          ofs << "2";
        else if (stage[x][y] == 3)
          ofs << "3";
        else if (stage[x][y] == 4)
          ofs << "4";
        else if (stage[x][y] == 5)
          ofs << "5";
      }
      ofs << std::endl;
    }
  }
}

//-------------------------------------------//
//               マップの更新                  //
//-------------------------------------------//
void Map::ChangeMap(int x_, int y_)
{
  if (env.isPressButton(Mouse::LEFT))
  {
    if (!press[x_][y_])
    {
      press[x_][y_] = true;
      stage[x_][y_] += 1;
    }
  }

  if (env.isPullButton(Mouse::LEFT))
  {
    for (int x = 0; x < MapSize::WIDTH_; x++)
      for (int y = 0; y < MapSize::HEIGHT_; y++)
        press[x][y] = false;
  }
  if (env.isPressButton(Mouse::RIGHT))
  {
      stage[x_][y_] = 0;
  }

  if (stage[x_][y_] > OBJECT_NUM-1)
  {
    stage[x_][y_] = 0;
  }
}

//-------------------------------------------//
//          マウスの現在座標を取得             //
//-------------------------------------------//
Vec2i Map::GetMousePos(){
  for (int x = 0; x < MapSize::WIDTH_; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT_; y++)
    {
      if (Collision::BoxtoMouse(
        Vec2f(mouse_pos.x() + Window::WIDTH / 2,
        mouse_pos.y() + Window::HEIGHT / 2),
        Vec2f(1, 1),
        Vec2f(x*MAPCHIP_SIZE, y*MAPCHIP_SIZE),
        Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE)))
      {
        mouse_pos_on_map = Vec2i(x, y);
      }
    }
  }
  return mouse_pos_on_map;
}
