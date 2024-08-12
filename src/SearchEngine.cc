#include "SearchEngine.h"



//compare query with all movieTitles using 
void SearchEngine::getMostSimilar(std::vector<std::string> &mostSimilar, 
                                  std::string &query){

  uint16_t index = 0;
  for(auto &title : movieTitles){
    uint8_t m = query.length(), n = title.length(), prev = 0;
    
    std::vector<uint8_t> curr(n + 1, 0);

    for(uint8_t j = 0; j <= n; ++j){
      curr[j] = j;
    }

    for(uint8_t i = 1; i <= m; ++i){
      prev = curr[0];
      curr[0] = i;
      for(uint8_t j = 1; j <= n; ++j){
        auto temp = curr[j];
        if(tolower(query[i - 1]) == tolower(title[j - 1]))
          curr[j] = prev;
        else
          curr[j] = 1 + std::min({prev, curr[j - 1], curr[j]});
        prev = temp;
      }
    }

      if(pq.empty() || pq.size() < mostSimilar.size())
        pq.emplace(curr[n], index);

      else{

        if(curr[n] < pq.top().first){
          pq.pop();
          pq.emplace(curr[n], index);
        }
      } 
      ++index;

    }
    uint8_t pos = mostSimilar.size() - 1;
    while(!pq.empty()){
      mostSimilar[pos--] = movieTitles[pq.top().second];
      pq.pop();
    }

  }
