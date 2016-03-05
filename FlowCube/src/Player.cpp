#include "Player.h"
//-------------------------------------------//
//                  ������                    //
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
//               �S�̂̍X�V                   //
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
//               �S�̂̕`��                   //
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
//               �ړ��̍X�V                   //
//-------------------------------------------//
void Player::Move()
{
  
  pos += (move + addPos);
}


//-------------------------------------------//
//         �U��q���N���b�N�������Ƃ�          //
//-------------------------------------------//
void Player::PendulumActionPush()
{
  //�U��q�A�N�V����
  if (env.isPushButton(Mouse::LEFT))
  {
    rotateSpeed = 3 * key;
    // �}�E�X�̈ʒu���x�_��
    sPos = mousePos;
    //���W�A���p�x�����߂�
    rotate = (atan2(pos.y() - sPos.y(), pos.x() - sPos.x())) * 180 / M_PI;
    length = sqrt(((pos.x() - sPos.x()) * (pos.x() - sPos.x())) + ((pos.y() - sPos.y()) * (pos.y() - sPos.y())));
    chainActive = true;
  }
}


//-------------------------------------------//
//             �U��q�𗣂����Ƃ�              //
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
//             �U��q���̍X�V                 //
//-------------------------------------------//
void Player::PendulumUpdate()
{
  //�A�N�V�����̏ڍ�
  // ���������Ă���ԐU��q�̓���
  if (chainActive)
  {
    pos = Pendulum::AnGravity(pos, sPos, rotate, rotateSpeed, length);
  }
}

//-------------------------------------------//
//                �s������                   //
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