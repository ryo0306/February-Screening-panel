#pragma once
#include "ScreenMake.h"


struct Particle {
  Vec2f position;
  Vec2f speed;

  // ������
  // 1.0���傫��: ����ɑ����Ȃ�
  // 1.0:           ���x���ێ�
  // 1.0��菬����: ����ɒx���Ȃ�
  float attenuation;

  float radius;
  Color color;

  // ��������(0�ŏI��)
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