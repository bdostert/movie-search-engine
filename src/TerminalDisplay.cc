#include "TerminalDisplay.h"

void TerminalDisplay::update(){

  char buf[9 * 50];
  std::string line, query;

  std::memset(buf, ' ', height * width - 1);

  std::vector<std::string> mostSimilar(height - 2);


  //setting border---------------------------------------
  pos = (height * width) - width + 1;
  std::memset(buf, '-', width - 1); //top line
  std::memset(buf + pos - width, '-', width - 1); //second last line
                                                  
  for(int i = 1; i < height; ++i){
    buf[width * i - 1] = '|';   
    buf[width * (i - 1)] = '|';   
  }
  std::cout << "Search: ";
  //-----------------------------------------------------

    printf("\x1b[H");
    for(int i = 0; i < height * width; ++i){
      putchar(i % width ? buf[i] : 10);
    }
    
  printf("\x1b[2J");

  do{
    std::getline(std::cin, line);
    query += line;
    char c = line.back();
    //std::cin.get(c);

    if(pos / height >= width - 1){
      std::cout << "Too many input characters" << std::endl;
      exit(1);
    }

    if(c == '\b'){
      //buf[pos] = ' ';
      pos = std::max(3, pos - 1);
    }
    //else
      //buf[++pos] = c; 
    

   // std::string query(buf + (height * width) - width + 8, buf + pos);
    searchEngine.getMostSimilar(mostSimilar, query);
//    std::cout << "QUERY = " << query << "\n";
        

    for(auto s : mostSimilar){
    //    std::cout << s << "\n";
        assert(!s.empty());
    }
    
    for(uint8_t i = 0; i < height - 3; ++i){
      std::memset(buf + width * (i + 1) + 4, ' ', width - 5); //clearing line
      
      buf[width * (i + 1) + 2] = '0' + i + 1; 
      buf[width * (i + 1) + 3] = '.';
      buf[width * (i + 1) + 4] = ' ';

                                                                          
      for(uint8_t j = 0; j < mostSimilar[i].size(); ++j)
        buf[width * (i + 1) + 4 + j] = mostSimilar[i][j]; 
                                                                          
      //std::memcpy(buf[width * (i + 1) + 2], mostSimilar[i], mostSimilar[i].length()); 
    }
    


    printf("\x1b[H");
    for(int i = 0; i < height * width; ++i){
      putchar(i % width ? buf[i] : 10);
    }
    std::cout << "\rSearch: " << query;

  }while(line.back() != '~');
    
}
