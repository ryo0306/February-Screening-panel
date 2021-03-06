#pragma once
#include "ScreenMake.h"


struct Particle {
  Vec2f position;
  Vec2f speed;

  // 減衰率
  // 1.0より大きい: 次第に速くなる
  // 1.0:           速度を維持
  // 1.0より小さい: 次第に遅くなる
  float attenuation;

  float radius;
  Color color;

  // 生存時間(0で終了)
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