#ifndef _REMOVENODE_H
#define _REMOVENODE_H

#include <stdio.h>
#include "Node.h"
#include "addnode.h"
#include "rotate.h"

Node *removeN(Node **rootPtr, int nodeToRemove);
Node *removeNode(Node **rootPtr, Node *nodeToRemove);
Node *removeN_Height(Node **rootPtr, int nodeToRemove,int *height);
Node *findnearest(Node *rootPtr,int *height);

#endif // _REMOVENODE_H
