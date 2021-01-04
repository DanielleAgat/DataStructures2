//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "MinHeap.h"

namespace DataQ2{
    MinHeap::MinHeap(int _phySize){
        phySize = _phySize;
        data = new Pair[phySize];
        logSize = 0;
        isAllocated = true;
    }

    MinHeap::MinHeap(Pair arr[],int size) {
        logSize = phySize = size;
        data = arr;
        isAllocated = false;

        for(int i = size/2-1 ; i >= 0 ; i--)
            fixHeap(i);
    }

    MinHeap::~MinHeap(){
        if(isAllocated)
            delete[] data;
        data = nullptr;
    }

    int MinHeap::left(int nodeIndex){
        return (2*nodeIndex + 1);
    }
    int MinHeap::right(int nodeIndex){
        return (2*nodeIndex + 2);
    }
    int MinHeap::parent(int nodeIndex){
        return (nodeIndex-1)/2;
    }

    void MinHeap::fixHeap(int nodeIndex){
        int min;
        int _left = left(nodeIndex);
        int _right = right(nodeIndex);

        if((_left < logSize) && (data[_left].frequency < data[nodeIndex].frequency)){
            min = _left;
        }else{
            min = nodeIndex;
        }
        if((_right < logSize) && (data[_right].frequency < data[min].frequency)){
            min = _right;
            //Swap values if necessary and continue fixing the heap towards the leaves:
            if(min != nodeIndex){
                swap(&data[nodeIndex],&data[min]); //TODO: The swap function is unknown, need to implement one by our own.
                fixHeap(min);
            }
        }
    }

    Pair MinHeap::deleteMin() {
        if(logSize < 1){
            cout << "There is no data left in the heap. There is no min value to delete." << endl;
            exit(1);
        }else{
            Pair min = data[0];
            logSize--;
            data[0] = data[logSize];
            fixHeap(0);
            return (min);
        }
    }

    void MinHeap::insert(Pair item) {
        if(logSize == phySize){
            cout << "Heap is full! Cannot add data anymore" << endl;
            exit(1);
        }
        int i = logSize;
        logSize++;

        while((i > 0) && (data[parent(i)].frequency > item.frequency)){
            data[i] = data[parent(i)];
            i = parent(i);
        }
        data[i] = item;
    }


    void MinHeap::swap(Pair* x, Pair* y){
        Pair temp = *x;
        *x = *y;
        *y = temp;
    }



}