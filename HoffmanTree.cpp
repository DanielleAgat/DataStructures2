//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "HoffmanTree.h"

namespace DataQ2{


    HoffmanTree::HoffmanTree(){
        root = nullptr;
    }

    HoffmanTree::HoffmanTree(const HoffmanTree& toCopy) :HoffmanTree(){
        *this = toCopy;
    }

    HoffmanTree::~HoffmanTree(){
        make_empty();
    }

    void HoffmanTree::make_empty(HoffTreeNode *leaf){
        if(leaf != nullptr){
            make_empty(leaf->left);
            make_empty(leaf->right);
            delete leaf;
        }
    }

    void HoffmanTree::insert(float key, char _data, HoffTreeNode *leaf){
        if(key < leaf->frequency){
            if(leaf->left != nullptr){
                insert(key,_data, leaf->left);
            }else{
                leaf->left = new HoffTreeNode;
                leaf->left->frequency = key;
                leaf->left->data = _data;
                leaf->left->left = nullptr;
                leaf->left->right = nullptr;
            }
        }else if(key >= leaf->frequency){
            if(leaf->right != nullptr){
                insert(key,_data, leaf->right);
            }else{
                leaf->right = new HoffTreeNode;
                leaf->right->frequency = key;
                leaf->right->data = _data;
                leaf->right->right = nullptr;
                leaf->right->left = nullptr;
            }
        }

    }

    void HoffmanTree::insert(float key, char _data){
        if(root != nullptr){
            insert(key,_data,root);
        }else{
            root = new HoffTreeNode;
            root->data = _data;
            root->frequency = key;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    HoffTreeNode *HoffmanTree::search(float key, HoffTreeNode *leaf){
        if(leaf != nullptr){
            if(key == leaf->frequency){
                return leaf;
            }
            if(key < leaf->frequency){
                return search(key, leaf->left);
            }else{
                return search(key, leaf->right);
            }
        }else{
            return nullptr;
        }
    }

    HoffTreeNode *HoffmanTree::search(float key){
        return search(key, root);
    }

    void HoffmanTree::make_empty(){
        make_empty(root);
    }

    void HoffmanTree::inorder_print(){
        inorder_print(root);
        cout << "\n";
    }

    void HoffmanTree::inorder_print(HoffTreeNode *leaf){
        if(leaf != nullptr){
            inorder_print(leaf->left);
            cout << leaf->data << ",";
            inorder_print(leaf->right);
        }
    }

    void HoffmanTree::postorder_print(){
        postorder_print(root);
        cout << "\n";
    }

    void HoffmanTree::postorder_print(HoffTreeNode *leaf){
        if(leaf != nullptr){
            inorder_print(leaf->left);
            inorder_print(leaf->right);
            cout << leaf->data << ",";
        }
    }

    void HoffmanTree::preorder_print(){
        preorder_print(root);
        cout << "\n";
    }

    void HoffmanTree::preorder_print(HoffTreeNode* leaf){
        if(leaf != nullptr){
            cout << leaf->data << ",";
            inorder_print(leaf->left);
            inorder_print(leaf->right);
        }
    }

    void HoffmanTree::addSons(HoffmanTree& leftSon, HoffmanTree& rightSon) {
            float sum = leftSon.getRootKey() + rightSon.getRootKey();
            insert(sum, ' ');
            root->left = copyHoffmanTree(leftSon.getRoot());
            root->right = copyHoffmanTree(rightSon.getRoot());
    }

    void HoffmanTree::printHoffmanTree() const{
        float count = 0;
        string s;
        if(root->left ==nullptr && root->right ==nullptr) //Only one node to tree, hence only one code
            s.append("1");

        _hoffman(root, s, count);
        cout<<"\nthe weight of the tree is: "<<count;
    }


    void HoffmanTree::_hoffman(HoffTreeNode* root, string s, float& count)const{
        if(root->right != nullptr && root->left != nullptr){
            string s1,s2;
            s1.assign(s);
            s2.assign(s);
            _hoffman(root->left, s1.append("0"), count);
            _hoffman(root->right, s2.append("1"), count);
        }else{
            cout<<"\n'"<<root->data<<"':"<< s;
            count += ((s.length())*root->frequency);
        }
    }

    HoffmanTree& HoffmanTree::operator=(const HoffmanTree& otherTree){
        if (this != &otherTree){
            if (root != nullptr)
                make_empty();
            if (otherTree.root == nullptr)
                root = nullptr;
            else
                root = copyHoffmanTree(otherTree.root);
        }
        return *this;
    }


    HoffTreeNode* HoffmanTree::copyHoffmanTree(const HoffTreeNode* toCopy){
        if (toCopy == nullptr)
            return nullptr;
        HoffTreeNode* copyNode = new HoffTreeNode;
        copyNode->frequency = toCopy->frequency;
        copyNode->data = toCopy->data;
        copyNode->left = copyHoffmanTree(toCopy->left);
        copyNode->right = copyHoffmanTree(toCopy->right);
        return copyNode;
    }



}