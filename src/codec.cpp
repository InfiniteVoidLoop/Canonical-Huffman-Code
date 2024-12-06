#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <time.h>
#include "../include/codec.h"
#include "../include/utils.h"
#include "../include/globalVar.h"
#include "../include/huffmanCode.h"

void decompressToTextFile(void)  // decode data
{ 
    cerr << "Decompressing data, please wait . . ." << endl;
    fstream fileIn(fileNameIn, ios::in | ios::binary);
    fstream fileOut(fileNameOut, ios::out);

    if (!fileIn.is_open())
    {
        cout << "Can't open file " << fileNameIn << endl;
        return;
    }
    if (!fileOut.is_open())
    {
        cout << "Can't open file " << fileNameOut << endl;
        return;
    }
    
    // Read table for decoding data
    int table_size;
    char buffer;
    fileIn.read(&buffer, 1);
    table_size = (unsigned char)buffer;

    for (int i = 0; i < table_size; i++){
        char ch = 0;
        int bitLength = 0;
        fileIn.read(&ch, 1);
        fileIn.read(&buffer, 1);
        bitLength = (unsigned char)buffer;
        lstCanonical.push_back(make_pair(bitLength, ch));
    }

    // Build tree in canoncal form
    CanonicalHuffmanTree canonicalHuffmanTree;
    canonicalHuffmanTree.buildCode();
    canonicalHuffmanTree.buildCanonicalHuffmanTree();

    // Read padding
    int curPos = fileIn.tellg();
    fileIn.seekg(0, ios::end);
    int padding;
    fileIn.seekg(-1, ios::end);
    fileIn.read(&buffer, 1);
    padding = (unsigned char)buffer;
    fileIn.seekg(curPos, ios::beg);

    // Read compress data
    int byte, numBit = 0;
    fileIn.seekg(-1, ios::end);
    int lastByte = fileIn.tellg();
    fileIn.seekg(curPos, ios::beg);
    Node* root = canonicalHuffmanTree.root;
    while (fileIn.tellg() != lastByte - 1)
    {
        fileIn.read(&buffer, 1);
        byte = (unsigned char)buffer;
        for (int i = 7; i >= 0; --i)
        {
            bool bit = (byte >> i) & 1;
            if (bit == 0) root = root->l;
            else root = root->r;
            if (root->l == nullptr && root->r == nullptr)
            {
                fileOut << root->ch;
                root = canonicalHuffmanTree.root;
            }
        }
    }
    // Read the last byte of the binary file
    fileIn.read(&buffer, 1);
    byte = (unsigned char)buffer;

    for (int i = 7; i >= padding; --i)
    {
        bool bit = (byte >> i) & 1;
        if (bit == 0) root = root->l;
        else root = root->r;

        if (root->l == nullptr && root->r == nullptr){
            fileOut << root->ch;
            root = canonicalHuffmanTree.root;
        }   
    }
    canonicalHuffmanTree.deleteTree(canonicalHuffmanTree.root);
    cout << "Decompressing successfully" << endl;
    fileIn.close();
    fileOut.close();
}

void compressToBinaryFile(void)   // compress data
{ 
    fstream fileOut(fileNameOut, ios::out | ios::binary);
    if (!fileOut.is_open())
    {
        cout << "Can't open file " << fileNameOut << endl;
        return;
    }
    cout << "Compressing data, please wait . . ." << endl;
    HuffmanCompressing huffmanCompressing;
    huffmanCompressing.buildHuffmanTree();
    huffmanCompressing.getMask();
    huffmanCompressing.deleteTree(huffmanCompressing.root);

    // Write table for decoding data
    int table_size = 0;
    for (int i = 0; i < 256; i++){
        if (charFreq[i] == 0) continue;
        table_size++;
        lstCanonical.push_back(make_pair(compressData[i], char(i)));   
    }

    sort(lstCanonical.begin(), lstCanonical.end());

    fileOut.write((char *)&table_size, 1);
    for (int i = 0; i < lstCanonical.size(); i++){
        char ch = lstCanonical[i].se;
        char bitLength = lstCanonical[i].fi;
        fileOut.write((char *)&ch, 1);
        fileOut.write((char *)&bitLength, 1);
    }
    // Change to canonical form
    CanonicalHuffmanTree canonicalHuffmanTree;
    canonicalHuffmanTree.buildCode();

    // Compress Data
    
    
    int numBit = 0;
    int remainBit, byte;
    int maxLength = 0;
    for (int i = 0; line[i]; i++)
    {
        char ch = line[i];
        // cout << ch << " " << codeBook[ch] << endl;
        int bitLength = compressData[int(ch)];
        maxLength = max(maxLength, bitLength);

        while (bitLength > 0) {
            remainBit = 8 - numBit;
            if (remainBit >= bitLength){
                byte = (byte << bitLength) | codeBook[ch];
                numBit += bitLength;
                bitLength = 0;
            }
            else{
                bitLength -= remainBit;
                byte = (byte << remainBit) | (codeBook[ch] >> bitLength);
                fileOut.write((char *)&byte, 1);
                numBit = 0;
                byte = 0;
            }
        }
    }
    
    remainBit = 8 - numBit; 
    int padding = remainBit;
    byte = byte << padding;
    fileOut.write((char *)&byte, 1);
    fileOut.write((char *)&padding, 1);
    originalSize = line.size();
    compressSize = fileOut.tellp();
    cout << "Compressing successfully" << endl;    
    // cout << "Max bit length: " << maxLength << endl;

    fileOut.close();
}