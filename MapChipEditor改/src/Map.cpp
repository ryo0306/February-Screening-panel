#include "Map.h"
//TODO:ŠÖ”‰»


void Map::FileRead(std::string path_)
{



  mapSize = (Window::HEIGHT / MapSize::WIDTH_ * 2);
  worldMapPos = Vec2f(-Window::WIDTH/2,-Window::HEIGHT/2);
  objectNum = 7;
  mode = EditMode::ObjectEdit;
  oWindow.SetUp(Vec2f(Window::WIDTH/2 - 200,-Window::HEIGHT/2),Vec2f(200,Window::HEIGHT),Color::cyan);
  moveActive = false;
  Creating = false;
  selectObject = MapObject::NONEOBJECT;
  std::fstream ifs(path_);
  assert(ifs);

  while (!ifs.eof())
  {
    ReadData put;
    ifs >> put.num
      >> put.pos.x() >> put.pos.y()
      >> put.size.x() >> put.size.y();
    put.num += 1;
    CriateObject(put.pos, put.size, put.num);
  }
  for (int i = 0; i < ObjectNum-1; i++)
  {
    objects[i].num = i;
  }
}

void Map::Edit()
{
  mousePos = env.mousePosition();
  
  ChangeSize();
  if (!Collision::BoxtoMouse(oWindow.GetPos(), oWindow.GetSize(), mousePos, Vec2f(1, 1)))
  {
    WindowManager();
    CreateAction();
  }
  IconManager();

  for (int x = 0; x < MapSize::WIDTH_; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT_; y++)
    {
      if (Collision::BoxtoMouse(
        Vec2f(mousePos.x() + Window::WIDTH / 2,
        mousePos.y() + Window::HEIGHT / 2),
        Vec2f(1, 1),
        Vec2f(x*mapSize, y*mapSize),
        Vec2f(mapSize, mapSize)))
      {
        frameColor[x][y] = Color::red;
        mousePosOnMapChip = Vec2f(x, y);
      }
      else
      {
        frameColor[x][y] = Color::black;
      }
    }
  }
  oWindow.Update();
}

void Map::Draw()
{
  env.bgColor(Color::white);
  for (int x = 0; x < MapSize::WIDTH_; x++)
  {
    for (int y = 0; y < MapSize::HEIGHT_; y++)
    {
      drawBox(x*mapSize + worldMapPos.x(),
              y*mapSize + worldMapPos.y(),
              mapSize, mapSize, 3,
              frameColor[x][y]);
    }
  }

  if (Creating)
  {
    drawFillBox(startPos.x(), startPos.y(), endPos.x() - startPos.x(), endPos.y() - startPos.y(), Color(0.5f, 0.5f, 0.5f, 0.5f));
  }
  
  for (int i = 0; i < ObjectNum - 1; i++)
  {
    for (auto& o : objects[i].onj)
    {
      o.Draw();
    }
  }
  oWindow.Draw();
  drawPoint(mousePosOnMapChip.x() * mapSize + worldMapPos.x(), mousePosOnMapChip.y() * mapSize + worldMapPos.y(), 30, Color::red);

}


void Map::ChangeSize()
{
  if (env.isPressKey(GLFW_KEY_UP))
  {
    mapSize++;
  }

  if (env.isPressKey(GLFW_KEY_DOWN))
  {
    mapSize--;
  }

 }


void Map::WindowManager()
{
  
   
    if (mode == EditMode::Move)
    {
      if (env.isPushButton(Mouse::LEFT))
      {
        moveActive = true;
        putWorldMapPos = mousePos - worldMapPos;
      }

      if (moveActive)
      {
        worldMapPos = mousePos - putWorldMapPos;
      }

      if (env.isPullButton(Mouse::LEFT))
      {
        moveActive = false;
      }
    }
  
}


