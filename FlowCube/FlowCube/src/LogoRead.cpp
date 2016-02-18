#include "LogoRead.h"

void LogoRead::SetFilePath(std::string path_)
{
  path = path_;
}

void LogoRead::SearchData()
{
  path = "res/logo.text";

  std::fstream file(path);
  assert(file);

  file >> putData.x() >> putData.y();
  std::cout << putData << std::endl;
  return;
}