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
    BinSearchNode::~BinSearchNode() = default;

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
        logSize = 0;
    }
    BinSearchNode* BinarySearchTree::insert(char _key) {
        BinSearchNode* tmp = find(_key);
        if (tmp) {
            tmp->data.frequency++;
        }
        else {
            tmp = root;
            BinSearchNode* newNode= new BinSearchNode();
            BinSearchNode* nodeParent = nullptr;
            newNode->data.frequency = 1;
            newNode->data.key = _key;
            while (tmp!= nullptr) {
                nodeParent = tmp;
                if (tmp->data.key >=_key)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            if (nodeParent== nullptr)
                root = newNode;
            else if (nodeParent->data.key>_key)
                nodeParent->left = newNode;
            else
                nodeParent->right = newNode;
        }
        return root;
    }

    BinSearchNode* BinarySearchTree::findMin(BinSearchNode *t) const{
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    BinSearchNode* BinarySearchTree::findMax(BinSearchNode *t) const{
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

    void BinarySearchTree::inorder(const BinSearchNode *t) const{
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data.key << " ";
        inorder(t->right);
    }

    BinSearchNode* BinarySearchTree::find(BinSearchNode *t, char x) const{
        if (t == nullptr)
            return nullptr;
        else if (x < t->data.key)
            return find(t->left, x);
        else if (x > t->data.key)
            return find(t->right, x);
        else
            return t;
    }

    void BinarySearchTree::insertV(char x) {
        root = insert(x);
        logSize++;
    }
    void BinarySearchTree::remove(Pair x) {
        root = remove(x, root);
        logSize--;
    }

    void BinarySearchTree::printBinarySearchTree()const{
        inorder(root);
        cout << endl;
    }

    BinSearchNode* BinarySearchTree::find(char x) const{
        return find(root, x);
    }

    void BinarySearchTree::makeEmpty() {
        makeEmpty(root);
    }

    bool BinarySearchTree::isEmpty() const {
        if(logSize==0)
            return true;
        return false;
    }

    Pair *BinSearchNode::makeDataArr(int phySize,int& logSize) const{
        Pair* arr=new Pair [phySize];
        makeDataArrHelper(arr,this,logSize);
        return arr;
    }

    void BinSearchNode::makeDataArrHelper(Pair* arr,const BinSearchNode *t,int& i) const{
        if (t == nullptr)
            return;
        makeDataArrHelper(arr,t->left,i);
        arr[i]=t->data;
        i++;
        makeDataArrHelper(arr,t->right,i);
    }
}