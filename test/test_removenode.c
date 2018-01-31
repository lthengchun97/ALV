#include "unity.h"
#include "rotate.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include "removenode.h"
#include "avlcompare.h"
#include "Exception.h"
#include "CException.h"
#include "addnode.h"

CEXCEPTION_T ex;
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
**/

void test_remove_node_30(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,NULL,0);
  initNode(&node20,&node10,&node30,0);
  Try{
  avlRemoveInteger(&root,30);
  }
  Catch(ex){
  dumpException(ex);
  }
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
  Try{
  avlRemoveInteger(&root,10);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL(1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
}

/**
*          20(0)         remove 20         NULL
*                         ----->
*
*
*
**/

void test_remove_node_20(void){
  Node *root = &node20;
  initNode(&node20,NULL,NULL,0);
  Try{
  avlRemoveInteger(&root,20);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(NULL,root);
}

/**
*       40(-1)                        30 (0)
*       /          remove 40
*     30 (0)  --------------->
*
*/
void test_remove_node_30_and_left_40_only(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);

    Node *root = &node40;
    Try{
    avlRemoveInteger(&root,40);
    }
    Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
    TEST_ASSERT_EQUAL(0,node30.balanceFactor);
}

/**
*       40(-1)                        40 (0)
*       /          remove 30
*     30 (0)  --------------->
*
*/
void test_remove_30_and_left_40_only(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);

    Node *root = &node40;
    Try{
    avlRemoveInteger(&root,30);
    }
    Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node40,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/**
*          20(1)                           30(0)
*          /   \           remove 20       /   \
*        10(0) 30(1)        ----->     10(0)    40(0)
*                \
*               40(0)
*
**/

void test_remove_node_20_replace_by_node_30(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,&node40,1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,NULL,0);
  Try{
  avlRemoveInteger(&root,20);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node30,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
}

/**
*          20(0)                           20(0)
*          /   \           remove 30       /   \
*        10(0) 30(1)        ----->     10(0)    40(0)
*                \
*               40(0)
*
**/

void test_remove_node_30_replace_by_node_40(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,NULL,&node40,1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,NULL,0);
  Try{
  avlRemoveInteger(&root,30);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(0,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
}

/**
*          20(1)                           20(1)
*          /   \           remove 30       /   \
*        10(0) 30(0)        ----->     10(0)    40(-1)
*             /   \                            /
*         25(0)  40(0)                      25(0)
*
**/
void test_remove_node_30_replace_by_node_40_v2(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,&node25,&node40,0);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  Try{
  avlRemoveInteger(&root,30);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(&node25,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
  TEST_ASSERT_EQUAL(-1,node40.balanceFactor);
  TEST_ASSERT_EQUAL(1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node25.balanceFactor);
}

/**
*          20(1)                           25(1)
*          /   \           remove 20       /   \
*        10(0) 30(0)        ----->     10(0)    30(1)
*              /  \                               \
*           25(0) 40(0)                         40(0)
*
**/

void test_remove_node_20_replace_by_node_25(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,&node25,&node40,0);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  Try{
  avlRemoveInteger(&root,20);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node25.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node25.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(1,node30.balanceFactor);
  TEST_ASSERT_EQUAL(1,node25.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
}

/**
*       40(-1)                            40 (-2)                                  30 (0)
*       / \          remove 60          /                 rotate right           /  \
*   30 (-1) 60(0)   --------------->   30(-1)            ------------>         15(0) 40 (0)
*   /                                 /
*  15                               15
*
**/

void test_remove_node_60_and_rotate_right(void){
  Node *root = &node40;
  initNode(&node15,NULL,NULL,0);
  initNode(&node30,&node15,NULL,-1);
  initNode(&node40,&node30,&node60,-1);
  initNode(&node60,NULL,NULL,0);
  Try{
  avlRemoveInteger(&root,60);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node30,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node15,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
  TEST_ASSERT_EQUAL(0,node15.balanceFactor);
}

/**
*       40(-1)                            40 (-2)                                  30 (1)
*       / \          remove 80          /                 rotate right           /  \
*   30 (0) 80(0)   --------------->   30(0)            ------------>          10     40 (-1)
*   / \                               / \                                            /
*  10  35                           10  35                                          35
*
**/
void test_remove_80_and_rotate_right(void){

    initNode(&node30,&node10,&node35,0);
    initNode(&node40,&node30,&node80,-1);
    initNode(&node80,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node10,NULL,NULL,0);
    Node *root = &node40;
    Try{
    avlRemoveInteger(&root,80);
    }
    Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
    TEST_ASSERT_EQUAL_NODE(&node10,&node40,1,&node30);
}

/**
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotate leftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (-1) 50  90 (0)
*      / \     \                            / \                                          /    / \
*  45   60 (1)   100(0)                    45  60 (1)                                   45   70   95
*        \                                       \
*        70                                       70
*
**/
void test_remove_100_and_rotate_left_right(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node95,NULL,&node100,1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,NULL,&node70,1);

     Node *root = &node90;
     Try{
     avlRemoveInteger(&root,100);
    }
      Catch(ex){
      dumpException(ex);
      }
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);
}

/**
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotate leftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95(0)         ---------------->       50(0)   90 (0)
*      / \     \                            / \                                          / \   / \
*  45(0) 60(0) 100(0)                    45   60 (-1)                                   45  55 70 95
*        / \                                 /  \
*       55  70                              55  70
*
**/

void test_remove_100(void){
  Node *root = &node90;
  initNode(&node45,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node95,NULL,&node100,1);
  initNode(&node90,&node50,&node95,-1);
  initNode(&node50,&node45,&node60,1);
  initNode(&node60,&node55,&node70,0);


  Try{
  avlRemoveInteger(&root,100);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(root,&node60);
  TEST_ASSERT_EQUAL_PTR(NULL,node45.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node45.right);
  TEST_ASSERT_EQUAL_PTR(&node45,node50.left);
  TEST_ASSERT_EQUAL_PTR(&node55,node50.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node55.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node55.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node95.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node95.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node70.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node70.right);
  TEST_ASSERT_EQUAL_PTR(&node70,node90.left);
  TEST_ASSERT_EQUAL_PTR(&node95,node90.right);
  TEST_ASSERT_EQUAL_PTR(&node50,node60.left);
  TEST_ASSERT_EQUAL_PTR(&node90,node60.right);
  TEST_ASSERT_EQUAL(0,node45.balanceFactor);
  TEST_ASSERT_EQUAL(0,node55.balanceFactor);
  TEST_ASSERT_EQUAL(0,node70.balanceFactor);
  TEST_ASSERT_EQUAL(0,node95.balanceFactor);
  TEST_ASSERT_EQUAL(0,node90.balanceFactor);
  TEST_ASSERT_EQUAL(0,node50.balanceFactor);
  TEST_ASSERT_EQUAL(0,node60.balanceFactor);
}

/**
*          20(1)                           25(0)                                    25(0)
*          /   \           remove 20       /   \              rotate left          /  \
*       10(-1) 30(1)        ----->     10(-1)  30(2)          ----->          10(-1)  40(0)
*       /      /  \                     /       \                              /      / \
*     5(0)   25(0) 40(1)              5(0)      40(1)                        5(0)  30(0) 50(0)
*                    \                           \
*                    50(0)                       50(0)
**/

void test_remove_node_20_replace_by_node_25_v2(void){
  Node *root = &node20;
  initNode(&node10,&node5,NULL,-1);
  initNode(&node30,&node25,&node40,1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,&node50,1);
  initNode(&node25,NULL,NULL,0);
  initNode(&node5,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);

  Try{
  avlRemoveInteger(&root,20);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node25.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
  TEST_ASSERT_EQUAL_PTR(&node30,node40.left);
  TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
  TEST_ASSERT_EQUAL(0,node25.balanceFactor);
  TEST_ASSERT_EQUAL(-1,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node50.balanceFactor);
  TEST_ASSERT_EQUAL(0,node5.balanceFactor);
}

/**
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
*
**/
void test_remove_given_Avl_tree_remove_60_test2(void){

  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,&node80,1);
  initNode(&node100,NULL,NULL,0);
  initNode(&node30,NULL,&node35,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);

  Node *root = &node60;
  Try{
  avlRemoveInteger(&root,40);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
  TEST_ASSERT_EQUAL_PTR(&node50,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node75,node90.left);
  TEST_ASSERT_EQUAL_PTR(&node100,node90.right);
  TEST_ASSERT_EQUAL_PTR(&node30,node60.left);
  TEST_ASSERT_EQUAL_PTR(&node90,node60.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(&node35,node50.left);
  TEST_ASSERT_EQUAL_PTR(&node55,node50.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node75.left);
  TEST_ASSERT_EQUAL_PTR(&node80,node75.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node100.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node100.right);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node35.balanceFactor);
  TEST_ASSERT_EQUAL(0,node55.balanceFactor);
  TEST_ASSERT_EQUAL(0,node80.balanceFactor);
  TEST_ASSERT_EQUAL(0,node50.balanceFactor);
  TEST_ASSERT_EQUAL(-1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(1,node75.balanceFactor);
  TEST_ASSERT_EQUAL(0,node100.balanceFactor);
  TEST_ASSERT_EQUAL(-1,node90.balanceFactor);
  TEST_ASSERT_EQUAL(0,node60.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
}
/**
*
*
*               40(-1)      ---------->         30
*              /     \                          / \
*            20(1)   50(1)                    20    50
*           / \        \                     /    /  \
*         10   30(1)   55                   10     35   55
*               \
*               35
**/

void test_noderemove_remove_with_right_value_is_NULL5(void)
{
    Node *root = &node40;

    initNode(&node40,&node20,&node50,-1);
    initNode(&node20,&node10,&node30,1);
    initNode(&node50,NULL,&node55,1);
    initNode(&node30,NULL,&node35,1);
    initNode(&node10,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node55,NULL,NULL,0);
    Try{
    avlRemoveInteger(&root,40);
    }
    Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
    TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
    TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
*
*                               remove 40                           rotateleft at 50
*               40        ------------------->      45            ---------------->         45
*              /  \                                 / \                                    / \
*            20   50                               20  50                                 20  55
*           /    /  \                             /     \                                 /   / \
*         10    45   55                          10      55                             10   50  60
*                      \                                   \
*                       60                                 60
*
**/

void test_remove_testing(void){

  initNode(&node40,&node20,&node50,1);
  initNode(&node20,&node10,NULL,-1);
  initNode(&node50,&node45,&node55,1);
  initNode(&node55,NULL,&node60,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node60,NULL,NULL,0);

  Node *root = &node40;
  Try{
  avlRemoveInteger(&root,40);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_PTR(&node50,node55.left);
  TEST_ASSERT_EQUAL_PTR(&node60,node55.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(&node20,node45.left);
  TEST_ASSERT_EQUAL_PTR(&node55,node45.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node60.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node60.right);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node50.balanceFactor);
  TEST_ASSERT_EQUAL(0,node60.balanceFactor);
  TEST_ASSERT_EQUAL(0,node55.balanceFactor);
  TEST_ASSERT_EQUAL(-1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node45.balanceFactor);
}


/**
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
*
**/
void test_remove_given_Avl_tree_remove_60_test3(void){

  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,&node80,1);
  initNode(&node100,NULL,NULL,0);
  initNode(&node30,NULL,&node35,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);

  Node *root = &node60;
  Try{
  avlRemoveInteger(&root,40);
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node90,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node75,&node100,-1,&node90);
  TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}

/**
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             /     /  \
*  15      40  100                         40   100                          20   45   100
*           \                              \
*           45                              45
*
*
**/
void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition3_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,NULL,&node45,1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     Try{
     avlRemoveInteger(&root,15);
      }
      Catch(ex){
      dumpException(ex);
      }
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,NULL,-1,&node30);
}

/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             / \    / \
*  15      40  100                         40   100                          20 35  45    100
*         / \                             / \
*       35  45                           35 45
*
*
**/
void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition2_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,&node35,&node45,0);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     Try{
     avlRemoveInteger(&root,15);
    }
    Catch(ex){
    dumpException(ex);
    }
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
}

/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             / \      \
*  15      40  100                         40   100                          20 35      100
*         /                                /
*       35                               35
*
*
**/

void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition1_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,&node35,NULL,-1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     Try{
     avlRemoveInteger(&root,15);
   }
   Catch(ex){
   dumpException(ex);
   }
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
}

/**
---------------------------------remove 30 and rotateLeft---------------------------------
*        40 (1)                            40 (+2)                             50(0)
*       /   \           remove 30            \                 rotate left    /   \
*     30     50 (0)   ---------->            50(0)        -------------->  40(+1) 100(0)
*            /\                              /   \                          \
*          45  100                         45   100                         45(0)
*
**/
void test_remove_rotateleft2(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node100,NULL,NULL,0);
    initNode(&node45,NULL,NULL,0);
    initNode(&node50,&node45,&node100,0);
    initNode(&node40,&node30,&node50,1);

    Node *root = &node40;
    Try{
    avlRemoveInteger(&root,30);
    }
    Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,-1,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);


}

/**
---------------------------------remove 30 and rotateLeft---------------------------------
*        40 (1)                            40 (+2)                             50(0)
*       /   \           remove 30            \                 rotate left    /   \
*     30     50 (+1)   ---------->            50(1)        -------------->  40(0) 100(0)
*            \                                 \
*            100                               100
*
**/
void test_remove_rotateleft1(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node100,NULL,NULL,0);
    initNode(&node50,NULL,&node100,1);
    initNode(&node40,&node30,&node50,1);

    Node *root = &node40;
    Try{
    avlRemoveInteger(&root,30);
    }
    Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
}
/*
  NULL      --->        1       --->        1         --->          25        (continue below...)
           add 1              add 25        \         add 40      /  \
                                            25                  1    40

 --->         25               --->          25
 add 50     /   \             add 55        / \
          1     40                        1   50
                 \                            / \
                 50                         40  55

Then remove (40)        ---->               25
        25              remove 55          / \
      /  \                               1   50
     1   50
          \
          55
*/
void test_remove_and_add_with_one_by_one_add_and_then_remove(void){
  initNode(&node1,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);

  Node *root = NULL;
  avlAddInteger(&root,&node1);
  avlAddInteger(&root,&node25);
  avlAddInteger(&root,&node40);
  avlAddInteger(&root,&node50);
  avlAddInteger(&root,&node55);

  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
  //TEST_ASSERT_EQUAL_PTR(&node1,node25.left);
  //TEST_ASSERT_EQUAL_PTR(&node50,node25.right);
  TEST_ASSERT_EQUAL_NODE(&node1,&node50,1,&node25);

  avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_NODE(&node1,&node50,1,&node25);
  TEST_ASSERT_EQUAL_NODE(NULL,&node55,1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);

  avlRemoveInteger(&root,55);
  TEST_ASSERT_EQUAL_NODE(&node1,&node50,0,&node25);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1);
}

