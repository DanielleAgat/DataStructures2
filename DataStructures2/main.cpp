//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429

#include "BinarySearchTree.h"
#include "BinaryTree.h"

using namespace DataQ2;
int main(){
    BinarySearchTree t;
    Pair x1;
    x1.key='a';
    x1.frequency=20;

    Pair x2;
    x2.key='b';
    x2.frequency=25;

    Pair x3;
    x3.key='c';
    x3.frequency=40;

    Pair x4;
    x4.key='d';
    x4.frequency=30;

    Pair x5;
    x5.key='e';
    x5.frequency=35;

    t.insert(x1);
    t.insert(x2);
    t.insert(x3);
    t.insert(x4);
    t.insert(x5);
    t.display();
    t.remove(x1);
    t.display();
    t.remove(x2);
    t.display();
    t.remove(x3);
    t.display();



    //btree tree;
    btree *tree = new btree();

    tree->insert('e');
    tree->insert('b');
    tree->insert('A');
    tree->insert('c');
    tree->insert('a');
    tree->insert('T');
    tree->insert('Z');
    tree->insert('f');
    tree->insert('0');
    tree->insert('W');

    tree->preorder_print();
    tree->inorder_print();
    tree->postorder_print();

    delete tree;


    return 0;
}