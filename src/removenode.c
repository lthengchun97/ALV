#include "removenode.h"
#include "addnode.h"
#include <stdlib.h>
#include "rotate.h"
#include <stdio.h>

//recursive remove node
Node *removeN(Node **rootPtr, int nodeToRemove)
 {
   int height;
   Node *removeN = removeN_Height(rootPtr, nodeToRemove, &height);
   return removeN;
  }

Node *removeN_Height(Node **rootPtr, int nodeToRemove,int *height)
   {
     // height change return 1 , no height change return 0
       if (*rootPtr == NULL)
         {
           return NULL;
         }
       else if ( nodeToRemove < (*rootPtr)->data ){
           removeN_Height(&(*rootPtr)->left, nodeToRemove,height);
           if(*height == 1)
             (*rootPtr)->balanceFactor += 1;
             if((*rootPtr)->balanceFactor != 0)
             *height = 0;
          }
       else if ( nodeToRemove > (*rootPtr)->data ){
            removeN_Height(&(*rootPtr)->right, nodeToRemove,height);
            if(*height == 1)
              (*rootPtr)->balanceFactor -= 1;
              if((*rootPtr)->balanceFactor != 0)
              *height = 0;
           }
       else
       {
           if( ( (*rootPtr)->left == NULL) || ( (*rootPtr)->right == NULL) )
           {
               Node *temp = (*rootPtr)->left ?  (*rootPtr)->left : (*rootPtr)->right;
               if (temp == NULL)
               {
                   temp = *rootPtr;
                   *rootPtr = NULL;
                   *height = 1;
               }
               else
               {
                *rootPtr  = temp;
                *height = 1;
              }
            }
            else
            {
              Node* Rgrandchild = (*rootPtr)->right;
              Node* nearestHighest = findnearest((*rootPtr)->right,height);


              if(Rgrandchild->right != NULL)
              {
              nearestHighest->balanceFactor = ((*rootPtr)->balanceFactor);
              }
              else
              {
              nearestHighest->balanceFactor = ((*rootPtr)->balanceFactor) - 1;
              }


              if(*height == 0)
                (*rootPtr)->balanceFactor -= 1;
              else
                (*rootPtr)->balanceFactor = (*rootPtr)->balanceFactor;



              if(nearestHighest->right != NULL)
              {
                nearestHighest->balanceFactor = ((*rootPtr)->balanceFactor);
                nearestHighest->left = (*rootPtr)->left;
                (*rootPtr) = nearestHighest;
              }
              else
              {
                //nearestHighest->balanceFactor = ((*rootPtr)->balanceFactor);
                nearestHighest->left = (*rootPtr)->left;
                nearestHighest->right= (*rootPtr)->right;
                (*rootPtr) = nearestHighest;
              }
              if((*rootPtr)->balanceFactor >= 2)
                  avlBalanceRightTree(&(*rootPtr));
              else if((*rootPtr)->balanceFactor <= -2)
                  avlBalanceLeftTree(&(*rootPtr));
              else{
                 *rootPtr = *rootPtr;
                }
            }
            return *rootPtr;
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

Node *findnearest(Node *rootPtr,int *height)
 {
    Node *temp;
    Node *current = rootPtr->left;
     if(current!=NULL){
       if(current->left != NULL)
          findnearest(rootPtr->left,height);
      else{
        if(rootPtr->right!=NULL)
        {
          if(current->right !=NULL){
            rootPtr->left = current->right;
            rootPtr->balanceFactor +=1;
            current->right = NULL;
            *height = 1;
            if((rootPtr)->balanceFactor >= 2)
                avlBalanceRightTree(&(rootPtr));
            else if((rootPtr)->balanceFactor <= -2)
                avlBalanceLeftTree(&(rootPtr));
            else{
               *rootPtr = *rootPtr;
              }
          }
          else{
            rootPtr->left = NULL;
            rootPtr->balanceFactor +=1;
            *height = 0;
            if((rootPtr)->balanceFactor >= 2)
                avlBalanceRightTree(&(rootPtr));
            else if((rootPtr)->balanceFactor <= -2)
                avlBalanceLeftTree(&(rootPtr));
            else{
               *rootPtr = *rootPtr;
              }
            }
        return current;
      }
      else{
        if(rootPtr->right!=NULL)
        {
          if(current->right !=NULL){
            rootPtr->left = current->right;
            rootPtr->balanceFactor +=1;
            current->right = NULL;
            *height = 1;
            if((rootPtr)->balanceFactor >= 2)
                avlBalanceRightTree(&(rootPtr));
            else if((rootPtr)->balanceFactor <= -2)
                avlBalanceLeftTree(&(rootPtr));
            else{
               *rootPtr = *rootPtr;
              }
          }
          else{
            rootPtr->left = NULL;
            rootPtr->balanceFactor +=1;
            *height = 1;
            if((rootPtr)->balanceFactor >= 2)
                avlBalanceRightTree(&(rootPtr));
            else if((rootPtr)->balanceFactor <= -2)
                avlBalanceLeftTree(&(rootPtr));
            else{
               *rootPtr = *rootPtr;
              }
            }
        return current;
      }
      }
      }
  }
  else
     *height = 0;
     return rootPtr;
 }
