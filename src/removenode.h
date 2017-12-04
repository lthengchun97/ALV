#ifndef _REMOVENODE_H
#define _REMOVENODE_H

#include <stdio.h>
#include "Node.h"
#include "addnode.h"
#include "rotate.h"
#include "avlinteger.h"

typedef int (*compare)(void *data, Node *refNode);

#define avlRemoveInteger(r,n)     removeN(r,n,(compare)integerCompare);

Node *removeN(Node **rootPtr, int nodeToRemove,compare integerCompare);
Node *removeN_Height(Node **rootPtr, int nodeToRemove,int *height,compare integerCompare);
Node *findnearest(Node *rootPtr,int *height);

#endif // _REMOVENODE_H
