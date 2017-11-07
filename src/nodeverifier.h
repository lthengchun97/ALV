#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H

#include "Node.h"

#define TEST_ASSERT_EQUAL_NODE(left,right,bf,node) \
                          testAssertEqualNode(left,right,bf,node,__LINE__)

void testAssertEqualNode(Node *left, Node *right, int bf, Node *node,int lineNo);

#endif // _NODEVERIFIER_H
