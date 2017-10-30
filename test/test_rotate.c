#include "unity.h"
#include "rotate.h"
#include <stdio.h>
#include "addnode.h"

Node node1,node5,node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55,node70;
Node node100;

void initNode(Node *node,Node *left,Node *right, int bf){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}
void setUp(void)
{
  node1.data =1;
  node5.data =5;
  node10.data =10;
  node15.data =15;
  node20.data =20;
  node25.data =25;
  node30.data =30;
  node35.data =35;
  node40.data =40;
  node45.data =45;
  node50.data =50;
  node55.data =55;
  node70.data= 70;
  node100.data=100;
}

void tearDown(void)
{

}
/**
 *        30             40
 *          \           /  \
 *          40   ---> 30    50
 *         /  \         \
 *        35  50        35
 *
 */
 void test_rotateLeft(void)
 {
   Node *root;
   initNode(&node35,NULL,NULL,0);
   initNode(&node50,NULL,NULL,0);
   initNode(&node40,&node35,&node50,0);
   initNode(&node30,NULL,&node40,+2);

   root = rotateLeft(&node30);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
   TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
   TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
   TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
   TEST_ASSERT_EQUAL_PTR(&node35,node30.right);
   TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
   TEST_ASSERT_EQUAL_PTR(&node30,node40.left);
   TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
 }

 /**
  *        30            10
  *       /             /  \
  *     10       ---> 5    30
  *    /  \               /
  *  5     20           20
  *
  */
