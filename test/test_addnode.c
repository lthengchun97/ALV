#include "unity.h"
#include "rotate.h"
#include <stdio.h>
#include "addnode.h"
#include "rotate.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include "avlinteger.h"


void setUp(void)
{
  initData();
}

void tearDown(void)
{
}

/**
----------------test_insert_left----------
*        20            20
*         \           /   \
*          30  ->   10    30
*
**/
void test_insert_left_with_10(void)
{
    Node *root = &node20;
    initNode(&node20,NULL,&node30,1);

    avlAddInteger(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(&node20,root);
    TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
    TEST_ASSERT_EQUAL(0,node10.balanceFactor);
    TEST_ASSERT_EQUAL(0,node30.balanceFactor);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
}

/**
*          20(0)                           20(1)
*          /   \           add 40          /  \
*        10(0) 30(0)        ----->      10(0) 30(1)
*                                              \
*                                              40(0)
*
**/

void test_add_node_to_the_right(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,NULL,0);
  initNode(&node20,&node10,&node30,0);

  avlAddInteger(&root,&node40);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL(1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(1,node30.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
}

/**
*          20(0)                           20(-1)
*          /   \           add 5           /  \
*        10(0) 30(0)        ----->      10(-1) 30(0)
*                                        /
*                                       5(0)
*
**/

void test_add_node_to_the_left(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,NULL,0);
  initNode(&node20,&node10,&node30,0);

  avlAddInteger(&root,&node5);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL(-1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node5.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
  TEST_ASSERT_EQUAL(-1,node10.balanceFactor);
}

   /**
   *          20(+1)                           20(+2)                           30(-1)
   *          /   \            add 55           /  \             RL             /     \
   *        10(0) 30(0)        ----->      10(0) 30(1)          ----->       20(0)   40(1)
   *             /  \                            /  \                         /   \        \
   *         25(0)  40(0)                    25(0)   40(1)                  10(0) 25(0)     55(0)
   *                                                  \
   *                                                  55(0)
   **/

   void test_add_node_to_the_left1(void){
     Node *root = &node20;
     initNode(&node10,NULL,NULL,0);
     initNode(&node30,&node25,&node40,0);
     initNode(&node20,&node10,&node30,1);
     initNode(&node30,&node25,&node40,0);
     initNode(&node25,NULL,NULL,0);
     initNode(&node40,NULL,NULL,0);

     avlAddInteger(&root,&node55);
     TEST_ASSERT_EQUAL_PTR(&node30,root);
     TEST_ASSERT_EQUAL_PTR(&node55,node40.right);
     TEST_ASSERT_EQUAL(0,node20.balanceFactor);
     TEST_ASSERT_EQUAL(0,node25.balanceFactor);
     TEST_ASSERT_EQUAL(0,node30.balanceFactor);
     TEST_ASSERT_EQUAL(0,node10.balanceFactor);
     TEST_ASSERT_EQUAL(0,node55.balanceFactor);
     TEST_ASSERT_EQUAL(1,node40.balanceFactor);
   }
