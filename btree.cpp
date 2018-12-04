/*
Author: Cashton
Date:   3/20/2018
Purpose:Store Strings into a Binary Sort Tree with 3 traversals
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>
#include "btree.h"
using namespace std;

template<class A>
void print(BSTNode<A>* nodeIn){cout << nodeIn -> myItem << endl;}
template<class A>
void inOrder(BSTNode<A>* nodeIn)
{
  if (nodeIn == NULL) return;

  inOrder(nodeIn -> leftChild);
  print(nodeIn);
  inOrder(nodeIn -> rightChild);
}
template<class A>
void preOrder(BSTNode<A>* nodeIn)
{
  if (nodeIn == NULL) return;

  print(nodeIn);
  preOrder(nodeIn -> leftChild);
  preOrder(nodeIn -> rightChild);
}
template<class A>
void postOrder(BSTNode<A>* nodeIn)
{
  if (nodeIn == NULL) return;

  postOrder(nodeIn -> leftChild);
  postOrder(nodeIn -> rightChild);
  print(nodeIn);
}


int main()
{
  int choice, exitCondition = 0;
  string pause, fileName, insertValue, readInItem, searchValue;
  ifstream readInFile;
  BinarySortTree<string> bst1;
  BinarySortTree<string>* bst1ptr;

  while(choice != 8){

    system("clear");//Clears the screen
    cout << " - - - - - - - - - - - - - - -"<< endl;
    cout << "1 - Insert from a File       -\n";
    cout << "2 - Insert from the Keyboard -\n";
    cout << "3 - Find                     -\n";
    cout << "4 - Remove                   -\n";
    cout << "5 - Print Inorder            -\n";
    cout << "6 - Print Preorder           -\n";
    cout << "7 - Print Postorder          -\n";
    cout << "8 - EXIT                     -\n";
    cout << " - - - - - - - - - - - - - - -"<< endl;

    cin >> choice;
    cout << endl;

    system("clear");//Clears the screen

    switch (choice) {
      case 1://Insert from a file
        cout << "Insert from a File" << endl;
        cout << "Enter the name of the file: ";

        cin.ignore();
        getline(cin, fileName);
        readInFile.open(fileName.c_str());
        if(!readInFile.is_open())
        {
          cout << "file not found" << endl;
          cout << "\n\nPress any key to continue...";
          cin >> pause;
          break;
        }

        while(readInFile >> readInItem) bst1.insert(readInItem);

        readInFile.close();

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 2://Insert from the keyboard
        cout << "Insert from the Keyboard" << endl;
        cout << "Please enter a value: ";
        cin.ignore();
        getline(cin, insertValue);

        bst1.insert(insertValue);

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 3://Find
        cout << "Find" << endl;
        cin.ignore();
        getline(cin, searchValue);

        try{bst1.find(searchValue);}
        catch(int e)
        {
          cout << "Item not Found" << endl;
          cout << "\n\nPress any key to continue...";
          cin >> pause;
          break;
        }
        cout << "Found: " << bst1.find(searchValue) << endl;

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 4://Delete
        cout << "Remove" << endl;
        cin.ignore();
        getline(cin, searchValue);

        bst1.removeValue(searchValue);

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 5://Print INorder
        cout << "Print Inorder" << endl;

        inOrder(bst1.root);

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 6://Print PREorder
        cout << "Print Preorder" << endl;

        preOrder(bst1.root);

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 7://Print POSTorder
        cout << "Print Postorder" << endl;

        postOrder(bst1.root);

        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;

      case 8://Exit
        break;

      default://(Choice < 1 && Choice > 8)
        cout << "That is not a valid choice. Please try again." << endl;
        cout << "\n\nPress any key to continue...";
        cin >> pause;
        break;
    }
  }
  system("clear");//Clears the screen
}
