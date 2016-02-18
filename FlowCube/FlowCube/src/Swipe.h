#pragma once
#include "ScreenMake.h"

class Swipe
{
public:

  Swipe(){};
  void SetUp();
  void Update();

  // スワイプしている長さを取得
  Vec2f GetRange(){ return range; }

  // スワイプをしてるかどうか
  bool GetSwiping(){ return swiping; }

  // 強制的にスワイプを終了
  void offSwiping(){ swiping = false; }

  // どれぐらいスワイプすれば反応するかを設定
  // float   rangeLimit_     長さ
  void SetRangeLimit(Vec2f rangeLimit_){ rangeLimit = rangeLimit_; }

  // 1フレーム前との差を取得
  // if(GetOneFreameDifferencce() < num(距離))
  // で右側にnum文スワイプ時の処理を書くことできる。
  Vec2f GetOneFrameDifference();


private:

  bool swiping;                    // スワイプしているかどうか
  Vec2f mousePos;                  // マウスの位置
  Vec2f startPos;                  // スワイプ開始位置
  Vec2f endPos;                    // スワイプ終了位置（現在地）
  Vec2f range;                     // スワイプしている距離
  Vec2f putRange;                  // 1フレーム前のrange
  Vec2f rangeLimit;                // どれだけスワイプすれば反応するか
};