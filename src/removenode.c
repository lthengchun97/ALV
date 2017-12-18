#include "removenode.h"
#include "addnode.h"
#include <stdlib.h>
#include "rotate.h"
#include <stdio.h>
#include "avlcompare.h"

//recursive remove node
Node *removeN(Node **rootPtr, void* nodeToRemove,compare integerCompare)
 {
   int height;
   Node *removeN = removeN_Height(rootPtr, nodeToRemove, &height,integerCompare);
   return removeN;
  }

Node *removeN_Height(Node **rootPtr, void* nodeToRemove,int *height,compare integerCompare)
   {
     // height change return 1 , no height change return 0
      int compare2 = integerCompare(nodeToRemove,(*rootPtr));
       if (*rootPtr == NULL)
         {
           return NULL;
         }
       else if ( compare2 == -1 ){
           removeN_Height(&(*rootPtr)->left, nodeToRemove,height,integerCompare);
           if(*height == 1)
             (*rootPtr)->balanceFactor += 1;
             if((*rootPtr)->balanceFactor != 0)
             *height = 0;
          }
       else if (compare2 == 1 ){
            removeN_Height(&(*rootPtr)->right, nodeToRemove,height,integerCompare);
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
            if((*rootPtr)->balanceFactor == 0)
            *height = 1;
            else
            *height = 0;
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
              if((rootPtr)->balanceFactor!=0)
              *height = 0;
           else
             *height = 1;
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
