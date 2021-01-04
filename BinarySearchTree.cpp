//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "BinarySearchTree.h"
namespace DataQ2 {
    BinSearchNode::BinSearchNode(): right(nullptr), left(nullptr) {
        data.frequency=-1;
        data.key=0;
    }
    BinSearchNode::BinSearchNode(BinSearchNode *_right, BinSearchNode *_left, Pair _data): right(_right), left(_left){
        data.frequency=_data.frequency;
        data.key=_data.key;
    }
    BinSearchNode::~BinSearchNode() {}

    BinarySearchTree::BinarySearchTree():root(nullptr),logSize(0){
    }

    BinarySearchTree::~BinarySearchTree(){
        makeEmpty(root);
    }

    void BinarySearchTree::makeEmpty(BinSearchNode *t) {
        if (t == nullptr)
            return;

        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        logSize=0;
    }

    BinSearchNode* BinarySearchTree::insert(char _key, BinSearchNode* t) {
//        if (t == nullptr) { TODO
//            t = new BinSearchNode(nullptr, nullptr, x);
//        } else if (x.key < t->data.key)
//            t->left = insert(x, t->left);
//        else if (x.key > t->data.key)
//            t->right = insert(x, t->right);
//        return t;


        //TreeNode* temp = root;TODO: Dor's comment
        BinSearchNode* parent = nullptr;
        BinSearchNode* newNode;

        BinSearchNode* temp = find(parent,_key);
        if (temp)
            (temp->data.key)++;
        else {
            temp = root;
            while (temp) {
                parent = temp;
                if (_key > temp->data.key)
                    temp = temp->right;
                else
                    temp = temp->left;
            }

            newNode = new BinSearchNode();
            newNode->data.key = _key;
            newNode->data.key = 1;

            if (!parent)
                root = newNode;
            else if (_key > parent->data.key)
                parent->right = newNode;
            else
                parent->left = newNode;

            logSize++;
        }
    }

    BinSearchNode* BinarySearchTree::findMin(BinSearchNode *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    BinSearchNode* BinarySearchTree::findMax(BinSearchNode *t) {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    BinSearchNode* BinarySearchTree::remove(Pair x, BinSearchNode *t) {
        BinSearchNode *temp;
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

    void BinarySearchTree::inorder(BinSearchNode *t) {
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data.key << " ";
        inorder(t->right);
    }

    BinSearchNode* BinarySearchTree::find(BinSearchNode *t, char x) {
        if (t == nullptr)
            return nullptr;
        else if (x < t->data.key)
            return find(t->left, x);
        else if (x > t->data.key)
            return find(t->right, x);
        else
            return t;
    }

    void BinarySearchTree::insert(char x) {
        root = insert(x, root);
        logSize++;
    }
    void BinarySearchTree::remove(Pair x) {
        root = remove(x, root);
        logSize--;
    }

    void BinarySearchTree::display(){
        inorder(root);
        cout << endl;
    }

    BinSearchNode* BinarySearchTree::find(char x) {
        return find(root, x);
    }
}