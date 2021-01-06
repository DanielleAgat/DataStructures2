//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include <iostream>

using namespace std;

namespace DataQ2{
#define ENTER '\n'

    class HoffTreeNode{
        friend class HoffmanTree;
        private:
        char data;
        float frequency;
        HoffTreeNode *left;
        HoffTreeNode *right;

    public:
        ///Constructors & destructors:
        HoffTreeNode();
        HoffTreeNode(char _data, float _frequency);
        HoffTreeNode(const HoffTreeNode& toCopy);
        ~HoffTreeNode();

        ///Getters & setters:
        char getData() const { return data; };
        float getFrequency() const { return frequency; };
        bool setData(char _data);
        bool setFrequency(float _frequency);

        ///Overriding operators:
        HoffTreeNode& operator=(const HoffTreeNode& toCopy);
    };

    class HoffmanTree{
    private:
        HoffTreeNode *root;

        ///Inner Methods:
        void makeEmpty(HoffTreeNode *leaf);
        bool isEmpty();
        void insert(float key, char _data, HoffTreeNode *leaf);
        HoffTreeNode* find(float key, HoffTreeNode *leaf);

        //Print methods:
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
        void makeEmpty();
        bool isEmpty() const;
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