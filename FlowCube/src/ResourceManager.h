#pragma once
#include "ScreenMake.h"
#include "Common.hpp"
#define ReadTex ResourceManager::Texture()
#define ReadAud ResourceManager::Audio()


//  呼び出すために必要なキー
enum class AudioKey
{

};

enum class TextureKey
{
  START,
};


namespace Resource
{
  class AudioManager
  {
  public:
    AudioManager(){}
    bool Insert(std::string file_path_, AudioKey key);
    Media Get(AudioKey key);
  private:
    std::map<AudioKey , Media> resource;
  };
  /*
  pScene nextScene_;
  
  if () { nextScene_ = scene::create<Main>(); }
  else if () { nextScene_ = scene::create<Option>(); }
  return nextScene_;

  */
  class TextureManager
  {
  public:
    TextureManager(){}
    bool Insert(std::string file_path, TextureKey key);
    Texture Get(TextureKey Key);
  private:
    std::map<TextureKey, Texture> resource;
  };
};

class ResourceManager
{
public:
  ResourceManager(ResourceManager&) = delete;
  //シングルトン
  static Resource::AudioManager& Audio()
  {
    static Resource::AudioManager audio;
    return audio;
  }

  static Resource::TextureManager& Texture()
  {
    static Resource::TextureManager texture;
    return texture;
  }
private:

  ResourceManager(){}
};