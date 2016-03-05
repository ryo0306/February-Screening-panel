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
  angle = 0;
  addPos = Vec2f(0,0);
  rotateSpeed = 2;
  chainActive = false;
  animationTime = ANIMATION_TIME;
  demo = false;
  key = PendulumKey::PLEFT;
}


//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void Player::Update()
{

  mousePos = env.mousePosition();
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
    rotateSpeed = 3 * key;
    // マウスの位置を支点に
    sPos = mousePos;
    //ラジアン角度を求める
    rotate = (atan2(pos.y() - sPos.y(), pos.x() - sPos.x())) * 180 / M_PI;
    length = sqrt(((pos.x() - sPos.x()) * (pos.x() - sPos.x())) + ((pos.y() - sPos.y()) * (pos.y() - sPos.y())));
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
      float angle = rotateSpeed / 180 * M_PI;
      chainActive = false;
      move.x() = length * angle * cos(rotate / 180 * M_PI + M_PI / 2);
      move.y() = length * angle * sin(rotate / 180 * M_PI + M_PI / 2);
    }
}

//-------------------------------------------//
//             振り子時の更新                 //
//-------------------------------------------//
void Player::PendulumUpdate()
{
  //アクションの詳細
  // 長押ししている間振り子の動き
  if (chainActive)
  {
    pos = Pendulum::AnGravity(pos, sPos, rotate, rotateSpeed, length);
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