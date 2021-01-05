//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include <iostream>

using namespace std;

namespace DataQ2{
#define ENTER '\n'

    struct HoffTreeNode{
        char data;
        float frequency;
        HoffTreeNode *left;
        HoffTreeNode *right;
    };

    class HoffmanTree{
    private:
        HoffTreeNode *root;

        ///Methods:
        void make_empty(HoffTreeNode *leaf);
        void insert(float key, char _data, HoffTreeNode *leaf);
        HoffTreeNode* find(float key, HoffTreeNode *leaf);
        void inorder(HoffTreeNode *leaf);
        void postorder(HoffTreeNode *leaf);
        void preorder(HoffTreeNode *leaf);

    public:
        ///Constructors & Destructors:
        HoffmanTree();
        HoffmanTree(const HoffmanTree& toCopy);
        ~HoffmanTree();

        ///Getters:
        float getRootKey() { return root->frequency; }
        char getRootData() { return root->data; }
        HoffTreeNode* getRoot(){ return root; }

        ///Methods:
        void insert(float key,char _data);
        HoffTreeNode* find(float key);
        void make_empty();
        void mergeTreesToHoffman(HoffmanTree& leftSubTree, HoffmanTree& rightSubTree);
        void printHoffmanTree() const;
        float print(HoffTreeNode* node, float weight, string s)const;
        HoffTreeNode* copyHoffmanTree(const HoffTreeNode* toCopy);

        ///Print methods:
        void inorder();
        void postorder();
        void preorder();

        ///Override operators:
        HoffmanTree& operator=(const HoffmanTree& toCopy);
    };
}