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
    BinarySearchTree BinarySearchTree;
    string fileName;

    cout<<"please enter file name: "; cin>> fileName;
    readFile(fileName, BinarySearchTree);
    MinHeap minHeap(BinarySearchTree, BinarySearchTree.getBinSearchTreeSize() );
    HoffmanTree* hoffmanTree = minHeap.buildHoffmanTree();

    hoffmanTree->printHoffmanTree();
    cout<<endl;
}

void readFile(string fileName, BinarySearchTree& BinarySearchTree) {
    char currC;
    ifstream infile(fileName);

    if (!infile) {
        cout << "Error with infile" << endl;
        exit(-1);
    }

    infile.get(currC);
    while (!infile.eof()) {
        if (infile.eof()) {
            cout << "Error reading" << endl;
            exit(-1);
        }
        BinarySearchTree.insert(currC); //TODO: Consider search the char in the tree, and if find then insert to the returned node, else insert
        infile.get(currC);
    }
    infile.close();



//    char currC;
//    ifstream infile(fileName);
//
//    if (!infile) {
//        cout << "Error with infile" << endl;
//        exit(-1);
//    }
//
//    infile.get(currC);
//    while (!infile.eof()) {
//        if (infile.eof()) {
//            cout << "Error reading" << endl;
//            exit(-1);
//        }
//        BinarySearchTree.insert(currC); //TODO: Consider search the char in the tree, and if find then insert to the returned node, else insert
//        infile.get(currC);
//    }
//    infile.close();

}

   
