#include "nodehelper.h"

extern Node node1,node5,node10,node15,node20,node25,node30,node35,node40;
extern Node node45,node50,node55,node70;
extern Node node100;
extern Node node60,node65,node75,node80,node85,node90,node95;

extern StringNode nodeCristiano,nodeMessi,nodeVanPersie,nodeRooney,nodeDeGea;

void initNode(Node *node,Node *left,Node *right, int bf)
{
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}

void initStringNode(StringNode *node,StringNode *left,StringNode *right, int bf)
{
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}

void initStrData(void){
  nodeCristiano.data = "Cristiano";
  nodeMessi.data = "Messi";
  nodeVanPersie.data = "VanPersie";
  nodeRooney.data ="Rooney";
  nodeDeGea.data = "DeGea";
}

void initData(void)
{
  node1.data =(int *)1;
  node5.data =(int *)5;
  node10.data =(int *)10;
  node15.data =(int *)15;
  node20.data =(int *)20;
  node25.data =(int *)25;
  node30.data =(int *)30;
  node35.data =(int *)35;
  node40.data =(int *)40;
  node45.data =(int *)45;
  node50.data =(int *)50;
  node55.data =(int *)55;
  node60.data=(int *)60;
  node65.data=(int *)65;
  node70.data=(int *)70;
  node75.data=(int *)75;
  node80.data=(int *)80;
  node95.data=(int *)85;
  node90.data=(int *)90;
  node95.data=(int *)95;
  node100.data=(int *)100;
}
