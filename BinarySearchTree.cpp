//
// Created by Aviv Nevelev on 21/12/2020.
//

#include "BinarySearchTree.h"
namespace DataQ2 {
    NODE::NODE():right(nullptr),left(nullptr) {
        data.frequency=-1;
        data.key=0;
    }
    NODE::NODE(NODE *_right,NODE *_left,Pair _data):right(_right),left(_left){
        data.frequency=_data.frequency;
        data.key=_data.key;
    }
    NODE::~NODE() {}
    BinarySearchTree::BinarySearchTree():root(nullptr){}
    BinarySearchTree::~BinarySearchTree(){makeEmpty(root);}
    void BinarySearchTree::makeEmpty(NODE *t) {
        if (t == nullptr)
            return;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
    }

    NODE *BinarySearchTree::insert(Pair x, NODE *t) {
        if (t == nullptr) {
            t=new NODE(nullptr, nullptr,x);
        } else if (x.key < t->data.key)
            t->left = insert(x, t->left);
        else if (x.key > t->data.key)
            t->right = insert(x, t->right);
        return t;
    }

    NODE *BinarySearchTree::findMin(NODE *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    NODE *BinarySearchTree::findMax(NODE *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    NODE *BinarySearchTree::remove(Pair x, NODE *t) {
        NODE *temp;
        if(t == nullptr)
            return nullptr;
        else if(x.key < t->data.key)
            t->left = remove(x, t->left);
        else if(x.key > t->data.key)
            t->right = remove(x, t->right);

        if (t->left && t->right) {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        } else {
            temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
        }

        return t;
    }
    /*
    const NODE& NODE::operator=(const NODE& node){
        data.key=node.data.key;
        data.frequency=node.data.frequency;
        right=node.right;
        left=node.left;
        return *this;
    }
     */
    void BinarySearchTree::inorder(NODE *t) {
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data.key << " ";
        inorder(t->right);
    }

    NODE *BinarySearchTree::find(NODE *t, Pair x) {
        if (t == nullptr)
            return nullptr;
        else if (x.key < t->data.key)
            return find(t->left, x);
        else if (x.key > t->data.key)
            return find(t->right, x);
        else
            return t;
    }
}