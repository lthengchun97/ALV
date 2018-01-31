#ifndef _NODEHELPER_H
#define _NODEHELPER_H

#include "Node.h"

Node node1,node5,node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55,node70;
Node node100,node120,node150,node200,node250;
Node node60,node65,node75,node80,node85,node90,node95;
StringNode nodeCristiano,nodeMessi,nodeVanPersie,nodeRooney,nodeDeGea;

void initNode(Node *node,Node *left,Node *right, int bf);
void initStringNode(StringNode *node,StringNode *left,StringNode *right, int bf);
void initData(void);
void initStrData(void);


#endif // _NODEHELPER_H
