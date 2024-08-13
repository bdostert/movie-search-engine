#ifndef MOVIESEARCHENGINE_SEARCHENGINE_H_
#define MOVIESEARCHENGINE_SEARCHENGINE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <queue>

struct pqLess {
  bool operator()(const std::pair<uint8_t, uint16_t> &a, const std::pair<uint8_t, uint16_t> &b){
    return a.first < b.first;
  }
};

class SearchEngine {
  private:
    std::vector<std::string> movieTitles;

    std::priority_queue< std::pair<uint8_t, uint16_t>, 
                         std::vector<std::pair<uint8_t, uint16_t>>, 
                         pqLess > pq;
  
  public:
    SearchEngine(){
      std::ifstream file("../data/MovieTitles.txt");

      movieTitles.reserve(60000); //approx number of titles

      if(!file.is_open()){
        std::cout << "Error opening MovieTitles file. Run scraper.py." << std::endl;
        exit(1);
      }
          
      std::string line;
      while(getline(file, line)){
        if(line.empty())
          continue;

  // This removes year information from titles, not sure if this is better
/*        for(uint8_t i = 0; i < static_cast<uint8_t>(line.size()); ++i){
          if(i && line[i] == '(') {
            line.resize(i - 1);
            break;
          }
        }
*/      
        movieTitles.push_back(line);
      }

    }

    void getMostSimilar(std::vector<std::string> &mostSimilar, std::string &query);

};


#endif 
