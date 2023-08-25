#ifndef CELL_HEADER
#define CELL_HEADER

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <map>

#define sizeY 7
#define sizeX 7

using namespace std;

struct Cell{
  string type;
  pair <int,int> position;
};



#endif CELL_HEADER