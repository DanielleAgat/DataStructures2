//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "MinHeap.h"

namespace DataQ2{
    MinHeap::MinHeap(int _phySize){
        phySize = _phySize;
        heapData = new HoffmanTree[phySize];
        logSize = 0;
        isAllocated = true;
    }
    MinHeap::MinHeap(BinarySearchTree &BinarySearchTree) :MinHeap(BinarySearchTree.getBinSearchTreeSize()){
        makeHeap(BinarySearchTree.root);
    }

    MinHeap::MinHeap(HoffmanTree arr[],int size) {
        logSize = phySize = size;
        heapData = arr;
        isAllocated = false;

        for(int i = size/2-1 ; i >= 0 ; i--)
            fixHeap(i);
    }

    MinHeap::~MinHeap(){
        if(isAllocated)
            delete[] heapData;
        heapData = nullptr;
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

    void MinHeap::fixHeap(int nodeIndex) {
        int min;
        int _left = left(nodeIndex);
        int _right = right(nodeIndex);

        if ((_left < logSize) && (heapData[_left].getRootKey() < heapData[nodeIndex].getRootKey())) {
            min = _left;
        } else {
            min = nodeIndex;
        }
        if ((_right < logSize) && (heapData[_right].getRootKey() < heapData[min].getRootKey()))
            min = _right;
        //Swap values if necessary and continue fixing the heap towards the leaves:
        if (min != nodeIndex) {
            swap(heapData[nodeIndex], heapData[min]);
            fixHeap(min);
        }
    }

    HoffmanTree* MinHeap::deleteMin() {
        if(logSize < 1){
            cout << "There is no heapData left in the heap. There is no min value to delete." << endl;
            exit(1);
        }else{
            HoffmanTree* min = new HoffmanTree();
            *min = *heapData;
            logSize--;
            heapData[0] = heapData[logSize];
            fixHeap(0);
            return min;
        }
    }

    void MinHeap::insert(HoffmanTree item) {
        if(logSize == phySize){
            cout << "Heap is full! Cannot add heapData anymore" << endl;
            exit(1);
        }
        int i = logSize;
        logSize++;

        while((i > 0) && (heapData[parent(i)].getRootKey() > item.getRootKey())){
            heapData[i] = heapData[parent(i)];
            i = parent(i);
        }
        heapData[i] = item;
    }

    //TODO: change
    void MinHeap::makeHeap(BinSearchNode* node){
        if (!node)
            return;
        makeHeap(node->left);
        HoffmanTree HoffmanTree;
        HoffmanTree.insert(node->data.frequency, node->data.key);
        insert(HoffmanTree);
        makeHeap(node->right);
    }

    HoffmanTree* MinHeap::buildHoffmanTree(){
        HoffmanTree* hoffmanTree;
        if(logSize == 1)
            hoffmanTree = deleteMin();
        else{
            while(logSize>1){
                HoffmanTree* t1 = deleteMin();
                HoffmanTree* t2 = deleteMin();
                HoffmanTree* t3 = new HoffmanTree();
                t3->addSons(*t1, *t2);
                insert(*t3);
            }
            hoffmanTree = deleteMin();
        }
        return hoffmanTree;
    }

    void swap(HoffmanTree& x, HoffmanTree& y){
        HoffmanTree temp = x;
        x = y;
        y = temp;
    }

}
