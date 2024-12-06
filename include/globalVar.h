#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H
#include "../include/node.h"
#include <cstring>
#include <vector>
#include <map>
using namespace std;

extern char* fileNameIn;
extern char* fileNameOut;
extern int charFreq[1000];
extern string line;
extern vector<Node*> lst;  // list node in heap while building tree
extern int compressData[256];
extern int codeBook[256];  // code of canonical form
extern vector <pair<int, char>> lstCanonical;     // list for building canonical huffman code
extern int originalSize;
extern int compressSize;
#endif