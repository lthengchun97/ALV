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

   /**
   ---------avlAdd 20 to 30->left & rotate right----------------------
   *       40                    40 (-2)                    30 (0)
   *       /      add 20        /      rotate    right      /   \
   *     30 (0)  ------> (-1) 30 --------------------->  20    40 (0)
   *                         /
   *                       20
   *
   **/
   void test_avlAdd_given_40_30_avlAdd_20_expect_balance(void){

       initNode(&node30,NULL,NULL,0);
       initNode(&node20,NULL,NULL,0);
       initNode(&node40,&node30,NULL,-1);

       Node *root = &node40;
       avlAddInteger(&root,&node20);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
       TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
       TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
   }

   /**
   ---------avlAdd   &    rotateleftRight(1)----------------------
   *        90(-1)               90 (-2)                                 60 (0)
   *       /  \    add 70        /  \            rotateLeftRight        /     \
   *     50   100 --------> (1)50   100      ------------------>      50 (-1)  90 (0)
   *    /  \                  /  \                                   /         / \
   *   45   60              45     60(1)                            45       70 100
   *                               \
   *                               70
   **/
   void test_avlAdd_given_90_50_100_45_60_avlAdd_70_expect_balance(void){

        initNode(&node45,NULL,NULL,0);
        initNode(&node60,NULL,NULL,0);
        initNode(&node70,NULL,NULL,0);
        initNode(&node100,NULL,NULL,0);
        initNode(&node90,&node50,&node100,-1);
        initNode(&node50,&node45,&node60,0);

        Node *root = &node90;
        avlAddInteger(&root,&node70);
        TEST_ASSERT_EQUAL_PTR(&node60,root);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
        TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
        TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
        TEST_ASSERT_EQUAL_NODE(&node70,&node100,0,&node90);
   }

   /**
   --------------------------------added 55 & rotateleftRight(2)----------------------
   *         90 (-1)                    90 (-2)                                60 (0)
   *        / \      added 55          /  \            rotateLeftRight        /     \
   *  (0) 50   100  --------->   (1) 50   100      ------------------>      50 (0)   90 (1)
   *     / \                         / \                                  /  \        \
   *   45  60 (0)                 45  60 (-1)                           45   55        100
   *                                 /
   *                               55
   * root -1 child 0 grandchild 0
   **/

   void test_avlAdd_55_then_rotateLeftRight_in_rotateleftright_condition3_expect_balance(void){

        initNode(&node45,NULL,NULL,0);
        initNode(&node55,NULL,NULL,0);
        initNode(&node100,NULL,NULL,0);
        initNode(&node60,NULL,NULL,0);
        initNode(&node90,&node50,&node100,-1);
        initNode(&node50,&node45,&node60,0);

        Node *root = &node90;
        avlAddInteger(&root,&node55);
        TEST_ASSERT_EQUAL_PTR(&node60,root);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
        TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
        TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
        TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);

   }
   /**
   ---------avlAdd   &    rotateleftRight(1)----------------------
   *        90(-1)               90 (-1)
   *       /  \    add 60        /  \
   *     50   100 --------> (0)50   100
   *    /                     /  \
   *   45                   45     60
   *
   *
   **/
   void test_avlAdd_given_90_50_1pect_balance(void){

        initNode(&node45,NULL,NULL,0);
        initNode(&node60,NULL,NULL,0);
        initNode(&node100,NULL,NULL,0);
        initNode(&node90,&node50,&node100,-1);
        initNode(&node50,&node45,NULL,-1);

        Node *root = &node90;
        avlAddInteger(&root,&node60);
        TEST_ASSERT_EQUAL_PTR(&node90,root);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
        TEST_ASSERT_EQUAL_NODE(&node45,&node60,0,&node50);
        TEST_ASSERT_EQUAL_NODE(&node50,&node100,-1,&node90);
   }
   /*
   ---------------avlAdd 100 &  rotateLeft----------------------
   *  40(1)             40 (+2)                           50
   *    \               \          rotateLeft           /   \
   *    50(0)           50 (+1)   ------------->      40    100
   *                     \
   *                     100
   *
   **/
   void test_avlAdd_100_thn_rotate_left_expect_balance(void){

       initNode(&node100,NULL,NULL,0);
       initNode(&node50,NULL,NULL,0);
       initNode(&node40,NULL,&node50,1);

       Node *root = &node40;
       avlAddInteger(&root,&node100);
       TEST_ASSERT_EQUAL_PTR(&node50,root);
       TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
       TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
       TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
   }

   /**
   -----------------------------add 30 & rotateRightLeft(1)----------------------------
   *      20                           20 (+2)                                35 (0)
   *     /  \     ADDED 30           /  \           rotateRightLeft        /     \
   *   15   40  ----------->       15   40 (-1)     --------------->    20 (0)   40 (+1)
   *       / \                         / \                            /  \        \
   *      35  50                (-1) 35  50                          15   30       50
   *                                /
   *                               30
   **/
   void test_avlAdd_30_rotateRightLeft_condition1_expect_balance(void){

        initNode(&node15,NULL,NULL,0);
        initNode(&node30,NULL,NULL,0);
        initNode(&node50,NULL,NULL,0);
        initNode(&node35,NULL,NULL,0);
        initNode(&node40,&node35,&node50,0);
        initNode(&node20,&node15,&node40,1);

        Node *root = &node20;
        avlAddInteger(&root,&node30);
        TEST_ASSERT_EQUAL_PTR(&node35,root);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);
        TEST_ASSERT_EQUAL_NODE(NULL,&node50,1,&node40);
        TEST_ASSERT_EQUAL_NODE(&node15,&node30,0,&node20);
        TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node35);
   }
   /**
   -------------------------added 75 & rotateRightLeft(3)---------------------------------
   *        60                        60 (+2)                                70 (0)
   *      /  \       added 75        /  \           rotateRightLeft        /     \
   *    40    80    ---------->    40   80 (-1)     --------------->   60 (-1)   80 (0)
   *         / \                       / \                            /        /  \
   *       70 100                (+1)70  100                        40      75   100
   *                               \
   *                               75
   **/
   void test_avlAdd_75_given_AVL_need_rotateRightLeft_expect_balance(void){

        initNode(&node40,NULL,NULL,0);
        initNode(&node75,NULL,NULL,0);
        initNode(&node100,NULL,NULL,0);
        initNode(&node70,NULL,NULL,0);
        initNode(&node80,&node70,&node100,0);
        initNode(&node60,&node40,&node80,1);

        Node *root = &node60;
        avlAddInteger(&root,&node75);
        TEST_ASSERT_EQUAL_PTR(&node70,root);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
        TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
        TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node60);
        TEST_ASSERT_EQUAL_NODE(&node75,&node100,0,&node80);
        TEST_ASSERT_EQUAL_NODE(&node60,&node80,0,&node70);
   }
