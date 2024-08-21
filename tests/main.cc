#include "SearchEngine_tests.h"
#include <iostream>


int main(int argc, char *argv[]){

  SearchEngine_tests searchTest;
    
  if(!searchTest.basic())
      std::cout << "Failed SearchEngin_basic\n";

//  if(!searchTest.threadCount())
  //    std::cout << "Failed SearchEngin_threadCount\n";
  

  return 0;
}
