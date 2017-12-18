#ifndef _REMOVENODE_H
#define _REMOVENODE_H

#include <stdio.h>
#include "Node.h"
#include "addnode.h"
#include "rotate.h"
#include "avlcompare.h"
#include "string.h"

typedef int (*compare)(void *data, Node *refNode);

#define avlRemoveInteger(r,n)     removeN((Node **)r,(int *)n,(compare)integerCompare);
#define avlRemoveString(r,n)     removeN((Node **)r,(char *)n,(compare)stringCompare);

Node *removeN(Node **rootPtr, void* nodeToRemove,compare integerCompare);
Node *removeN_Height(Node **rootPtr, void* nodeToRemove,int *height,compare integerCompare);
Node *findnearest(Node *rootPtr,int *height);

#endif // _REMOVENODE_H
