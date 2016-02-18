
#include "Particle.h"


//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
Particle Particles::createParticle(const Vec2f& pos, Random& random) {
  Vec2f speed(0.0f, random(8.0f, 9.0f));

  // 生成したベクトルを原点を中心に回転
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
//               描画の更新                   //
//-------------------------------------------//
void Particles::draw()
{
  // 表示
  for (const auto& p : particles) {
    drawFillCircle(p.position.x(), p.position.y(), p.radius, p.radius,
                   20, p.color);
  }
}

//-------------------------------------------//
//               全体の更新                   //
//-------------------------------------------//
void Particles::Update(Vec2f pos) {

    // 生成
  if (active){
    for (int i = 0; i < spawn_num; ++i) {
      Particle p = createParticle(pos, random);
      particles.push_back(p);
    }
    active = false;
  }

    // 更新
    for (auto& p : particles) {
      p.position += p.speed + gravity;
      // 速度は減衰率に従って更新される
      p.speed *= p.attenuation;

      // 生存時間を減らす
      p.active_time -= 1;
    }

    // 生存時間が0になったParticleをコンテナから削除
    particles.erase(std::remove_if(std::begin(particles), std::end(particles),
      [](const Particle& p) {
      return p.active_time == 0;
    }),
      std::end(particles));

}

//-------------------------------------------//
//          更新フラグをオンにする             //
//-------------------------------------------//
void Particles::switch_on()
{
  active = true;
}