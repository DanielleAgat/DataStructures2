//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "BinaryTree.h"

namespace DataQ2{


    btree::btree(){
        root = nullptr;
    }

    btree::btree(const btree& toCopy){
        root = copyHelper(toCopy.root);
    }

    btree::~btree(){
        make_empty();
    }

    void btree::make_empty(binTreeNode *leaf){
        if(leaf != nullptr){
            make_empty(leaf->left);
            make_empty(leaf->right);
            delete leaf;
        }
    }

    void btree::insert(float key,char _data, binTreeNode *leaf){
        if(key < leaf->frequency){
            if(leaf->left != nullptr){
                insert(key,_data, leaf->left);
            }else{
                leaf->left = new binTreeNode;
                leaf->left->frequency = key;
                leaf->left->data = _data;
                leaf->left->left = nullptr;
                leaf->left->right = nullptr;
            }
        }else if(key >= leaf->frequency){
            if(leaf->right != nullptr){
                insert(key,_data, leaf->right);
            }else{
                leaf->right = new binTreeNode;
                leaf->right->frequency = key;
                leaf->right->data = _data;
                leaf->right->right = nullptr;
                leaf->right->left = nullptr;
            }
        }

    }

    void btree::insert(float key,char _data){
        if(root != nullptr){
            insert(key,_data, root);
        }else{
            root = new binTreeNode;
            root->data = _data;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    binTreeNode *btree::search(float key, binTreeNode *leaf){
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

    binTreeNode *btree::search(float key){
        return search(key, root);
    }

    void btree::make_empty(){
        make_empty(root);
    }

    void btree::inorder_print(){
        inorder_print(root);
        cout << "\n";
    }

    void btree::inorder_print(binTreeNode *leaf){
        if(leaf != nullptr){
            inorder_print(leaf->left);
            cout << leaf->data << ",";
            inorder_print(leaf->right);
        }
    }

    void btree::postorder_print(){
        postorder_print(root);
        cout << "\n";
    }

    void btree::postorder_print(binTreeNode *leaf){
        if(leaf != nullptr){
            inorder_print(leaf->left);
            inorder_print(leaf->right);
            cout << leaf->data << ",";
        }
    }

    void btree::preorder_print(){
        preorder_print(root);
        cout << "\n";
    }

    void btree::preorder_print(binTreeNode* leaf){
        if(leaf != nullptr){
            cout << leaf->data << ",";
            inorder_print(leaf->left);
            inorder_print(leaf->right);
        }
    }

    void btree::addSons(btree& leftSon, btree& rightSon) {
            float sum = leftSon.getRootKey() + rightSon.getRootKey();
            insert(sum, ' ');
            root->left = copyHelper(leftSon.getRoot());
            root->right = copyHelper(rightSon.getRoot());
    }

    void btree::printHoffmanTree() const{
        float count = 0;
        string s;
        if(root->left ==nullptr && root->right ==nullptr)
            s.append("1");

        _hoffman(root, s, count);
        cout<<endl<<"the weight of the tree is: "<<count;
    }


    void btree::_hoffman(binTreeNode* root, string s, float& count)const{
        if(root->right == nullptr && root->left == nullptr){
            cout<<endl;
            cout<<"'"<<root->data<<"':"<< s;
            count = count+ ((s.length())*root->frequency);
        }else{
            //count +=2;
            string s1,s2;
            s1.assign(s);
            s2.assign(s);
            _hoffman(root->right, s2.append("1"), count);
            _hoffman(root->left, s1.append("0"), count);
        }
    }

    btree& btree::operator=(const btree& otherTree){
        if (this != &otherTree){
            if (root != nullptr)
                make_empty();
            if (otherTree.root == nullptr)
                root = nullptr;
            else
                root = copyHelper(otherTree.root);
        }
        return *this;
    }


    binTreeNode* btree::copyHelper(const binTreeNode* toCopy){
        if (toCopy == nullptr)
            return nullptr;
        binTreeNode* copyNode = new binTreeNode;
        copyNode->frequency = toCopy->frequency;
        copyNode->data = toCopy->data;
        copyNode->left = copyHelper(toCopy->left);
        copyNode->right = copyHelper(toCopy->right);
        return copyNode;
    }


}