#pragma once
#include <map>
#include <iostream>

//  �t�@�C�����J�������ǂ���
static void FileCheck(bool result){
  if (!result){
    std::cout << "Load fail" << std::endl;
  }
  else{
    std::cout << "Load Success" << std::endl;
  }
}