void test_rotateRight(void)
{
  Node *root;
  initNode(&node5,NULL,NULL,0);
  initNode(&node20,NULL,NULL,0);
  initNode(&node10,&node5,&node20,0);
  initNode(&node30,&node10,NULL,-2);

  root = rotateRight(&node30);
  TEST_ASSERT_EQUAL_PTR(&node10,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
  TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
}
/**
*        45                   45                   30
*       /  \      RL"10"    /   \      RR"45"     /   \
*      10   50  ------->  30    50  ----------> 10     45
*        \               /  \                     \    / \
*        30             10   40                   25  40 50
*       /  \              \
*      25   40             25
*
**/
void test_rotateLeftRight(void)
{
  Node *root;
  initNode(&node25,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node30,&node25,&node40,0);
  initNode(&node10,NULL,&node30,1);
  initNode(&node50,NULL,NULL,0);
  initNode(&node45,&node10,&node50,-2);

  root = rotateLeftRight(&node45);
  TEST_ASSERT_EQUAL_PTR(&node30,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
  TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
  TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
}
/**
*         5                   5                   25
*       /  \      RL"40"    /   \      RR"5"     /   \
*      1   40  ------->   1     25  ----------> 5     40
*          /                    / \            /  \   /
*        25                    20 40          1   20  35
*       /  \                     /
*      20   35                  35
*
**/
void test_rotateRightLeft(void)
{
  Node *root;
  initNode(&node20,NULL,NULL,0);
  initNode(&node35,NULL,NULL,0);
  initNode(&node25,&node20,&node35,0);
  initNode(&node40,&node25,0,-1);
  initNode(&node1,NULL,NULL,0);
  initNode(&node5,&node1,&node40,2);

  root = rotateRightLeft(&node5);
  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node1.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node1.right);
  TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
  TEST_ASSERT_EQUAL_PTR(&node20,node5.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
}

/**
 *        40(+2)                    50 (0)
 *          \             RL         /    \
 *         50 (+1)       --->    40(0)  100(0)
 *          \
 *         100 (0)
 *
 */

void test_balanceTree_given_40_50_100_expect_a_balance_tree(void)
{
    Node *root = NULL ;
    initNode(&node100,NULL,NULL,0);
    initNode(&node50,NULL,&node100,1);
    initNode(&node40,NULL,&node50,2);
    root = &node40;

    avlBalanceRightTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node100.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node100.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node50.left);
    TEST_ASSERT_EQUAL_PTR(&node100,node50.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL(0,node40.balanceFactor);
    TEST_ASSERT_EQUAL(0,node100.balanceFactor);
    TEST_ASSERT_EQUAL(0,node50.balanceFactor);
}

/**
 *        40(+2)                    50 (-1)
 *          \            RL          /    \
 *         50 (0)       --->    40(1)  100(0)
 *       /     \                   \
 *     70 (0)  100 (0)             70 (0)
 *
 */


 void test_balanceTree_given_40_50_70_100_expect_a_balance_tree(void)
 {
     Node *root = NULL ;
     initNode(&node100,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node50,&node70,&node100,0);
     initNode(&node40,NULL,&node50,2);
     root = &node40;

     avlBalanceRightTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node50,root);
     TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
     TEST_ASSERT_EQUAL_PTR(&node70,node40.right);
     TEST_ASSERT_EQUAL_PTR(NULL,node100.left);
     TEST_ASSERT_EQUAL_PTR(NULL,node100.right);
     TEST_ASSERT_EQUAL_PTR(&node40,node50.left);
     TEST_ASSERT_EQUAL_PTR(&node100,node50.right);
     TEST_ASSERT_EQUAL(1,node40.balanceFactor);
     TEST_ASSERT_EQUAL(0,node100.balanceFactor);
     TEST_ASSERT_EQUAL(-1,node50.balanceFactor);
     TEST_ASSERT_EQUAL(0,node70.balanceFactor);
 }

 /**
  *        40(-2)                    20 (1)
  *        /            RR          /    \
  *       20 (0)       --->    10(0)    40(-1)
  *      /    \                           /
  *   10 (0)  30 (0)                   30 (0)
  *
  */

  void test_balanceTree_given_40_20_10_30_expect_a_balance_tree(void)
  {
      Node *root = NULL ;
      initNode(&node10,NULL,NULL,0);
      initNode(&node30,NULL,NULL,0);
      initNode(&node40,&node20,NULL,-2);
      initNode(&node20,&node10,&node30,0);
      root = &node40;

      avlBalanceLeftTree(&root);
      TEST_ASSERT_EQUAL_PTR(&node20,root);
      TEST_ASSERT_EQUAL_PTR(&node30,node40.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
      TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
      TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
      TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
      TEST_ASSERT_EQUAL_PTR(&node40,node20.right);
      TEST_ASSERT_EQUAL(1,node20.balanceFactor);
      TEST_ASSERT_EQUAL(0,node10.balanceFactor);
      TEST_ASSERT_EQUAL(-1,node40.balanceFactor);
      TEST_ASSERT_EQUAL(0,node30.balanceFactor);
  }

  /**
   *        40(-2)                    20 (0)
   *        /            RR          /    \
   *       20 (-1)      --->    10(0)    40(0)
   *      /
   *   10 (0)
   *
   */

   void test_balanceTree_given_40_20_10_expect_a_balance_tree(void)
   {
       Node *root = NULL ;
       initNode(&node10,NULL,NULL,0);
       initNode(&node20,&node10,NULL,-1);
       initNode(&node40,&node20,NULL,-2);
       root = &node40;

       avlBalanceLeftTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node20,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
       TEST_ASSERT_EQUAL_PTR(&node40,node20.right);
       TEST_ASSERT_EQUAL(0,node20.balanceFactor);
       TEST_ASSERT_EQUAL(0,node10.balanceFactor);
       TEST_ASSERT_EQUAL(0,node40.balanceFactor);
   }

   /**
   *          45 (-2)                   45(-2)                                30(0)
   *        /      \        RL         /    \           RR                /          \
   *      10(1)   50(0)  -------> 30(-1)   50(0)  ---------->         10(0)           45(0)
   *     /    \                   /   \                             /     \        /        \
   *    5(0)  30(0)             10(0) 40(0)                        5(0)  25(0)   40(0)     50(0)
   *         /    \            /   \
   *      25(0)    40(0)    5(0)   25(0)
   *
   **/

   void test_balanceTree_given_45_10_50_25_30_40expect_a_balance_tree(void)
   {
       Node *root = NULL ;
       initNode(&node25,NULL,NULL,0);
       initNode(&node40,NULL,NULL,0);
       initNode(&node30,&node25,&node40,0);
       initNode(&node10,&node5,&node30,1);
       initNode(&node5,NULL,NULL,0);
       initNode(&node50,NULL,NULL,0);
       initNode(&node45,&node10,&node50,-2);
       root = &node45;

       avlBalanceLeftTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
       TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
       TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
       TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
       TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
       TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
       TEST_ASSERT_EQUAL(0,node5.balanceFactor);
       TEST_ASSERT_EQUAL(0,node25.balanceFactor);
       TEST_ASSERT_EQUAL(0,node40.balanceFactor);
       TEST_ASSERT_EQUAL(0,node50.balanceFactor);
       TEST_ASSERT_EQUAL(0,node30.balanceFactor);
       TEST_ASSERT_EQUAL(0,node10.balanceFactor);
       TEST_ASSERT_EQUAL(0,node45.balanceFactor);
   }

   /**
   *          45 (-2)                   45(-2)                               30(0)
   *        /      \        RL         /    \           RR                /        \
   *      10(1)   50(0)  -------> 30(-1)   50(0)  ---------->         10(-1)         45(0)
   *     /    \                   /   \                             /                /   \
   *    5(0)  30(1)             10(0) 40(0)                        5(0)           40(0)  50(0)
   *            \               /
   *            40(0)       5(0)
   *
   **/

   void test_balanceTree_given_45_10_50_30_40_expect_a_balance_tree_rotate_left_right(void)
   {
       Node *root = NULL ;
       initNode(&node40,NULL,NULL,0);
       initNode(&node30,NULL,&node40,1);
       initNode(&node10,&node5,&node30,1);
       initNode(&node5,NULL,NULL,0);
       initNode(&node50,NULL,NULL,0);
       initNode(&node45,&node10,&node50,-2);
       root = &node45;

       avlBalanceLeftTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
       TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
       TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
       TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
       TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
       TEST_ASSERT_EQUAL(0,node5.balanceFactor);
       TEST_ASSERT_EQUAL(0,node40.balanceFactor);
       TEST_ASSERT_EQUAL(0,node50.balanceFactor);
       TEST_ASSERT_EQUAL(0,node30.balanceFactor);
       TEST_ASSERT_EQUAL(-1,node10.balanceFactor);
       TEST_ASSERT_EQUAL(0,node45.balanceFactor);
   }


   /**
   *          45 (-2)                   45(-2)                               30(0)
   *        /      \        RL         /    \           RR                /        \
   *      10(1)   50(0)  -------> 30(-2)   50(0)  ---------->         10(0)         45(1)
   *     /    \                    /                                /    \               \
   *    5(0)  30(-1)             10(0)                         5(0)     25(0)            50(0)
   *           /                 /   \
   *          25(0)            5(0)  25(0)
   *
   **/

   void test_balanceTree_given_45_10_50_30_25_expect_a_balance_tree(void)
   {
       Node *root = NULL ;
       initNode(&node25,NULL,NULL,0);
       initNode(&node30,&node25,NULL,-1);
       initNode(&node10,&node5,&node30,1);
       initNode(&node5,NULL,NULL,0);
       initNode(&node50,NULL,NULL,0);
       initNode(&node45,&node10,&node50,-2);
       root = &node45;

       avlBalanceLeftTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
       TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
       TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
       TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node45.left);
       TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
       TEST_ASSERT_EQUAL(0,node5.balanceFactor);
       TEST_ASSERT_EQUAL(0,node25.balanceFactor);
       TEST_ASSERT_EQUAL(0,node50.balanceFactor);
       TEST_ASSERT_EQUAL(0,node30.balanceFactor);
       TEST_ASSERT_EQUAL(0,node10.balanceFactor);
       TEST_ASSERT_EQUAL(1,node45.balanceFactor);
   }

   /**
   *          20 (2)                   20(2)                               30(0)
   *        /      \        RR         /    \           RL                /       \
   *      10(0)   50(-1)  -------> 10(0)   30(1)  ---------->         20(0)         50(1)
   *              /    \                    /   \                     /   \           \
   *            30(-1)  55(0)           25(0)   50(1)              10(0)  25(0)     55(0)
   *            /                                \
   *          25(0)                              55(0)
   *
   **/

   void test_balanceTree_given_45_10_50_30_40expect_a_balance_tree(void)
   {
       Node *root = NULL ;
       initNode(&node25,NULL,NULL,0);
       initNode(&node30,&node25,NULL,-1);
       initNode(&node50,&node30,&node55,-1);
       initNode(&node10,NULL,NULL,0);
       initNode(&node55,NULL,NULL,0);
       initNode(&node20,&node10,&node50,2);
       root = &node20;

       avlBalanceRightTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node55.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node55.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
       TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
       TEST_ASSERT_EQUAL_PTR(&node50,node30.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
       TEST_ASSERT_EQUAL_PTR(&node25,node20.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
       TEST_ASSERT_EQUAL_PTR(&node55,node50.right);
       TEST_ASSERT_EQUAL(0,node25.balanceFactor);
       TEST_ASSERT_EQUAL(0,node55.balanceFactor);
       TEST_ASSERT_EQUAL(1,node50.balanceFactor);
       TEST_ASSERT_EQUAL(0,node30.balanceFactor);
       TEST_ASSERT_EQUAL(0,node10.balanceFactor);
       TEST_ASSERT_EQUAL(0,node20.balanceFactor);
   }


   /**
   *          20 (2)                   20(2)                               30(0)
   *        /      \        RR         /    \           RL                /       \
   *      10(0)   50(-1)  -------> 10(0)   30(1)  ---------->         20(0)         50(0)
   *              /    \                    /   \                     /   \         /   \
   *            30(0)  55(0)           25(0)   50(0)              10(0)  25(0)    40(0)  55(0)
   *            /   \                          /    \
   *          25(0) 40(0)                    40(0) 55(0)
   *
   **/

   void test_balanceTree_given_45_10_50_30_40_25_55_expect_a_balance_tree(void)
   {
       Node *root = NULL ;
       initNode(&node25,NULL,NULL,0);
       initNode(&node30,&node25,&node40,0);
       initNode(&node50,&node30,&node55,-1);
       initNode(&node10,NULL,NULL,0);
       initNode(&node40,NULL,NULL,0);
       initNode(&node55,NULL,NULL,0);
       initNode(&node20,&node10,&node50,2);
       root = &node20;

       avlBalanceRightTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node55.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node55.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
       TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
       TEST_ASSERT_EQUAL_PTR(&node50,node30.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
       TEST_ASSERT_EQUAL_PTR(&node25,node20.right);
       TEST_ASSERT_EQUAL_PTR(&node40,node50.left);
       TEST_ASSERT_EQUAL_PTR(&node55,node50.right);
       TEST_ASSERT_EQUAL(0,node25.balanceFactor);
       TEST_ASSERT_EQUAL(0,node55.balanceFactor);
       TEST_ASSERT_EQUAL(0,node50.balanceFactor);
       TEST_ASSERT_EQUAL(0,node30.balanceFactor);
       TEST_ASSERT_EQUAL(0,node10.balanceFactor);
       TEST_ASSERT_EQUAL(0,node20.balanceFactor);
   }

   /**
   *          20 (2)                   20(2)                               30(0)
   *        /      \        RR         /    \           RL                /       \
   *      10(0)   50(-1)  -------> 10(0)   30(2)  ---------->         20(-1)       50(0)
   *              /    \                        \                     /            /   \
   *            30(1)  55(0)                   50(0)              10(0)          40(0)  55(0)
   *               \                          /    \
   *              40(0)                    40(0) 55(0)
   *
   **/

   void test_balanceTree_given_45_10_50_30_40_55_expect_a_balance_tree(void)
   {
       Node *root = NULL ;
       initNode(&node30,NULL,&node40,1);
       initNode(&node50,&node30,&node55,-1);
       initNode(&node10,NULL,NULL,0);
       initNode(&node40,NULL,NULL,0);
       initNode(&node55,NULL,NULL,0);
       initNode(&node20,&node10,&node50,2);
       root = &node20;

       avlBalanceRightTree(&root);
       TEST_ASSERT_EQUAL_PTR(&node30,root);
       TEST_ASSERT_EQUAL_PTR(NULL,node55.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node55.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
       TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
       TEST_ASSERT_EQUAL_PTR(&node50,node30.right);
       TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
       TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
       TEST_ASSERT_EQUAL_PTR(&node40,node50.left);
       TEST_ASSERT_EQUAL_PTR(&node55,node50.right);
       TEST_ASSERT_EQUAL(0,node55.balanceFactor);
       TEST_ASSERT_EQUAL(0,node50.balanceFactor);
       TEST_ASSERT_EQUAL(0,node30.balanceFactor);
       TEST_ASSERT_EQUAL(0,node10.balanceFactor);
       TEST_ASSERT_EQUAL(-1,node20.balanceFactor);
   }
