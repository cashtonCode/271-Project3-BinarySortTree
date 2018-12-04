// FILE: Bst.h
// H Bennett, Transy U
// CS 2444, Fall 2017
//
//	Implementation of Mp3 class
//

#ifndef    BST_H
#define    BST_H
#include "DataType.h"
#include <string>
using namespace std;

class Bst {
public:
// public member functions:

//Constructor
Bst (void);

//destructor call recursive function to kill Bst nodes
~Bst (void);

//Mutator
bool put (const ValueType& newItem);

//Accessors
bool get (const KeyType& searchKey,  ValueType& foundItem) const;

void printDEBUG (void) const;

private:
// private data type: Node

    struct Node {
         ValueType    data;
         Node        *left;
	 Node        *right;
    };

bool tup(Node*& root, ValueType newItem);

bool teg(const KeyType& searchKey, Node* root,  ValueType& foundItem) const;

void preorder(Node* root) const;

void kill(Node*& root);

void printNode (Node* root) const;

// state variables:

    Node *wholeTreeRoot;

};
#endif
