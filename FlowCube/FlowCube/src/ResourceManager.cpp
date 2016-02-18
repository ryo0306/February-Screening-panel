#include "ResourceManager.h"



bool Resource::AudioManager::Insert(std::string file_path, AudioKey key)
{
  //キーをイテレーターに代入
  std::map<AudioKey, Media>::iterator it = resource.find(key);

  if (it != resource.end())
  {
    return false;
  }

  Media temp(file_path);
  resource.insert(std::make_pair(key, temp));
  return true;
}


// 情報を渡す
Media Resource::AudioManager::Get(AudioKey key)
{
  return resource.find(key)->second;
}

bool Resource::TextureManager::Insert(std::string file_path, TextureKey key)
{
  std::map<TextureKey, Texture>::iterator it = resource.find(key);

  if (it != resource.end())
  {
    return false;
  }

  Texture temp(file_path);
  resource.insert(std::make_pair(key, temp));
  return true;
}

//情報を渡す
Texture Resource::TextureManager::Get(TextureKey key)
{
  return resource.find(key)->second;
}