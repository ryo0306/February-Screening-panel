
#include "Particle.h"


//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
Particle Particles::createParticle(const Vec2f& pos, Random& random) {
  Vec2f speed(0.0f, random(8.0f, 9.0f));

  // ���������x�N�g�������_�𒆐S�ɉ�]
  float angle = random(float(-M_PI), float(M_PI));
  speed = Eigen::Rotation2Df(angle) * speed;

  struct Particle p = {
    pos,
    speed,
    random(0.95f, 0.99f),
    random(7.0f, 10.0f),
    Color(random(0.7f, 1.0f), random(0.7f, 1.0f), random(0.7f, 1.0f)),
    random(60, 120)
  };

  return p;
}


//-------------------------------------------//
//               �`��̍X�V                   //
//-------------------------------------------//
void Particles::draw()
{
  // �\��
  for (const auto& p : particles) {
    drawFillCircle(p.position.x(), p.position.y(), p.radius, p.radius,
                   20, p.color);
  }
}

//-------------------------------------------//
//               �S�̂̍X�V                   //
//-------------------------------------------//
void Particles::Update(Vec2f pos) {

    // ����
  if (active){
    for (int i = 0; i < spawn_num; ++i) {
      Particle p = createParticle(pos, random);
      particles.push_back(p);
    }
    active = false;
  }

    // �X�V
    for (auto& p : particles) {
      p.position += p.speed + gravity;
      // ���x�͌������ɏ]���čX�V�����
      p.speed *= p.attenuation;

      // �������Ԃ����炷
      p.active_time -= 1;
    }

    // �������Ԃ�0�ɂȂ���Particle���R���e�i����폜
    particles.erase(std::remove_if(std::begin(particles), std::end(particles),
      [](const Particle& p) {
      return p.active_time == 0;
    }),
      std::end(particles));

}

//-------------------------------------------//
//          �X�V�t���O���I���ɂ���             //
//-------------------------------------------//
void Particles::switch_on()
{
  active = true;
}