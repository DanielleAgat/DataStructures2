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
    public:
        BinSearchNode();
        BinSearchNode(BinSearchNode* _right, BinSearchNode* _left, Pair _data);
        ~BinSearchNode();
    };
    class BinarySearchTree {
        friend class MinHeap;
    private:
        BinSearchNode* root;
        int logSize;

        ///Inner methods:
        //This method returns 'true' if the tree is empty ; 'false' otherwise


        //Inner method: frees all tree's memory and leaves the root as nullptr
        void makeEmpty(BinSearchNode* t);

        //Inner method: inserts a node to the tree in the right place
        BinSearchNode* insert(char _key, BinSearchNode* t);

        //Inner method: returns the min BinSearchNode in the tree (which is the most left node)
        BinSearchNode* findMin(BinSearchNode* t);

        //Inner method: returns the min BinSearchNode in the tree (which is the most right node)
        BinSearchNode* findMax(BinSearchNode* t);

        //Inner method: deletes the node with the given data in the tree (if exist).
        BinSearchNode* remove(Pair x, BinSearchNode* t);

        //Inner method: prints the tree's data inorder.
        void inorder(BinSearchNode* t);

        //Inner method: returns the BinSearchNode* with the given key ; returns nullptr if the key is not exist in the tree.
        BinSearchNode* find(BinSearchNode* t, char x);

    public:
        ///Constructors & Destructors:
        BinarySearchTree();
        ~BinarySearchTree();

        ///Getters & Setters:
        int getBinSearchTreeSize() const { return logSize; };
        BinSearchNode* getRoot(){ return root; };


        ///Methods:
        //This method inserts a node to the tree in the right place.
        void insert(char x);

        //This method deletes the node with the given data in the tree (if exist).
        void remove(Pair x);

        //This method prints the tree's data inorder.
        void printBinarySearchTree();

        //This method returns the BinSearchNode* with the given key ; returns nullptr if the key is not exist in the tree.
        BinSearchNode* find(char x);
    };
}
