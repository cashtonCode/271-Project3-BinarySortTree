#include<iostream>
#include "btree.h"
using namespace std;

template<class A>
void print(BSTNode<A>* nodeIn){cout << nodeIn -> myItem << endl;}

template<class A>
void inOrder(BSTNode<A>* nodeIn){
  if (nodeIn == NULL) return;


  inOrder(nodeIn -> leftChild);
  print(nodeIn);
  inOrder(nodeIn -> rightChild);
}
template<class A>
void preOrder(BSTNode<A>* nodeIn){
  if (nodeIn == NULL) return;

  print(nodeIn);
  preOrder(nodeIn -> leftChild);
  preOrder(nodeIn -> rightChild);
}
template<class A>
void postOrder(BSTNode<A>* nodeIn){
  if (nodeIn == NULL) return;

  postOrder(nodeIn -> leftChild);
  postOrder(nodeIn -> rightChild);
  print(nodeIn);
}


int main()
{
  BinarySortTree<string> tree1;

  tree1.insert("banana1");
  tree1.insert("apple2");
  tree1.insert("clam3");

  BSTNode<string>* treeRoot = tree1.root;

  cout << "This is root: " << tree1.root -> myItem << endl
    << "This is left of root: " << tree1.root -> leftChild -> myItem << endl
      << "This is right of root: " << tree1.root -> rightChild -> myItem << endl;
}