void Map::IconManager()
{
  for (int i = 0; i < ObjectNum; i++)
  {
    if (Collision::BoxtoMouse(oWindow.icons[i].GetPos(), oWindow.icons[i].GetSize(), mousePos, Vec2f(1, 1)))
    {
      if (env.isPullButton(Mouse::LEFT))
      {
        oWindow.ActiveAllClear();
        oWindow.icons[i].SetActive(true);
        selectObject = MapObject(i);
      }
    }
  }
}


void Map::CreateAction()
{
  if (mode == EditMode::ObjectEdit)
  {
    if (selectObject != MapObject::NONEOBJECT)
    {
      Vec2f putSize = endPos -startPos;
      if (env.isPushButton(Mouse::LEFT))
      {
        Creating = true;
        startPos = mousePosOnMapChip * mapSize + worldMapPos;
      }

      if (Creating)
      {
        endPos = mousePosOnMapChip  * mapSize + worldMapPos;

      }

      if (env.isPullButton(Mouse::LEFT))
      {
        Creating = false;
        bool onObject = false;
        //ŠÖ”‰»H
        Vec2f CheckSize = SizeCheck() - Vec2f(mapSize, mapSize)*2;
        Vec2f CheckPos = startPos + Vec2f(mapSize, mapSize);
        for (int i = 0; i < ObjectNum - 1; i++)
        {
          for (int j = 0; j < objects[i].onj.size(); j++)
          {
            
            if (Collision::BoxtoBox(CheckPos, CheckSize, objects[i].onj[j].GetPos(), objects[i].onj[j].GetSize()))
            {
              onObject = true;
            }
          }
        }

        if (putSize.x() != 0 && putSize.y() != 0)
        if (!onObject)
        {
          putSize = SizeCheck();
          CriateObject(startPos, putSize, selectObject);
        }

      }
    }
    else
    {
      DeleteAction();
    }
  }
}

void Map::CriateObject(Vec2f pos_, Vec2f size_, int objectNum_)
{
  MapObject put = MapObject(objectNum_);
  switch (objectNum_)
  {
  case NONEOBJECT:
    break;
  case WALL:
   objects[0].onj.push_back(Object(Color::navy, pos_, size_));
    break;
  case RPENDULUM:
    objects[1].onj.push_back(Object(Color::magenta, pos_, size_));
    break;
  case LPENDULUM:
    objects[2].onj.push_back(Object(Color::lime, pos_, size_));
    break;
  case MAGNET:
    objects[3].onj.push_back(Object(Color::blue, pos_, size_));
    break;
  case START:
    objects[4].onj.push_back(Object(Color::yellow, pos_, size_));
    break;
  case GOAL:
    objects[5].onj.push_back(Object(Color::red, pos_, size_));
    break;
  default:
    break;
  }
}



void Map::DeleteAction()
{
  for (int i = 0; i < ObjectNum - 1; i++)
  {
    for (int j = 0; j < objects[i].onj.size();j++)
    {
      if (Collision::BoxtoMouse(objects[i].onj[j].GetPos(), objects[i].onj[j].GetSize(), mousePos, Vec2f(1, 1)))
      {
        if (env.isPushButton(Mouse::LEFT))
        {
          objects[i].onj.erase(objects[i].onj.begin() + j);
        }
      }
    }
  }
}



void Map::WrightData(std::string path_)
{
  std::ofstream ofs(path_);

  assert(ofs);

  for (int i = 0; i < ObjectNum - 1; i++)
  {
    for (int j = 0; j < objects[i].onj.size(); j++)
    {
      ofs << objects[i].num << " "
        << objects[i].onj[j].GetPos().x() << " " << objects[i].onj[j].GetPos().y() << " "
        << objects[i].onj[j].GetSize().x() << " " << objects[i].onj[j].GetSize().y()
        << std::endl;
    }
  }

}

Vec2f Map::SizeCheck()
{
  Vec2f putSize = endPos - startPos;

  if (putSize.x() < 0)
  {
    startPos.x() += putSize.x();
    putSize.x() = abs(putSize.x());
  }
    
  if (putSize.y() < 0)
  {
    startPos.y() += putSize.y();
    putSize.y() = abs(putSize.y());
  }

  return putSize;
}