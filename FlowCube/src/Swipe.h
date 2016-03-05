#pragma once
#include "ScreenMake.h"

class Swipe
{
public:

  Swipe(){};
  void SetUp();
  void Update();

  // �X���C�v���Ă��钷�����擾
  Vec2f GetRange(){ return range; }

  // �X���C�v�����Ă邩�ǂ���
  bool GetSwiping(){ return swiping; }

  // �����I�ɃX���C�v���I��
  void offSwiping(){ swiping = false; }

  // �ǂꂮ�炢�X���C�v����Δ������邩��ݒ�
  // float   rangeLimit_     ����
  void SetRangeLimit(Vec2f rangeLimit_){ rangeLimit = rangeLimit_; }

  // 1�t���[���O�Ƃ̍����擾
  // if(GetOneFreameDifferencce() < num(����))
  // �ŉE����num���X���C�v���̏������������Ƃł���B
  Vec2f GetOneFrameDifference();


private:

  bool swiping;                    // �X���C�v���Ă��邩�ǂ���
  Vec2f mousePos;                  // �}�E�X�̈ʒu
  Vec2f startPos;                  // �X���C�v�J�n�ʒu
  Vec2f endPos;                    // �X���C�v�I���ʒu�i���ݒn�j
  Vec2f range;                     // �X���C�v���Ă��鋗��
  Vec2f putRange;                  // 1�t���[���O��range
  Vec2f rangeLimit;                // �ǂꂾ���X���C�v����Δ������邩
};