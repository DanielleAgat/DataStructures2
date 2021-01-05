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
        void makeEmpty(BinSearchNode* t);
        BinSearchNode* insert(char _key);
        BinSearchNode* findMin(BinSearchNode* t);
        BinSearchNode* findMax(BinSearchNode* t);
        BinSearchNode* remove(Pair x, BinSearchNode* t);
        void inorder(BinSearchNode* t);
        BinSearchNode* find(BinSearchNode* t, char x);
    public:
        ///Constructors & Destructors:
        BinarySearchTree();
        ~BinarySearchTree();

        ///Getters & Setters:
        int getBinSearchTreeSize() const { return logSize; };


        ///Methods:
        void insertV(char x);
        BinSearchNode* getRoot(){ return root; };
        void remove(Pair x);
        void display();
        BinSearchNode* find(char x);
    };
}
