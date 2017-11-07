#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <stdio.h>
#include "Node.h"


Node *addNode(Node **rootPtr, Node *nodeToAdd);
int avlBalanceRightTree(Node **rootPtr);
int avlBalanceLeftTree(Node **rootPtr);
Node *removeNode(Node **rootPtr, Node *nodeToRemove);

#endif // _ADDNODE_H
