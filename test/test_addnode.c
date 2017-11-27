#include "unity.h"
#include "rotate.h"
#include <stdio.h>
#include "addnode.h"

Node node1,node5,node10,node15,node20,node25,node30,node35,node40;
Node node45,node50,node55;
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
}

void tearDown(void)
{
}

/**
----------------test_insert_right----------
*        20            20
*         \           /   \
*          30  ->   10    30
*
**/
void test_insert_right(void)
{
    Node *root = &node20;
    initNode(&node20,NULL,&node30,1);

    addNode(&root,&node10);
    TEST_ASSERT_EQUAL_PTR(&node20,root);
    TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node20.right);

}

/*      _______________________________________________________________________________________
   *     |_Current_Node_|__Child_Node_| G.Child_Node |________Action________|_Root_|_Child_|_G.Child_|
   *     |_______+2_____|_(R)__+1_____|______X_______|________Rotate_Left___|___0__|___0___|____X____|
   *     |_______+2_____|_(R)___0_____|______X_______|________Rotate_Left___|__-1__|___1___|____X____|
   *     |_______+2_____|_(R)__-1_____|_____-1_______|___Rotate_RightLeft___|___0__|___1___|____0____|
   *     |_______+2_____|_(R)__-1_____|______0_______|___Rotate_RightLeft___|___0__|___0___|____0____|
   *     |_______+2_____|_(R)__-1_____|_____+1_______|___Rotate_RightLeft___|__-1__|___0___|____0____|
   *     |_______-2_____|_(L)__-1_____|______X_______|________Rotate_Left___|___0__|___0___|____X____|
   *     |_______-2_____|_(L)___0_____|______X_______|________Rotate_Left___|___1__|__-1___|____X____|
   *     |_______-2_____|_(L)__+1_____|_____+1_______|___Rotate_LeftRight___|___0__|__-1___|_________|
   *     |_______-2_____|_(L)__+1_____|______0_______|___Rotate_LeftRight___|___0__|___0___|____X____|
   *     |_______-2_____|_(L)__+1_____|_____-1_______|___Rotate_LeftRight___|___1__|___0___|____0____|
   *
   *
   */
