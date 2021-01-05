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

    HoffTreeNode *HoffmanTree::find(float key, HoffTreeNode *leaf){
        if(leaf != nullptr){
            if(key == leaf->frequency){
                return leaf;
            }
            if(key < leaf->frequency){
                return find(key, leaf->left);
            }else{
                return find(key, leaf->right);
            }
        }else{
            return nullptr;
        }
    }

    HoffTreeNode *HoffmanTree::find(float key){
        return find(key, root);
    }

    void HoffmanTree::make_empty(){
        make_empty(root);
    }

    void HoffmanTree::inorder(){
        inorder(root);
        cout << "\n";
    }

    void HoffmanTree::inorder(HoffTreeNode *leaf){
        if(leaf != nullptr){
            inorder(leaf->left);
            cout << leaf->data << ",";
            inorder(leaf->right);
        }
    }

    void HoffmanTree::postorder(){
        postorder(root);
        cout << "\n";
    }

    void HoffmanTree::postorder(HoffTreeNode *leaf){
        if(leaf != nullptr){
            inorder(leaf->left);
            inorder(leaf->right);
            cout << leaf->data << ",";
        }
    }

    void HoffmanTree::preorder(){
        preorder(root);
        cout << "\n";
    }

    void HoffmanTree::preorder(HoffTreeNode* leaf){
        if(leaf != nullptr){
            cout << leaf->data << ",";
            inorder(leaf->left);
            inorder(leaf->right);
        }
    }

    void HoffmanTree::mergeTreesToHoffman(HoffmanTree& leftSubTree, HoffmanTree& rightSubTree) {
            float sum = leftSubTree.getRootKey() + rightSubTree.getRootKey();
            insert(sum, ' ');
            root->left = copyHoffmanTree(leftSubTree.getRoot());
            root->right = copyHoffmanTree(rightSubTree.getRoot());
    }

    void HoffmanTree::printHoffmanTree() const{
        float weight = 0;
        string s;
        if(root->left ==nullptr && root->right ==nullptr) //Only one node to tree, hence only one code
            s.append("1");

        cout << "Character encoding:" << endl;
        weight = print(root, weight, s);
        cout << "\nEncoded file weight: " << weight << " bits";
    }


    float HoffmanTree::print(HoffTreeNode* node, float weight, string s)const{
        if(node->left != nullptr){ //Hoffman tree is always full tree, hence if there is no one son, there is no sons at all.
            string s1,s2;
            s1.assign(s);
            s2.assign(s);
            float weight1 = print(node->left, weight,s1.append("0"));
            float weight2 = print(node->right, weight, s2.append("1"));
            weight = weight1 + weight2;
        }else{
            if(node->data == ENTER)
                cout << "\n'\\n' - " << s;
            else
                cout << "\n'" << node->data << "' - " << s;
            weight += ((s.length()) * node->frequency);
        }
        return weight;
    }

    HoffmanTree& HoffmanTree::operator=(const HoffmanTree& toCopy){
        if (this != &toCopy){
            if (root != nullptr)
                make_empty();
            if (toCopy.root == nullptr)
                root = nullptr;
            else
                root = copyHoffmanTree(toCopy.root);
//                HoffTreeNode* copyNode = new HoffTreeNode();
//                copyNode->data = toCopy.root->data;
//                copyNode->frequency = toCopy.root->frequency;
//                copyNode->left = copyHoffmanTree(toCopy.root->left);
//                copyNode->right = copyHoffmanTree(toCopy.root->right);
//                root = copyNode;

        }
        return *this;
    }


    HoffTreeNode* HoffmanTree::copyHoffmanTree(const HoffTreeNode* toCopy){
        if (toCopy == nullptr)
            return nullptr;
        HoffTreeNode* copyNode = new HoffTreeNode;
        copyNode->data = toCopy->data;
        copyNode->frequency = toCopy->frequency;
        copyNode->left = copyHoffmanTree(toCopy->left);
        copyNode->right = copyHoffmanTree(toCopy->right);
        return copyNode;
    }



}