#pragma once
#include <map>
#include <iostream>

//  ファイルが開けたかどうか
static void FileCheck(bool result){
  if (!result){
    std::cout << "Load fail" << std::endl;
  }
  else{
    std::cout << "Load Success" << std::endl;
  }
}