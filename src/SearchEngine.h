#ifndef MOVIESEARCHENGINE_SEARCHENGINE_H_
#define MOVIESEARCHENGINE_SEARCHENGINE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

class SearchEngine {
  private:
  
  public:

    SearchEngine(std::vector<std::string> &movieTitles){
      std::ifstream file("../data/MovieTitles.txt");
      if(!file.is_open()){
        std::cout << "Error opening MovieTitles file. Run scraper.py." << std::endl;
        exit(1);
      }
          
      std::string line;
      while(getline(file, line)){
        if(line.empty())
          continue;
        
        movieTitles.push_back(line);

      }

    }

    void getMostSimilar(std::vector<std::string> &movieTitles, std::vector<std::string> &mostSimilar, 
                        std::string query);

};


#endif 
