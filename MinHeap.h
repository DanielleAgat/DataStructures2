//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include "BinarySearchTree.h"
#include "HoffmanTree.h"
namespace DataQ2{
    class MinHeap{
    private:
        HoffmanTree* heapData;
        int phySize;
        int logSize;
        bool isAllocated; // 'true' if heap allocated memory ; 'false' otherwise.

        ///Inner Methods:
        // calc leftChild index
        static int left(int nodeIndex);
        // calc rightChild index
        static int right(int nodeIndex);
        // calc parent index
        static int parent(int nodeIndex);
        //fixHeap based on algorithm learned in class.
        void fixHeap(int nodeIndex);

    public:
        ///Constructors & Destructors:
        //Allocate memory for the heap and make the heap empty.
        MinHeap(int _phySize);
        //turns arr of frequencies and chars into min heap.
        MinHeap(HoffmanTree arr[],int size);
        //turns binarySearchTree into min heap.
        MinHeap(BinarySearchTree& BinarySearchTree);
        //destructor
        ~MinHeap();

        ///Methods:
        //return min without delete.
        HoffmanTree* min();
        // reset logSize
        void makeEmpty();
        //check if empty
        bool isEmpty() const;
        // return and delete min
        HoffmanTree* deleteMin();
        // insert HoffmanTree to heap
        void insert(HoffmanTree item);
        //make heap from BinarySearchTree based on floyd.
        void makeHeap(BinSearchNode* node);
        //Build HoffManTree as learned in class.
        HoffmanTree* buildHoffmanTree();
    };

    //swap 2 hoffmanTrees
    void swap(HoffmanTree& x, HoffmanTree& y);
}