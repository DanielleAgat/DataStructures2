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
    private:
        BinSearchNode* root;

        ///Inner methods:
        void makeEmpty(BinSearchNode* t);
        BinSearchNode* insert(Pair x, BinSearchNode* t);
        BinSearchNode* findMin(BinSearchNode* t);
        BinSearchNode* findMax(BinSearchNode* t);
        BinSearchNode* remove(Pair x, BinSearchNode* t);
        void inorder(BinSearchNode* t);
        BinSearchNode* find(BinSearchNode* t, Pair x);
    public:
        ///Constructors & Destructors:
        BinarySearchTree();
        ~BinarySearchTree();

        ///Methods:
        void insert(Pair x);
        void remove(Pair x);
        void display();
        BinSearchNode* find(Pair x);
    };
}