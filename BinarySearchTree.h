//
// Created by Aviv Nevelev on 21/12/2020.
//
#pragma once
#include<iostream>
using namespace std;
namespace DataQ2 {
    typedef struct{
        char key;
        int frequency;
    }Pair;
    class NODE {
        friend class BinarySearchTree;
    private:
        Pair data;
        NODE *left;
        NODE *right;
    public:
        NODE();
        NODE(NODE *_right,NODE *_left,Pair _data);
        ~NODE();
        //const NODE& operator=(const NODE& node);
    };
    class BinarySearchTree {
        NODE *root;
        void makeEmpty(NODE *t);
        NODE *insert(Pair x, NODE *t);
        NODE *findMin(NODE *t);
        NODE *findMax(NODE *t);
        NODE *remove(Pair x, NODE *t);
        void inorder(NODE *t);
        NODE *find(NODE *t, Pair x);
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Pair x) {root=insert(x, root);}// check if no need root=insert(x, root);
        void remove(Pair x) {root=remove(x, root);}
        void display() {inorder(root);cout << endl;}
        NODE * find(Pair x) {return find(root, x);}
    };
}
