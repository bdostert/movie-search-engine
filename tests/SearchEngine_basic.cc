#include "../src/SearchEngine.h"
#include <cassert>

using namespace std;


int main(int argc, char *argv[]){
  ios_base::sync_with_stdio(0);


  SearchEngine searchEngine;

  vector<string> mostSimilar(10);
  string query = "the prnicess brdie";
  cout << "QUERY: " << query << "\n";
  //getline(cin, query);

  searchEngine.getMostSimilar(mostSimilar, query);

  for(int i = 0; i < static_cast<int>(mostSimilar.size()); ++i){
    assert(!mostSimilar[i].empty());

    cout << i + 1 << ". " << mostSimilar[i] << "\n";
  }

  //assert(mostSimilar[0] == "The Princess Bride");
  cout << "\nSearchEngine_basic Test Complete\n";

  return 0;
}
