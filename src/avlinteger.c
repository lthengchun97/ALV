#include "avlinteger.h"


int integerCompare(int data, Node *refNode){
  if(data < (refNode)->data)
  return -1;
  else if( data > (refNode)->data)
  return 0;
  else
  return 1;
}

int stringCompare(char* data,StringNode *refNode){
  int result = strcmp(data, (refNode)->data);
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
