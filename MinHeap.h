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
        static int left(int nodeIndex);
        static int right(int nodeIndex);
        static int parent(int nodeIndex);
        void fixHeap(int nodeIndex);

    public:
        ///Constructors & Destructors:
        MinHeap(int _phySize); //Allocate memory for the heap and make the heap empty.
        MinHeap(HoffmanTree arr[],int size); //turns arr of frequencies and chars into min heap.
        MinHeap(BinarySearchTree& BinarySearchTree,int size); //turns arr of frequencies and chars into min heap.
        ~MinHeap();

        ///Methods:
        HoffmanTree min();
        HoffmanTree* deleteMin();
        void insert(HoffmanTree item);
        void makeHeap(BinSearchNode* node);
        HoffmanTree* buildHoffmanTree();
    };

    void swap(HoffmanTree* x, HoffmanTree* y);
}