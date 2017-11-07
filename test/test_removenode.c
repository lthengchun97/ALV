#include "unity.h"
#include "rotate.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include "removenode.h"


void setUp(void)
{
  initData();
}

void tearDown(void)
{
}

/**
*          20(0)                           20(-1)
*          /   \           remove 30       /
*        10(0) 30(0)        ----->      10(0)
*
*
*
**/

void test_remove_node_30(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,NULL,0);
  initNode(&node20,&node10,&node30,0);

  removeNode(&root,&node30);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL(-1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
}

/**
*          20(0)                           20(1)
*          /   \           remove 10          \
*        10(0) 30(0)        ----->           30(0)
*
*
*
**/

void test_remove_node_10(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,NULL,0);
  initNode(&node20,&node10,&node30,0);

  removeNode(&root,&node10);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL(1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
}
