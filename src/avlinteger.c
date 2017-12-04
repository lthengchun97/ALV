#include "avlinteger.h"


int integerCompare(int data, Node *refNode){

  if(data < (refNode)->data)
  return -1;
  else if( data > (refNode)->data)
  return 0;
  else
  return 1;
}
