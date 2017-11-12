#include "addnode.h"
#include <stdlib.h>
#include <stdio.h>
#include "rotate.h"


// add node with considering the height
int addNodeWithHeight(Node **rootPtr, Node *nodeToAdd){
  int height;
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return height=1;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
      height = addNodeWithHeight(&(*rootPtr)->left,nodeToAdd);
        if(height==1){
        (*rootPtr)->balanceFactor -= 1;
          if((*rootPtr)->balanceFactor==0)
          height=0;
        }
      else
      (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;

      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
      height = addNodeWithHeight(&(*rootPtr)->right,nodeToAdd);
        if(height==1){
        (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor==0)
            height=0;;
          }
        else
          (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;
      }
    }
    if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTree(&(*rootPtr));
    else{
       *rootPtr = *rootPtr;
      }
        return height;
 }

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
        (*rootPtr)->balanceFactor -= 1;
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
        (*rootPtr)->right = addNode(&(*rootPtr)->right,nodeToAdd);
        (*rootPtr)->balanceFactor += 1;
      }
      }

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
