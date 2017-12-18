#include "unity.h"
#include "rotate.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include "removenode.h"
#include "avlcompare.h"

void setUp(void)
{
  initStrData();
}

void tearDown(void)
{
}

void test_remove_cristiano(void)
{
  initStringNode(&nodeCristiano,NULL,NULL,0);

  StringNode *root = &nodeCristiano;
  avlRemoveString(&root,"Cristiano");
  TEST_ASSERT_EQUAL_PTR(NULL,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeCristiano);
}
