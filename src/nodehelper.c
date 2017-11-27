#include "nodehelper.h"

extern Node node1,node5,node10,node15,node20,node25,node30,node35,node40;
extern Node node45,node50,node55,node70;
extern Node node100;
extern Node node60,node65,node75,node80,node85,node90,node95;

void initNode(Node *node,Node *left,Node *right, int bf){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}
void initData(void)
{
  node1.data =1;
  node5.data =5;
  node10.data =10;
  node15.data =15;
  node20.data =20;
  node25.data =25;
  node30.data =30;
  node35.data =35;
  node40.data =40;
  node45.data =45;
  node50.data =50;
  node55.data =55;
  node60.data=60;
  node65.data=65;
  node70.data= 70;
  node75.data=75;
  node80.data=80;
  node95.data=85;
  node90.data=90;
  node95.data=95;
  node100.data=100;
}
