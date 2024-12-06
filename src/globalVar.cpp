#include "../include/globalVar.h"
#include "../include/node.h"
#include <cstring>
#include <vector>
#include <map>
using namespace std;

char* fileNameIn;
char* fileNameOut;
int charFreq[1000];
string line;
vector<Node*> lst;  // list node in heap while building tree
int compressData[256];  // code values and bit length of huffman tree
int codeBook[256];  // code of canonical form
vector <pair <int,char >> lstCanonical;     // list for building canonical huffman code
int compressSize;
int originalSize;

