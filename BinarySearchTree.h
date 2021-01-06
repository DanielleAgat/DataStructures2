//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#pragma once
#include<iostream>
using namespace std;
namespace DataQ2 {
    typedef struct{
        char key;
        float frequency;
    }Pair;
    class BinSearchNode {
        friend class BinarySearchTree;
        friend class MinHeap;
    private:
        Pair data;
        BinSearchNode* left;
        BinSearchNode* right;

        ///Inner methods:
        //Inner method: return an array of pair according to the binary search tree (inorder).
        void makeDataArrHelper(Pair* arr,const BinSearchNode *t,int& i)const;

    public:
        ///Constructors & Destructors:
        BinSearchNode();
        BinSearchNode(const BinSearchNode* toCopy);
        BinSearchNode(BinSearchNode* _right, BinSearchNode* _left, Pair _data);
        ~BinSearchNode();

        ///Getters:
        char getKey() const { return data.key; };
        float getFrequency() const { return data.frequency; };

        ///Methods:
        //This method return an array of pair according to the binary search tree (inorder).
        Pair* makeDataArr(int phySize,int& logSize)const;

        ///Overriding operators:
        BinSearchNode& operator=(const BinSearchNode& toCopy);

    };
    class BinarySearchTree {
        friend class MinHeap;
    private:
        BinSearchNode* root;
        int logSize;

        ///Inner methods:
        //Inner method: frees all tree's memory and leaves the root as nullptr
        void makeEmpty(BinSearchNode* t);

        //Inner method: inserts a node to the tree in the right place
        BinSearchNode* insert(char _key);

        //Inner method: returns the min BinSearchNode in the tree (which is the most left node)
        BinSearchNode* findMin(BinSearchNode* t)const;

        //Inner method: returns the min BinSearchNode in the tree (which is the most right node)
        BinSearchNode* findMax(BinSearchNode* t)const;

        //Inner method: deletes the node with the given data in the tree (if exist).
        BinSearchNode* remove(Pair x, BinSearchNode* t);

        //Inner method: prints the tree's data inorder.
        void inorder(const BinSearchNode* t)const;

        //Inner method: returns the BinSearchNode* with the given key ; returns nullptr if the key is not exist in the tree.
        BinSearchNode* find(BinSearchNode* t, char x)const;

    public:
        ///Constructors & Destructors:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& t);
        ~BinarySearchTree();

        ///Getters & Setters:
        int getBinSearchTreeSize() const { return logSize; };
        BinSearchNode* getRoot(){ return root; };


        ///Methods:
        //This method frees all tree's memory and leaves the root as nullptr
        void makeEmpty();

        //This method returns 'true' if the tree is empty ; 'false' otherwise
        bool isEmpty() const;

        //This method inserts a node to the tree in the right place.
        void insertV(char x);

        //This method deletes the node with the given data in the tree (if exist).
        void remove(Pair x);

        //This method prints the tree's data inorder.
        void printBinarySearchTree()const;

        //This method returns the BinSearchNode* with the given key ; returns nullptr if the key is not exist in the tree.
        BinSearchNode* find(char x)const;

        //copy binary search tree
        BinSearchNode* copyBinarySearchTree(const BinSearchNode* toCopy) const;

        ///Overriding operators:
        BinarySearchTree& operator=(const BinarySearchTree& toCopy);

    };
}
