#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <stdio.h>
#include "Node.h"
#include "rotate.h"
#include "avlcompare.h"

typedef int (*compare)(void *data, Node *refNode);

#define avlAddInteger(r,n)     addNode(r,n,(compare)integerCompare);
#define avlAddString(r,n)      addNode((Node **)r,(Node *)n,(compare)stringCompare);

//Node *addNode(Node **rootPtr, Node *nodeToAdd);
int addNode(Node **rootPtr, Node *nodeToAdd,compare integerCompare);
//int stringCompare(char* data,Node *refNode);


#endif // _ADDNODE_H
