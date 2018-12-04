template <class A>
class BSTNode
{
private:

public:
  A myItem;
  BSTNode<A>* leftChild;
  BSTNode<A>* rightChild;

  BSTNode();                        //constructor
  BSTNode(A);
  BSTNode(A, BSTNode<A>*, BSTNode<A>*);  //parameter constructor

  /*A getItem();                      //getter for Item
  BSTNode<A>* getrightChild();      //getter for pointer
  BSTNode<A>* getleftChild();       //getter for pointer
  void setItem(A);                  //setter for Item
  void setrightChild(BSTNode<A>*);  //setter for pointer
  void setleftChild(BSTNode<A>*);   //setter for pointer
  */
};
  /***************************************************************************
                    **CONSTRUCTOR**
  *Input: Noneint i = 0;
  *Output: None
  *Description: sets the pointer to NULL
  ***************************************************************************/
  template<class A>
  BSTNode<A>::BSTNode(){
    rightChild = NULL;
    leftChild = NULL;
  }
  /***************************************************************************
                    **PARAMETER CONSTRUCTOR **
  *Input: an item
  *Output: None
  *Description: sets the myItem = input
  ***************************************************************************/
  template<class A>
  BSTNode<A>::BSTNode(A data){
    myItem = data;
    rightChild = NULL;
    leftChild = NULL;
  }
  /***************************************************************************
                    **PARAMETER CONSTRUCTOR **
  *Input: None
  *Output: None
  *Description: sets the 2 objects(pointer and object of type A) within the
  class equal to the parameters of the function
  template<class A>
  ***************************************************************************/
  template<class A>
  BSTNode<A>::BSTNode(A newItem, BSTNode<A>* leftChildBSTNode, BSTNode<A>* rightChildBSTNode){
    rightChild = rightChildBSTNode;
    leftChild = leftChildBSTNode;
    myItem = newItem;
  }
  /***************************************************************************
                    **GETItem FUNCTION **
  *Input: None
  *Output: object of type A
  *Description: returns myItem object from within class
  ***************************************************************************/
/*  template<class A>
  A BSTNode<A>::getItem(){return myItem;}
  /***************************************************************************
                    **GETrightChild FUNCTION **
  *Input: None
  *Output: pointer of templated BSTNode class
  *Description: returns the pointer rightChild
  ***************************************************************************/
/*template<class A>
  BSTNode<A>* BSTNode<A>::getrightChild(){return rightChild;}
  /***************************************************************************
                    **GETleftChild FUNCTION **
  *Input: None
  *Output: pointer of templated BSTNode class
  *Description: returns the pointer leftChild
  ***************************************************************************/
/*template<class A>
  BSTNode<A>* BSTNode<A>::getleftChild(){return leftChild;}
  /***************************************************************************
                    **SETItem FUNCTION **
  *Input: object of type A
  *Output: None
  *Description: sets MyItem equal to the parameter within the function
  ***************************************************************************/
/*template<class A>
  void BSTNode<A>::setItem(A newItem){myItem = newItem;}
  /***************************************************************************
                    **SETrightChild FUNCTION **
  *Input: Pointer of templated class BSTNode
  *Output: None
  *Description: sets the pointer rightChild equal to the parameter within the function
  ***************************************************************************/
/*template<class A>
  void BSTNode<A>::setrightChild(BSTNode<A>* arg_rightChild){rightChild = arg_rightChild;}
  /***************************************************************************
                    **SETleftChild FUNCTION **
  *Input: Pointer of templated class BSTNode
  *Output: None
  *Description: sets the pointer leftChild is equal to the parameter within the function
  ***************************************************************************/
/*template<class A>
  void BSTNode<A>::setleftChild(BSTNode<A>* arg_leftChild){leftChild = arg_leftChild;}
/******************************************************************************/
