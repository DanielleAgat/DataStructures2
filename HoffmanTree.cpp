//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "HoffmanTree.h"

namespace DataQ2{
    HoffTreeNode::HoffTreeNode() :data(0),frequency(0),left(nullptr),right(nullptr){
    }

    HoffTreeNode::HoffTreeNode(char _data, float _frequency) :data(_data),frequency(_frequency),left(nullptr),right(nullptr){
    }

    HoffTreeNode::HoffTreeNode(const HoffTreeNode& toCopy)
        :data(toCopy.data), frequency(toCopy.frequency),left(nullptr),right(nullptr){
      *this = toCopy;
    }

    HoffTreeNode::~HoffTreeNode() = default;

    bool HoffTreeNode::setData(char _data) {
        data = _data;
        return true;
    }

    bool HoffTreeNode::setFrequency(float _frequency) {
        frequency = _frequency;
        return true;
    }

    HoffTreeNode& HoffTreeNode::operator=(const HoffTreeNode& toCopy){
        if (this != &toCopy){
            HoffTreeNode copyNode;
            data = toCopy.data;
            frequency = toCopy.frequency;
            if(toCopy.left != nullptr) { //Hoffman is always full, hence, it is enough to check only for left son.
                left = new HoffTreeNode(*toCopy.left);
                right = new HoffTreeNode(*toCopy.right);
            }
            else{
                left = nullptr;
                right = nullptr;
            }
        }
        return *this;
    }

    HoffmanTree::HoffmanTree(){
        root = nullptr;
    }

    HoffmanTree::HoffmanTree(const HoffmanTree& toCopy) :HoffmanTree(){
        *this = toCopy;
    }

    HoffmanTree::~HoffmanTree(){
        makeEmpty();
    }

    void HoffmanTree::makeEmpty(HoffTreeNode *leaf){
        if(leaf != nullptr){
            makeEmpty(leaf->left);
            makeEmpty(leaf->right);
            delete leaf;
        }
    }

    void HoffmanTree::insert(float key, char _data, HoffTreeNode *leaf){
        if(key < leaf->frequency){
            if(leaf->left != nullptr)
                insert(key,_data, leaf->left);
            else
                leaf->left = new HoffTreeNode(_data,key);

        }else if(key >= leaf->frequency){
            if(leaf->right != nullptr)
                insert(key,_data, leaf->right);
            else
                leaf->right = new HoffTreeNode(_data,key);
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

    HoffTreeNode *HoffmanTree::find(float key, HoffTreeNode *leaf)const{
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

    void HoffmanTree::makeEmpty(){
        makeEmpty(root);
    }

    void HoffmanTree::inorder()const{
        inorder(root);
        cout << "\n";
    }

    void HoffmanTree::inorder(HoffTreeNode *leaf)const{
        if(leaf != nullptr){
            inorder(leaf->left);
            cout << leaf->data << ",";
            inorder(leaf->right);
        }
    }

    void HoffmanTree::postorder()const{
        postorder(root);
        cout << "\n";
    }

    void HoffmanTree::postorder(HoffTreeNode *leaf)const{
        if(leaf != nullptr){
            inorder(leaf->left);
            inorder(leaf->right);
            cout << leaf->data << ",";
        }
    }

    void HoffmanTree::preorder()const{
        preorder(root);
        cout << "\n";
    }

    void HoffmanTree::preorder(HoffTreeNode* leaf)const{
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

    float HoffmanTree::printHoffmanTree(ostream& os,HoffTreeNode* node, float weight, string s)const{
        if(node->left != nullptr){ //Hoffman tree is always full tree, hence if there is no one son, there is no sons at all.
            string s1,s2;
            s1.assign(s);
            s2.assign(s);
            float weight1 = printHoffmanTree(os,node->left, weight,s1.append("0"));
            float weight2 = printHoffmanTree(os,node->right, weight, s2.append("1"));
            weight = weight1 + weight2;
        }else{
            if(node->data == ENTER)
                os << "\n'\\n' - " << s;
            else
                os << "\n'" << node->data << "' - " << s;
            weight += ((s.length()) * node->frequency);
        }
        return weight;
    }

    HoffmanTree& HoffmanTree::operator=(const HoffmanTree& toCopy){
        if (this != &toCopy){
            if (root != nullptr)
                makeEmpty();
            if (toCopy.root == nullptr)
                root = nullptr;
            else{
                HoffTreeNode* copyNode = new HoffTreeNode();
                copyNode->data = toCopy.root->data;
                copyNode->frequency = toCopy.root->frequency;
                copyNode->left = copyHoffmanTree(toCopy.root->left);
                copyNode->right = copyHoffmanTree(toCopy.root->right);
                root = copyNode;
            }
        }
        return *this;
    }


    HoffTreeNode* HoffmanTree::copyHoffmanTree(const HoffTreeNode* toCopy) const{
        if (toCopy == nullptr)
            return nullptr;
        HoffTreeNode* copyNode = new HoffTreeNode(toCopy->data,toCopy->frequency);
        copyNode->left = copyHoffmanTree(toCopy->left);
        copyNode->right = copyHoffmanTree(toCopy->right);
        return copyNode;
    }

    bool HoffmanTree::isEmpty() const {
        if(root== nullptr)
            return true;
        return false;
    }
    ostream& operator<<(ostream& os, const HoffmanTree& hfTree){
        float weight = 0;
        string s;
        if(hfTree.root->left ==nullptr && hfTree.root->right ==nullptr) //Only one node to tree, hence only one code
            s.append("1");
        os << "Character encoding:" << endl;
        weight = hfTree.printHoffmanTree(os,hfTree.root, weight, s);
        os << "\nEncoded file weight: " << weight << " bits";
        return os;
    }


}