void test_functional_test(void){
  initNode(&node1,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node60,NULL,NULL,0);
  initNode(&node65,NULL,NULL,0);
  initNode(&node75,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node90,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);
  initNode(&node120,NULL,NULL,0);
  initNode(&node150,NULL,NULL,0);
  initNode(&node200,NULL,NULL,0);
  initNode(&node250,NULL,NULL,0);
  Node *root = NULL;
  avlAddInteger(&root,&node1);
  avlAddInteger(&root,&node25);
  avlAddInteger(&root,&node40);
  avlAddInteger(&root,&node50);
  avlAddInteger(&root,&node55);
  avlAddInteger(&root,&node60);
  avlAddInteger(&root,&node65);
  avlAddInteger(&root,&node75);
  avlAddInteger(&root,&node80);
  avlAddInteger(&root,&node90);
  avlAddInteger(&root,&node100);
  avlAddInteger(&root,&node120);
  avlAddInteger(&root,&node150);
  avlAddInteger(&root,&node200);
  avlAddInteger(&root,&node250);

  TEST_ASSERT_EQUAL_PTR(&node75,root);
  TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(&node150,&node250,0,&node200);
  TEST_ASSERT_EQUAL_NODE(&node25,&node60,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node1,&node40,0,&node25);
  TEST_ASSERT_EQUAL_NODE(&node55,&node65,0,&node60);

  avlRemoveInteger(&root,60);
  TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(&node150,&node250,0,&node200);
  TEST_ASSERT_EQUAL_NODE(&node25,&node65,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node1,&node40,0,&node25);
  //TEST_ASSERT_EQUAL_PTR(&node55,node65.left);
  //TEST_ASSERT_EQUAL_PTR(&node65,node65.right);
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);

  avlRemoveInteger(&root,150);
  TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(&node25,&node65,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node1,&node40,0,&node25);
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);

  avlRemoveInteger(&root,25);
  TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(&node40,&node65,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);

  avlRemoveInteger(&root,90);
  TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node100,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(&node80,NULL,-1,&node100);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(&node40,&node65,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);

  avlRemoveInteger(&root,100);
  TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
  TEST_ASSERT_EQUAL_PTR(&node80,node120.left);
  TEST_ASSERT_EQUAL_PTR(&node200,node120.right);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_NODE(&node80,&node200,1,&node120);
  TEST_ASSERT_EQUAL_NODE(&node40,&node65,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);

  avlRemoveInteger(&root,50);
  TEST_ASSERT_EQUAL_NODE(&node55,&node120,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node80,&node200,1,&node120);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(&node40,&node65,-1,&node55);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);

  avlRemoveInteger(&root,75);
  TEST_ASSERT_EQUAL_PTR(&node80,root);
  TEST_ASSERT_EQUAL_NODE(&node55,&node200,-1,&node80);
  TEST_ASSERT_EQUAL_NODE(&node120,&node250,0,&node200);
  TEST_ASSERT_EQUAL_NODE(&node40,&node65,-1,&node55);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);

  avlRemoveInteger(&root,55);
  TEST_ASSERT_EQUAL_NODE(&node40,&node200,0,&node80);
  TEST_ASSERT_EQUAL_NODE(&node120,&node250,0,&node200);
  TEST_ASSERT_EQUAL_NODE(&node1,&node65,0,&node40);

  avlRemoveInteger(&root,80);
  TEST_ASSERT_EQUAL_PTR(&node120,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(&node1,&node65,0,&node40);

  avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_NODE(&node65,&node200,0,&node120);
  TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node65);

  avlRemoveInteger(&root,200);
  TEST_ASSERT_EQUAL_NODE(&node65,&node250,-1,&node120);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node65);

  avlRemoveInteger(&root,250);
  TEST_ASSERT_EQUAL_PTR(&node65,root);
  TEST_ASSERT_EQUAL_NODE(&node1,&node120,0,&node65);

  avlRemoveInteger(&root,65);
  TEST_ASSERT_EQUAL_PTR(&node120,root);
  TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node120);

  avlRemoveInteger(&root,120);
  TEST_ASSERT_EQUAL_PTR(&node1,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node1);

  avlRemoveInteger(&root,1);
  TEST_ASSERT_EQUAL_PTR(NULL,root);
}
