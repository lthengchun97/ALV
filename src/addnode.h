#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <stdio.h>
#include "Node.h"
#include "rotate.h"


//Node *addNode(Node **rootPtr, Node *nodeToAdd);
int addNode(Node **rootPtr, Node *nodeToAdd);
Node *removeNode(Node **rootPtr, Node *nodeToRemove);

#endif // _ADDNODE_H
