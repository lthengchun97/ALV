#ifndef _REMOVENODE_H
#define _REMOVENODE_H

#include <stdio.h>
#include "Node.h"
#include "addnode.h"

Node *removeNode(Node **rootPtr, Node *nodeToRemove);
int avlBalanceLeftTree(Node **rootPtr);
int avlBalanceRightTree(Node **rootPtr);

#endif // _REMOVENODE_H
