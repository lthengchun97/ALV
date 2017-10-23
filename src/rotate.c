#include "rotate.h"
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
 *        20            10
 *       /             /  \
 *     10       ---> 5    30
 *    /  \               /
 *  5     15           20
 *         \
 *         17
 */
//Node *rotateLeftRight(Node *node){

//}
