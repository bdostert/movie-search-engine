#include "TerminalDisplay.h"

void TerminalDisplay::update(std::vector<std::string> &movieTitles){

  char c, buf[9 * 50];

  std::memset(buf, height * width - 1, ' ');

  std::vector<std::string> mostSimilar(height - 2);
  SearchEngine searchEngine(movieTitles);

  //setting border---------------------------------------
  for(int i = 1; i < height - 1; ++i){
    buf[width * i - 1] = '|';   
    buf[width * (i + 1) - 1] = '|';   
  }
  pos = (height * width) - width + 1;
  std::memset(buf, width - 1, '-'); //top line
  std::memset(buf + pos - width, (height * width) - width, '-'); //second last line
  for(auto letter : "Search: ")
      buf[pos++] = letter;
  //-----------------------------------------------------

    printf("\x1b[H");
    for(int i = 0; i < height * width; ++i){
      putchar(i % width ? buf[i] : 10);
    }
    
  //std::memcpy(buf + (height * width) - width + 1, initSearch, 7);

  printf("\x1b[2J");
  std::cin >> c;

  while(c != '~'){

    if(pos / height >= width - 1){
      std::cout << "Too many input characters" << std::endl;
      exit(1);
    }

    if(c == '\b'){
      buf[pos] = ' ';
      --pos;
    }
    else{
      ++pos;
      buf[pos] = c; 
    }


    searchEngine.getMostSimilar(movieTitles, mostSimilar,
        std::string(buf + (height * width) - width + 7, buf + pos));
        
    for(auto s : mostSimilar){
      std::cout << s << "\n";
        assert(!s.empty());
    }
    
    for(uint8_t i = 0; i < height - 3; ++i){
      std::memset(buf + width * (i + 1) + 3, width * (i + 2) - 1, ' '); //clearing line
                                                                          
      for(uint8_t j = 0; j < mostSimilar[i].size(); ++j)
        buf[width * (i + 1) + 3 + j] = mostSimilar[i][j]; 
                                                                          
      //std::memcpy(buf[width * (i + 1) + 2], mostSimilar[i], mostSimilar[i].length()); 
    }


    printf("\x1b[H");
    for(int i = 0; i < height * width; ++i){
      putchar(i % width ? buf[i] : 10);
    }

  }
}
