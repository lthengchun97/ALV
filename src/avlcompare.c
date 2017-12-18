#include "avlcompare.h"


int integerCompare(int data, Node *refNode){
  if(data < (refNode)->data)
  return -1;
  else if( data > (refNode)->data)
  return 1;
  else
  return 0;
}

int stringCompare(char* data,Node *refNode){
  StringNode *refN = (StringNode*)refNode;
  //refN->data=refNode->data;
  return strcmp(data, (refN)->data);
}
