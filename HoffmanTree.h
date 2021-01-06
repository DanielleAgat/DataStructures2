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
        //Inner method: frees all tree's memory and leaves the root as nullptr
        void make_empty(HoffTreeNode *leaf);

        //Inner method: inserts a node to the tree in the right place
        void insert(float key, char _data, HoffTreeNode *leaf);

        //Inner method: returns the HoffTreeNode* with the given key ; returns nullptr if the key is not exist in the tree
        HoffTreeNode* find(float key, HoffTreeNode *leaf);

        //Inner method: prints the Hoffman tree.
        float printHoffmanTree(HoffTreeNode* node, float weight, string s)const;

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
        //This method inserts a node to the tree in the right place
        void insert(float key,char _data);

        //This method returns 'true' if the tree is empty ; 'false' otherwise
        bool isEmpty();

        //This method returns the HoffTreeNode* with the given key ; returns nullptr if the key is not exist in the tree
        HoffTreeNode* find(float key);

        //This method frees all tree's memory and leaves the root as nullptr
        void make_empty();

        //This method gets 2 HoffmanTrees and merge them into one tree, with a new root which its key is the sum of both root's keys.
        void mergeTreesToHoffman(HoffmanTree& leftSubTree, HoffmanTree& rightSubTree);

        //This method prints the Hoffman tree.
        void printHoffmanTree() const;

        //This method returns a copy of a Hoffman tree.
        HoffTreeNode* copyHoffmanTree(const HoffTreeNode* toCopy);

        ///Print methods:
        void inorder();
        void postorder();
        void preorder();

        ///Override operators:
        HoffmanTree& operator=(const HoffmanTree& toCopy);
    };
}