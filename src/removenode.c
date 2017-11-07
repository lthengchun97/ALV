#include "removenode.h"
#include "addnode.h"
#include <stdlib.h>
#include "rotate.h"
#include <stdio.h>

// remove a node
Node *removeNode(Node **rootPtr, Node *nodeToRemove){
  if (*rootPtr == nodeToRemove){
      *rootPtr = NULL;
      return *rootPtr;
    }
  if(nodeToRemove-> data >(*rootPtr)->data)
  {
    (*rootPtr)->right = removeNode(&(*rootPtr)->right,nodeToRemove);
    (*rootPtr)->balanceFactor -= 1;
  }
  else if(nodeToRemove-> data <(*rootPtr)->data)
  {
    (*rootPtr)->left = removeNode(&(*rootPtr)->left,nodeToRemove);
    (*rootPtr)->balanceFactor += 1;
  }
  else
    return *rootPtr;
    if((*rootPtr)->balanceFactor >= 2)
      avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
      avlBalanceLeftTree(&(*rootPtr));
    else{
      *rootPtr = *rootPtr;
    }
   return *rootPtr;
}

int avlBalanceRightTree(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandchild = node->right->left;
  if((bf = child->balanceFactor)==-1)
  {
    if((bf = grandchild->balanceFactor)==0)
    {
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
    }
    else if((bf = grandchild->balanceFactor)==1)
    {
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
    }
    else if((bf = grandchild->balanceFactor)==-1)
    {
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandchild->balanceFactor = 0;
    }
   *rootPtr = rotateRightLeft(*rootPtr);
   return 0;
   }

  if((bf = child->balanceFactor)==0)
  {
    node->balanceFactor = 1;
    child->balanceFactor = -1;
  }
  else if((bf = child->balanceFactor)==1)
  {
    node->balanceFactor = 0;
    child->balanceFactor = 0;
  }
  *rootPtr = rotateLeft(*rootPtr);

  return 0;
 }


int avlBalanceLeftTree(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandchild = node->left->right;
  if((bf = child->balanceFactor)==1)
  {
    if((bf = grandchild->balanceFactor)==0)
    {
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
    }
    else if((bf = grandchild->balanceFactor)==1)
    {
      node->balanceFactor = 0;
      child->balanceFactor = -1;
      grandchild->balanceFactor = 0;
    }
    else if((bf = grandchild->balanceFactor)==-1)
    {
      node->balanceFactor = 1;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
    }
   *rootPtr = rotateLeftRight(*rootPtr);
   return 0;
  }
  else if((bf = child->balanceFactor)==0)
  {
    node->balanceFactor = -1;
    child->balanceFactor = 1;
  }
  else if((bf = child->balanceFactor)==-1)
  {
    node->balanceFactor = 0;
    child->balanceFactor = 0;
  }
  *rootPtr = rotateRight(*rootPtr);
  return 0;
}
