#ifndef MOVIESEARCHENGINE_SEARCHENGINE_H_
#define MOVIESEARCHENGINE_SEARCHENGINE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <queue>
#include <thread>
#include <mutex>

struct pqLess {
  bool operator()(const std::pair<uint8_t, uint16_t> &a, const std::pair<uint8_t, uint16_t> &b){
    return a.first < b.first;
  }
};

class SearchEngine {
  private:
    uint8_t threadCount;

    std::vector<std::string> movieTitles;

    std::priority_queue< std::pair<uint8_t, uint16_t>, 
                         std::vector<std::pair<uint8_t, uint16_t>>, 
                         pqLess > pq;
    std::mutex *mux;

    void getMostSimilar(std::vector<std::string> &mostSimilar, std::string &query, uint16_t start, uint16_t end);
  
  public:
    SearchEngine(const SearchEngine &obj)
      :threadCount(std::move(obj.threadCount)), movieTitles(std::move(obj.movieTitles)),
       pq(std::move(obj.pq)){

         //mutex is not copyable.
         mux = new std::mutex();
       } 

    SearchEngine(uint16_t threads)
      :threadCount(threads){
       mux = new std::mutex(); 

      std::ifstream file("../data/MovieTitles.txt");


      if(!file.is_open()){
        std::cout << "Error opening MovieTitles file. Run scraper.py." << std::endl;
        exit(1);
      }

      movieTitles.reserve(60000); //approx number of titles
          
      std::string line;
      while(getline(file, line)){
        if(line.empty())
          continue;

  // This removes year information from titles
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
  
    ~SearchEngine(){
      delete mux;
    }  

    void createThreads(std::vector<std::string> &mostSimilar, std::string &query);


};


#endif 
