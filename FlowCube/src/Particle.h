#pragma once
#include "ScreenMake.h"


struct Particle {
  Vec2f position;
  Vec2f speed;

  // Œ¸Š—¦
  // 1.0‚æ‚è‘å‚«‚¢: Ÿ‘æ‚É‘¬‚­‚È‚é
  // 1.0:           ‘¬“x‚ğˆÛ
  // 1.0‚æ‚è¬‚³‚¢: Ÿ‘æ‚É’x‚­‚È‚é
  float attenuation;

  float radius;
  Color color;

  // ¶‘¶ŠÔ(0‚ÅI—¹)
  int active_time;
};


class Particles
{

  public:

    void Update(Vec2f pos);
    void draw();
    void switch_on();
  private:
 
    Random random;

  Particle createParticle(const Vec2f& pos, Random& random);

  std::vector<Particle> particles;
  bool active = false;

  
};

const Vec2f gravity(0.0, -0.0);
const int spawn_num = 50;