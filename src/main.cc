#include "TerminalDisplay.h"
#include "SearchEngine.h"
#include "BufferToggle.h"


int main(int argc, char *argv[]){
  //std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
  
  BufferToggle toggle;
  toggle.off();

  SearchEngine searchEngine(8);
  TerminalDisplay terminalDisplay(searchEngine);

  terminalDisplay.update(); 

  return 0;
}
