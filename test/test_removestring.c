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
  initStrData();
}

void tearDown(void)
{
}
/*
        Cristiano          -->        NULL
                          remove
                       "Cristiano"
*/
void test_remove_cristiano(void)
{
  initStringNode(&nodeCristiano,NULL,NULL,0);

  StringNode *root = &nodeCristiano;
  Try{
  avlRemoveString(&root,"Cristiano");
  }
  Catch(ex){
  dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(NULL,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeCristiano);
}
/*
      Messi                                     Rooney
    /        \              ---->               /   \
  Cristiano  VanPersie      remove            Messi VanPersie
              /           "Cristiano"
            Rooney
*/
void test_insert_string_one_by_one_and_then_remove(void)
{
  initStringNode(&nodeVanPersie,NULL,NULL,0);
  initStringNode(&nodeCristiano,NULL,NULL,0);
  initStringNode(&nodeMessi,NULL,NULL,0);
  initStringNode(&nodeRooney,NULL,NULL,0);

  StringNode *root = NULL;
  avlAddString(&root,&nodeMessi);
  avlAddString(&root,&nodeCristiano);
  avlAddString(&root,&nodeVanPersie);
  avlAddString(&root,&nodeRooney);

  TEST_ASSERT_EQUAL_PTR(&nodeMessi,root);
  TEST_ASSERT_EQUAL_NODE(&nodeCristiano,&nodeVanPersie,1,&nodeMessi);
  TEST_ASSERT_EQUAL_NODE(&nodeRooney,NULL,-1,&nodeVanPersie);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeCristiano);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeRooney);

  avlRemoveString(&root,"Cristiano");
  TEST_ASSERT_EQUAL_PTR(&nodeRooney,root);
  TEST_ASSERT_EQUAL_NODE(&nodeMessi,&nodeVanPersie,0,&nodeRooney);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeVanPersie);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeMessi);
}
