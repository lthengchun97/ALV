#include "addnode.h"
#include <stdlib.h>
#include <stdio.h>


//add a new node
Node *addNode(Node **rootPtr, Node *nodeToAdd)
{

    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return *rootPtr;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->left = addNode(&(*rootPtr)->left,nodeToAdd);
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
        (*rootPtr)->right = addNode(&(*rootPtr)->right,nodeToAdd);
      }
      else
        return *rootPtr;
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
