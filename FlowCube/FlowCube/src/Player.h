#pragma once
#include "Object.h"
#include "common.h"
#include "Particle.h"
#define SPEED (0.5f)
#define ANIMATION_TIME 120

//動さするのはプレイヤーと考える

class Player : public Object
{
public:
  Player(){}
  void SetUp(Vec2f pos_, Vec2f move_);
  void Update();
  void Draw();
  void SetActive(bool active_){ active = active_; };
  bool CheckActive(){ return active; }
  bool CheakDead(){ return dead; }
  void AddMove(Vec2f add_){ move += add_; }
  void AddPos(Vec2f add_){ addPos = add_; }
  void PendulumActionPush();
  void PendulumActionPull();
  void PendulumUpdate();
  void MoveLimit();
  void SetDemo(bool demo_){ demo = demo_; }
private:
  void Move();

  Vec2f move;
  bool active;
  int animationTime;
  bool dead;
  Vec2f centerPos;
  float range;
  float angle;
  float angleSpeed;
  bool chainActive;
  bool demo;
  Vec2f putPos;
  Vec2f addPos;
  Particles particle;
  Media playerbreak = Media("res/break.wav");
};