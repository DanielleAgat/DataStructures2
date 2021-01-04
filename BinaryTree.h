//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include <iostream>
using namespace std;

namespace DataQ2{
    struct binTreeNode{
        char data; //only relevant in leaves
        float frequency;
        binTreeNode *left;
        binTreeNode *right;
    };

    class btree{
    private:
        binTreeNode *root;

        ///Methods:
        void make_empty(binTreeNode *leaf);
        void insert(float key,char _data, binTreeNode *leaf);
        binTreeNode *search(float key, binTreeNode *leaf);
        void inorder_print(binTreeNode *leaf);
        void postorder_print(binTreeNode *leaf);
        void preorder_print(binTreeNode *leaf);

    public:
        ///Constructors & Destructors:
        btree();
        btree(const btree& toCopy);
        ~btree();

        ///Getters:
        float getRootKey() { return root->frequency; }
        char getRootData() {return root->data;}
        binTreeNode* getRoot(){return root;}

        ///Methods:
        void insert(float key,char _data);
        binTreeNode *search(float key);
        void make_empty();
        void inorder_print();
        void postorder_print();
        void preorder_print();
        void addSons(btree& leftSon, btree& rightSon);
        void printHoffmanTree() const;
        void _hoffman(binTreeNode* root, string s, float& count)const;
        binTreeNode* copyHelper(const binTreeNode* toCopy);

        ///Override operators:
        btree& operator=(const btree& otherTree);

//        binTreeNode* huffman(binTreeNode c[], int n){
//            PriorityQueue q(c,n); // Initialize Q to contain forest of leaves
//            binTreeNode* node;
//
//            for(int i=1 ; i < n ; i++){
//                node = new binTreeNode();
//                node->left = q.deleteMin();
//                node->right = q.deleteMin();
//                node->frequency = node->left->frequency + node->right->frequency;
//                q.insert(node);
//            }
//            return q.deleteMin();
//        }

    };


}