//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include <iostream>

using namespace std;

namespace DataQ2{
    struct HoffTreeNode{
        char data; //only relevant in leaves
        float frequency;
        HoffTreeNode *left;
        HoffTreeNode *right;
    };

    class HoffmanTree{
    private:
        HoffTreeNode *root;

        ///Methods:
        void makeEmpty(HoffTreeNode *leaf);
        void insert(float key, char _data, HoffTreeNode *leaf);
        HoffTreeNode *search(float key, HoffTreeNode *leaf);
        void inorder_print(HoffTreeNode *leaf);
        void postorder_print(HoffTreeNode *leaf);
        void preorder_print(HoffTreeNode *leaf);

    public:
        ///Constructors & Destructors:
        HoffmanTree();
        HoffmanTree(const HoffmanTree& toCopy);
        ~HoffmanTree();

        ///Getters:
        float getRootKey() { return root->frequency; }
        char getRootData() {return root->data;}
        HoffTreeNode* getRoot(){return root;}

        ///Methods:
        void insert(float key,char _data);
        HoffTreeNode *search(float key);
        void makeEmpty();
        bool isEmpty() const;
        void inorder_print();
        void postorder_print();
        void preorder_print();
        void addSons(HoffmanTree& leftSon, HoffmanTree& rightSon);
        void printHoffmanTree() const;
        void _hoffman(HoffTreeNode* root, string s, float& count)const;
        HoffTreeNode* copyHoffmanTree(const HoffTreeNode* toCopy);

        ///Override operators:
        HoffmanTree& operator=(const HoffmanTree& otherTree);

//        HoffTreeNode* huffman(HoffTreeNode c[], int n){
//            PriorityQueue q(c,n); // Initialize Q to contain forest of leaves
//            HoffTreeNode* node;
//
//            for(int i=1 ; i < n ; i++){
//                node = new HoffTreeNode();
//                node->left = q.deleteMin();
//                node->right = q.deleteMin();
//                node->frequency = node->left->frequency + node->right->frequency;
//                q.insert(node);
//            }
//            return q.deleteMin();
//        }


    };


}