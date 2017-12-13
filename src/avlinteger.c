#include "avlinteger.h"


int integerCompare(int data, Node *refNode){
  if(data < (refNode)->data)
  return -1;
  else if( data > (refNode)->data)
  return 0;
  else
  return 1;
}

int stringCompare(char* data,Node *refNode){
  StringNode *refN = (StringNode*)refNode;
  //refN->data=refNode->data;
  int result = strcmp(data, (refN)->data);
  if (result > 0)
  {
    return -1;
  }
  else if (result < 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
