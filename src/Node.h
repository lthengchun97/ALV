#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>


typedef struct Node Node;
struct Node{
  Node *left;                       //Must be a pointer because its pointing to another Node
  Node *right;
  int balanceFactor;
  void* data;
};

typedef struct StringNode StringNode;
struct StringNode {
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char *data;
};

#endif // _NODE_H
