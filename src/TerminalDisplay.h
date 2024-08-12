#ifndef MOVIESEARCHENGINE_TERMINALDISPLAY_H_
#define MOVIESEARCHENGINE_TERMINALDISPLAY_H_

#include "SearchEngine.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <cassert>

class TerminalDisplay {
  private:
    uint16_t height = 9, width = 50, pos = 0;
    

  public:
    TerminalDisplay(){}

    void update(std::vector<std::string> &movieTitles);
};

#endif 
