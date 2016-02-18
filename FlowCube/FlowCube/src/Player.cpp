#include "Player.h"
//-------------------------------------------//
//                  初期化                    //
//-------------------------------------------//
void Player::SetUp(Vec2f pos_, Vec2f move_)
{
  pos = pos_;
  move = move_;
  size = Vec2f(MAPCHIP_SIZE, MAPCHIP_SIZE);
  dead = false;
  active = true;
  centerPos = Vec2f(0, 0);
  range = 0;
  angle = 0;
  addPos = Vec2f(0,0);
  angleSpeed = 0;
  chainActive = false;
  animationTime = ANIMATION_TIME;
  demo = false;
}


//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void Player::Update()
{
  if (active)
  {
    Move();
  }


  if (!active)
  {
  
    if (animationTime == ANIMATION_TIME-1)
    {
      playerbreak.play();
      particle.switch_on();
    }
    if (animationTime <= 0)
    {
      dead = true;
    }
    particle.Update(pos);
    animationTime--;
  }

  MoveLimit();
}


//-------------------------------------------//
//               全体の描画                   //
//-------------------------------------------//
void Player::Draw()
{
  if (active)
  {
    drawFillBox(pos.x(), pos.y(), size.x(), size.y(), Color::cyan);
  }
  else
  particle.draw();
}


//-------------------------------------------//
//               移動の更新                   //
//-------------------------------------------//
void Player::Move()
{
  
  pos += (move + addPos);
}


//-------------------------------------------//
//         振り子をクリックをしたとき          //
//-------------------------------------------//
void Player::PendulumActionPush()
{
  //振り子アクション
  if (env.isPushButton(Mouse::LEFT))
  {
    centerPos = env.mousePosition();
    putPos.x() = pos.x() + size.x() / 2;
    putPos.y() = pos.y() + size.y() / 2;
    range = sqrt(((putPos.x() - centerPos.x())*(putPos.x() - centerPos.x()))
                 + ((putPos.y() - centerPos.y())*(putPos.y() - centerPos.y())));


    angle = atan2((putPos.y() - centerPos.y())
                  , (putPos.x() - centerPos.x()));
    //TODO1:
    angleSpeed = (move.x() / cos(angle + M_PI / 2) + move.y() / sin(angle + M_PI / 2)) / 200  ;
    if (angleSpeed > 0.07f)
    {
      angleSpeed = 0.07f;
    }
    if (angleSpeed < -0.07f)
    {
      angleSpeed = -0.07f;
    }
    chainActive = true;
  }
}


//-------------------------------------------//
//             振り子を離したとき              //
//-------------------------------------------//
void Player::PendulumActionPull()
{
  if (chainActive)
  if (env.isPullButton(Mouse::LEFT))
  {
    move.x() = angleSpeed * 100 * cos(angle + M_PI / 2);
    move.y() = angleSpeed * 100 * sin(angle + M_PI / 2);
    chainActive = false;
    angleSpeed = 0;
  }
}

//-------------------------------------------//
//             振り子時の更新                 //
//-------------------------------------------//
void Player::PendulumUpdate()
{
  //アクションの詳細
  if (chainActive)
  {

    pos.x() = (centerPos.x() + range * cos(angle))-size.x()/2;
    pos.y() = (centerPos.y() + range * sin(angle))-size.y()/2;
  

    angle += angleSpeed;
  }
}

//-------------------------------------------//
//                行動制限                   //
//-------------------------------------------//
void Player::MoveLimit()
{
  if (!demo)
  {
    if (-Window::HEIGHT / 2 > pos.y() || Window::HEIGHT / 2 < pos.y())
    {
      active = false;
    }
    if (-Window::WIDTH / 2 > pos.x() || Window::WIDTH / 2 < pos.x())
    {
      active = false;
    }
  }
}