//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include <iostream>
#include <fstream>
#include "HoffmanTree.h"
#include "MinHeap.h"
#include "BinarySearchTree.h"

using namespace std;
using namespace DataQ2;

void readFile(string fileName, BinarySearchTree& BinarySearchTree);

int main(){
    string fileName;
    BinarySearchTree BinarySearchTree;
    cout<<"enter file name: ";
    cin>> fileName;

    readFile(fileName, BinarySearchTree);
    MinHeap minHeap(BinarySearchTree);
    HoffmanTree* hoffmanTree = minHeap.buildHoffmanTree();
    hoffmanTree->printHoffmanTree();
}

void readFile(string fileName, BinarySearchTree& BinarySearchTree) {
    char currC;
    ifstream infile(fileName);

    if (!infile) {
        cout << "invalid input" << endl;
        exit(1);
    }
    infile.get(currC);
    while (!infile.eof()) {
        if (infile.eof()) {
            cout << "invalid input"<< endl;
            exit(1);
        }
        BinarySearchTree.insertV(currC); //TODO: Consider find the char in the tree, and if find then insert to the returned node, else insert
        infile.get(currC);
    }
    infile.close();
}

   
