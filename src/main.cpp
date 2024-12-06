#include "../include/node.h"
#include "../include/heapSort.h"
#include "../include/huffmanCode.h"
#include "../include/globalVar.h"
#include "../include/utils.h"
#include "../include/codec.h"
#include <cstring>
#include <time.h>
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3){
        cout << "Not enough arguments !!! " << endl;
        return 0;
    }
    fileNameIn = argv[1];
    fileNameOut = argv[2];
    
    // Get extension of files
    string extFileIn = getExtension(fileNameIn);
    string extFileOut = getExtension(fileNameOut);
    
    if (extFileIn == "txt" && extFileOut == "bin"){
        clock_t startTime = clock();
        readTextFile(argv[1]);
        getFrequency();
        compressToBinaryFile();
        cout << "Execution time: " << (clock() - startTime) / CLOCKS_PER_SEC << "s" << endl;
        compressInfo(fileNameIn, fileNameOut);
    }
    else if (extFileIn == "bin" && extFileOut == "txt"){
        clock_t startTime = clock();
        decompressToTextFile();
        cout << "Execution time: " << (clock() - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }
    else{
        cout << "Invalid extension !!!" << endl;
    }
    return 0;
}  