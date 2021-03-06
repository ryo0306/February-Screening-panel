﻿#include "SceneManager.h"

//TODO:Titleからstageselectに移行
//     するときに何か工夫をしたい
//TODO:Pendulumを右回りと左回りで別のギミックとする。
//TODO:新しいギミックの追加
//     真っ暗なステージで
//     音波を発して壁に当たると壁の場所がわかる。
//     反射壁(これは前回と同じためなるべく実装したくない)
//     バグ
//     道中にある修正プログラムを入手後実行するとバグが治る
//     (ゲートとスイッチみたいなもの)

//TODO:ステージの追加をもっと簡潔に
//TODO:ギミック使用時になにかアクションを起こす
//TODO:リザルトの改良
//TODO:全体の操作をマウスだけにする


int main(){

  env;
  SceneManager sceneManager;
  sceneManager.SetUp();
 
  while (env.isOpen())
  {
    env.begin();

    sceneManager.Update();  //更新
    sceneManager.Draw();    //描画

    env.end();
  }

  return 0;
}


// 今回の反省点
//

// オブジェクトをもっと細分化するべきだった
//　 →例えばPlayerの前にFlowObjectなどをつくるべき
//    動くのはなにもPlayerとはかぎらない。

// クラスの機能をもっと細かくするべき
//   →継承した時に汎用性が高くなる。

// シーン分けでポインターで行ったため、シーン同士の情報交換を
// 少し制限がかかってしまったこと
//   →検討中

// ファイル読み込み用の関数が多くできてしまったこと。
//   →継承などを使うといいかも？
//    またはなるべく一つのファイルで読み込みができるようにするべき。


// 次回したい事
//○プログラム面
// 前提として上記の失敗の改善策を実行し検証したい。
// Editorの基礎になるものをつくる。
// ファイル読み込みなどをもともと持っていて
// 継承すれば使えるようになるなど。
// Gametemplateを改良して、自分の使いやすいように変える。


//○ゲームデザイン面
// ゲーム本編以外でも遊べるようにしたい（本編第一）
// ゲームオーバーはあってもいいがゲームオーバーを苦にさせない作り
// 例えば死んでもそれが次の時に＋になる。
// ゲームオーバーはこちら側でゲーム終了の区切りをつけてしまうことになってしまい
// 長くゲームをやってもらえない
// 次は成功するかもと思わせれるような失敗してもリターンが大きくて何回でもやってしまうような
// ゲームをつくる。


//○プランニング面
// スケジュールを組む
// このゲームの見どころ、やり所を決定してからゲーム制作に入る。（ゲームを触ってみようと思わせる）
// 大目標と小目標を掲げモチベーションを切らさないようにする。
// ユーザーにどういう風に思ってプレイしてほしいか決める。（）
// ユーザーが何を求めてるから何をつくったという根拠をしっかり持つ。（）