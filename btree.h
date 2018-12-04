/*
Author: Cashton
Date:   3/20/2018
Purpose:Node Class for Binary Sort Tree specifically
*/

template<class A>
class BSTNode
{
private:

public:
  A myItem;
  BSTNode<A>* leftChild;
  BSTNode<A>* rightChild;

  BSTNode(){
    rightChild = NULL;
    leftChild = NULL;
  };
  ~BSTNode(){
      free(leftChild);
      free(rightChild);
  };
};

#include <string>
using namespace std;

template<class A>
class BinarySortTree
{
public:
  int count;
  BSTNode<A>* root;//Node at the top of a BST

  BinarySortTree(){root = NULL;count = 0;};
  ~BinarySortTree(){free(root);};

  bool isEmpty();
  void insert(A item);
  A find(A key);

  //Remove functions
  BSTNode<A>* replacementValue(BSTNode<A>* cursor);
  void removeValue(A key);
  BSTNode<A>* removeRecurse(A key, BSTNode<A>* cursor);

  const static int itemNotFound = 0004;
};

//Checks if the BST is empty
template<class A>
bool BinarySortTree<A>::isEmpty(){
  if (root == NULL) return true;
  else return false;
}
/*******************************************************************************
                  **insert FUNCTION **
*Input: an element from the keyboard (int, flout, double, char, string)
*Output: none
*Description: takes the A element from the user and places it into the BST
*******************************************************************************/
template<class A>
void BinarySortTree<A>::insert(A value) {
  BSTNode<A>* newNode = new BSTNode<A>;
  newNode -> myItem = value;
  newNode -> leftChild = NULL;
  newNode -> rightChild = NULL;

  if (count == 0)
  {
    root = newNode;
    count++;
  }
  else
  {
    BSTNode<A>* cursor, *parent;
    cursor = root;

    //Moving curosor to correct node
    while(cursor)
    {
      if (value < cursor -> myItem)
      {
        parent = cursor;
        cursor = cursor -> leftChild;
      }
      else
      {
        parent = cursor;
        cursor = cursor ->rightChild;
      }
    }

    cursor = newNode;
    if (value < parent -> myItem) parent -> leftChild = cursor;
    else parent -> rightChild = cursor;
    count++;
  }
}

//Finds the node value that matches the key value or returns an error
template<class A>
A BinarySortTree<A>::find(A key){
  BSTNode<A>* cursor = root;
  while(cursor)
  {
    if(key == cursor -> myItem) return cursor -> myItem;
    else if(key < cursor -> myItem) cursor = cursor -> leftChild;
    else cursor = cursor -> rightChild;
  }
  throw itemNotFound;
}

//Finds the smallest value in the right subtree of a given BST
template<class A>
BSTNode<A>* BinarySortTree<A>::replacementValue(BSTNode<A>* cursor)
{
  BSTNode<A>* leftmost = cursor;
  //Loop down to find the leftmost leaf
  while(leftmost -> leftChild != NULL) leftmost = leftmost -> leftChild;
  //return the leftmost leaf
  return leftmost;
}

//Calls the recursive remove function and decrements count
template<class A>
void BinarySortTree<A>::removeValue(A key){
  removeRecurse(key, root);
  count--;
}

//Finds value to delete by
//determining the type of deletion needed, then it
//deletes the node
template<class A>
BSTNode<A>* BinarySortTree<A>::removeRecurse(A key, BSTNode<A>* cursor){
  //if key is not found at any point in the BST
  if(cursor == NULL) return cursor;
  //if key is smaller than cursor, search in left subtree
  if(key < cursor -> myItem) cursor -> leftChild = removeRecurse(key, cursor -> leftChild);
  //if key is larger than cursor, search in right subtree
  else if(key > cursor -> myItem) cursor -> rightChild = removeRecurse(key, cursor -> rightChild);
  //key == cursor
  //delete cursor
  else
  {
    //node with 1 or no children
    if(cursor -> leftChild == NULL)
    {
      BSTNode<A>* temp = cursor -> rightChild;
      free(cursor);
      return temp;
    }
    else if(cursor -> rightChild == NULL)
    {
      BSTNode<A>* temp = cursor -> leftChild;
      free(cursor);
      return temp;
    }
    //node with 2 children: Get smallest in right subtree to maintain BST rules
    BSTNode<A>* temp = replacementValue(cursor -> rightChild);//Returns smallest in right subtree
    cursor -> myItem = temp -> myItem;//copies value from rightmost subtree into cursor
    cursor -> rightChild = removeRecurse(temp -> myItem, cursor -> rightChild);//deletes item in rightmost subtree
  }
  return cursor;
}
