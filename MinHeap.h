//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include "BinarySearchTree.h"

namespace DataQ2{
    class MinHeap{
    private:
        Pair* data;
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
        MinHeap(Pair arr[],int size); //turns arr of frequencies and chars into min heap.
        ~MinHeap();

        ///Methods:
        Pair min();
        Pair deleteMin();
        void insert(Pair item);
        void swap(Pair* x, Pair* y);
    };
}