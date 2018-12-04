// FILE: Bst.cpp
// H Bennett, Transy U
// CS 2444, Fall 2017
//
//	Implementation of Mp3 class
//

#include "Bst.h"
#include <iostream>
using namespace std;

//Constructor
Bst::Bst (void){
	wholeTreeRoot = 0;

#ifdef DEBUG
	cout << "CONSTRUCTOR!" << endl;
#endif
}

//destructor call recursive function to kill Bst nodes, use post order
Bst::~Bst (void){

	kill (wholeTreeRoot);

}

//Mutator
//kills entire family then kills itself!! :)

void Bst::kill (Node*& root){
		if(!(root -> left == 0)){
			return kill(root -> left);
		}
		if(!(root -> right == 0)){
			return kill(root -> right);
			delete root;
		}
}

//put fn puts new node in the tree with two external nodes
bool Bst::put (const ValueType& newItem){
	tup(wholeTreeRoot, newItem);
}

bool Bst::tup (Node*& root, ValueType newItem){


//Base case
		if(root == 0){
			root = new Node;
			root -> data = newItem;
			root -> right = 0;
			root -> left = 0;
			return true;
		}

		if(newItem == root -> data){
			return false;
		}
//recursive case
		if(newItem < root -> data){
			tup(root -> left, newItem);
		}
		else{
			tup(root -> right, newItem);
		}

}

//Accessors

bool Bst::get (const KeyType& searchKey,  ValueType& foundItem) const{
	 return teg(searchKey, wholeTreeRoot, foundItem);


}

bool Bst::teg (const KeyType& searchKey, Node* root,  ValueType& foundItem) const{
//Base Case
	if(root == 0){return false;}
	if(searchKey == root -> data)
	{
		foundItem = root -> data;
		return true;
	}
//recursive case
	if(searchKey < root -> data){return teg (searchKey, root -> left, foundItem);}
	else{return teg (searchKey, root -> right, foundItem);}

}

void Bst::printNode (Node* root) const{
#define DB
//print node
//commment out #define DB for less verbose output
#ifndef DB
	cout << root -> data << ' ';
#else
	cout<< endl << "data: " << root -> data;
	cout<< endl << "\tleft: ";

	if(root -> left)cout << root -> left -> data;
	else cout << "[EXTERNAL]";

	cout << endl << "\tright: ";
	if(root -> right)cout << root -> right -> data;
	else cout << "[EXTERNAL]";

	cout << endl;
#endif
}

void Bst::preorder(Node* root) const{
	if(root == 0){return;}
	printNode(root);
	preorder(root ->left);
	preorder(root -> right);
}



void Bst::printDEBUG (void) const{
	preorder(wholeTreeRoot);
cout << "hi from the DEBUG function " << endl;
}
