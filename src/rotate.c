#include "rotate.h"
#include "Node.h"
#include <stdio.h>

/**
 *        30             40
 *          \           /  \
 *          40   ---> 30    50
 *         /  \         \
 *        35  50        35
 *
 */
Node *rotateLeft(Node *node){
  Node *root;
  root = node->right;
  node->right = node->right->left;
  root->left = node;
  return root;
}

/**
 *        30            10
 *       /             /  \
 *     10       ---> 5    30
 *    /  \               /
 *  5     20           20
 *
 */
Node *rotateRight(Node *node){
  Node *root;
  root = node->left;
  node->left = node->left->right;
  root->right = node;
  return root;
}
/**
---------rotateleftright-----------------
*        45                   45                   30
*       /  \      RL"10"    /   \      RR"45"     /   \
*      10   50  ------->  30    50  ----------> 10     45
*        \               /  \                     \    / \
*        30             10   40                   25  40 50
*       /  \              \
*      25   40             25
*
**/
Node *rotateLeftRight(Node *node){
  Node *root;
  node->left = rotateLeft(node->left);
  root = rotateRight(node);
  return root;
}

Node *rotateRightLeft(Node *node){
  Node *root;
  node->right = rotateRight(node->right);
  root = rotateLeft(node);
  return root;
}
