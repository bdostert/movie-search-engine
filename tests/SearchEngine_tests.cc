#include "SearchEngine_tests.h"


int SearchEngine_tests::basic(){

  SearchEngine searchEngine(8);

  vector<string> mostSimilar(10);
  string query = "the prnicess brdie";
//  cout << "QUERY: " << query << "\n";
  //getline(cin, query);

  searchEngine.createThreads(mostSimilar, query);

  for(int i = 0; i < static_cast<int>(mostSimilar.size()); ++i){
    if(!mostSimilar[i].empty())
      return 0;

  //  cout << i + 1 << ". " << mostSimilar[i] << "\n";
  }

  //assert(mostSimilar[0] == "The Princess Bride");
 // cout << "\nSearchEngine_basic Test Complete\n";

  return 1;
}

int SearchEngine_tests::threadCount(){
    
  vector<pair<int, clock_t>> threadCountTimes;
  threadCountTimes.reserve(100);


  for(int i = 1; i < 100; ++i){
    clock_t start = clock();
    SearchEngine searchEngine(i);
    vector<string> mostSim(6);

    string query = "american pie";
    searchEngine.createThreads(mostSim, query);
    threadCountTimes.emplace_back(i, clock() - start);
  }
  clock_t low = clock();
  int threadCount = 0;
   for(auto &t : threadCountTimes){
     if(t.second < low){
       threadCount = t.first;
       low = min(low, t.second);
      }
     cout << t.first << " " << t.second << "\n";
   }
   cout << "\nFastest time = " << (float)low/CLOCKS_PER_SEC<< " seconds with " << threadCount << " threads.\n";
  
  return 1;
}

