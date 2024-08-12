#include "SearchEngine.h"


struct pqLess {
  bool operator()(const std::pair<uint8_t, std::string> &a, const std::pair<uint8_t, std::string> &b){
    return a.first < b.first;
  }
};

//compare query with all movieTitles using 
void SearchEngine::getMostSimilar(std::vector<std::string> &movieTitles, std::vector<std::string> &mostSimilar, 
                                  std::string query){

//  std::vector<uint8_t> mostSimilarCost(mostSimilar.size(), 100);

  std::priority_queue< std::pair<uint8_t, std::string>, 
                       std::vector<std::pair<uint8_t, std::string>>, 
                       pqLess > pq;
    
  for(auto &title : movieTitles){
    uint8_t m = query.length(), n = title.length(), prev = 0;
    //std::vector<std::vector<uint8_t>> dp(m + 1, std::vector<uint8_t>(n + 1, 0));
    
    std::vector<uint8_t> curr(n + 1, 0);

    for(uint8_t j = 0; j <= n; ++j)
        curr[j] = j;

    for(uint8_t i = 0; i <= m; ++i){
      prev = curr[0];
      curr[0] = i;
      for(uint8_t j = 0; j <= n; ++j){
        auto temp = curr[j];
        if(query[i - 1] == title[j - 1])
          curr[j] = prev;
        
        else
            curr[j] = 1 + std::min({prev, curr[j - 1], curr[j]});
      prev = temp;

      }
    }

    if(pq.empty() || pq.size() < mostSimilar.size())
      pq.emplace(curr[n], title);
    else{
      if(curr[n] < pq.top().first){
        pq.pop();
        pq.emplace(curr[n], title);
      }
    } 

    }
    for(uint8_t i = 0; i < static_cast<uint8_t>(mostSimilar.size()); ++i){
      mostSimilar[i] = pq.top().second;
      pq.pop();
    }

  }
