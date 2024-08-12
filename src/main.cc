#include "TerminalDisplay.h"


int main(int argc, char *argv[]){
//  std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
  
  TerminalDisplay t;

  std::vector<std::string> movieTitles; movieTitles.reserve(50000);

  t.update(movieTitles); 

  return 0;
}
