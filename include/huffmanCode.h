#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <map>
#include "node.h"
#include "heapSort.h"
#include "globalVar.h"
#include "utils.h"

#define fi first
#define se second
#define pb push_back
using namespace std;

struct HuffmanCompressing{
    Node* root = nullptr;
    
    void buildHuffmanTree(void){
        int n = lst.size();
        HeapSort heapSort(lst);
        heapSort.buildHeap(lst.size());
        while(n > 1){
            Node* l = heapSort.getTop(n);
            Node* r = heapSort.getTop(n);
            Node* node = new Node();
            node->value = l->value + r->value;
            // cout << l->value << " " << r->value << " " << node->value << endl;
            node->l = l;
            node->r = r;
            heapSort.pushHeap(n, node);
        }
        root = heapSort.getTop(n);
    }
    
    void getMask(Node* root, int bitSize){
        if (root->l == nullptr && root->r == nullptr){
            compressData[root->ch] = bitSize;
            if (bitSize == 0) compressData[root->ch] = 1;
            return;    // Speacial case for single character
        }
        getMask(root->l, bitSize + 1);
        getMask(root->r, bitSize + 1);
    }

    void getMask(void){
        getMask(root, 0);
    }

    void deleteTree(Node* root){
        if (root == nullptr) return;
        deleteTree(root->l);
        deleteTree(root->r);
        delete root;
    }
};

struct CanonicalHuffmanTree{
    Node* root = nullptr;
    
    void buildCode(void){
        int curBit = 0;
        bool isFirst = true;
        int curLength = 0;
        for (int i = 0; i < lstCanonical.size(); i++){
            int bitLength = lstCanonical[i].fi;
            char ch = lstCanonical[i].se;
            if (isFirst == false) curBit = curBit + 1;
            isFirst = false;
            curBit = curBit << (bitLength - curLength);
            curLength = bitLength;
            // cout << ch << " " << bitLength << " " <<curBit << endl;
            codeBook[ch] = curBit;
        }
    }

    void buildTree(Node* root, char ch, int code, int bitLength){
        if (bitLength == 0){
            root->ch = ch;
            return;
        }
        bool bit = code >> (bitLength - 1) & 1;
        if (bit == 0){
            if (root->l == nullptr){
                root->l = new Node();
            }
            buildTree(root->l, ch, code, bitLength - 1);
        }
        else{
            if (root->r == nullptr){
                root->r = new Node();
            }
            buildTree(root->r, ch, code, bitLength - 1);
        }
    }
    void buildCanonicalHuffmanTree(void){
        root = new Node();
        for (int i = 0; i < lstCanonical.size(); i++){
            char ch = lstCanonical[i].se;
            int bitLength = lstCanonical[i].fi;
            buildTree(root, ch, codeBook[ch], bitLength);
        }
    }
    void deleteTree(Node* root){
        if (root == nullptr) return;
        deleteTree(root->l);
        deleteTree(root->r);
        delete root;
    }
};

#endif