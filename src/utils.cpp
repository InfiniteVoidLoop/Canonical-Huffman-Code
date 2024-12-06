#include "../include/utils.h"
#include "../include/globalVar.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

string getExtension(char* fileName){
    string res ="";
    for (int i = strlen(fileName) - 1; i >= 0; i--){
        if (fileName[i] == '.'){
            break;
        }
        res = fileName[i] + res;
    }
    return res;
}

void readTextFile(char* fileName){
    fstream fileIn(fileName, ios::in);
    if (!fileIn.is_open()){
        cout << "Can't open file " << fileName << endl;
        return;
    }
    string temp;
    bool check = false;
    while (!fileIn.eof()){
        getline(fileIn, temp);
        line += temp + "\n";
        check = true;
    }
    if (check) {
        line.pop_back();
    }
    fileIn.close();
}

 void getFrequency(void){
    for (int i = 0; i < line.size(); i++){    
       charFreq[(int)line[i]] += 1;
    }
    for (int i = 0; i < 256; i++){
        if (charFreq[i] > 0){
            Node* node = new Node();
            node->ch = (char)i;
            node->value = charFreq[i];
            lst.push_back(node);
        }
    }
}

void compressInfo(char* fileNameIn, char* fileNameOut){
    cout << "\n";
    cout << "================== Compression Info ==================" << endl;
    cout << "Input file: " << fileNameIn << endl;
    cout << "Output file: " << fileNameOut << endl;
    cout << "Original file size: " << originalSize << " bytes" << endl;
    cout << "Compressed file size: " << compressSize << " bytes" << endl;
}
