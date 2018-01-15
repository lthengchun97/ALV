#include "unity.h"
#include "rotate.h"
#include <stdio.h>
#include "addnode.h"
#include "rotate.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include "avlcompare.h"
#include "Exception.h"
#include "CException.h"

CEXCEPTION_T ex;
void setUp(void)
{
  initData();
  initStrData();
}

void tearDown(void)
{
}


   void test_compare_cristiano_with_cristiano_return_0(void)
   {
     char *Cristiano = "Cristiano";
     Node *nodeCr = (Node*)&nodeCristiano;
     TEST_ASSERT_EQUAL(0, stringCompare(Cristiano, nodeCr));
   }

   void test_compare_cristiano_with_messi_return_negative_1(void)
   {
     char *Cristiano = "Cristiano";
     Node *nodeMes = (Node*)&nodeMessi;
     TEST_ASSERT_EQUAL(-1, stringCompare(Cristiano, nodeMes));
   }

   void test_compare_rooney_with_messi_return_1(void)
   {
     char *Rooney = "Rooney";
     Node *nodeMes = (Node*)&nodeMessi;
     TEST_ASSERT_EQUAL(1, stringCompare(Rooney, nodeMes));
   }

   /**
   *        NULL       ->         VanPersie
   *
   *
   *
   **/
   void test_insert_van_persie(void)
   {

       initStringNode(&nodeVanPersie,NULL,NULL,0);

       Node *root = NULL;
       Try{
       avlAddString(&root,&nodeVanPersie);
      }
      Catch(ex){
      dumpException(ex);
      }
       //avlAddString(&root,&nodeRooney);
       TEST_ASSERT_EQUAL_PTR(&nodeVanPersie,root);
       TEST_ASSERT_EQUAL_PTR(NULL,nodeVanPersie.left);
       TEST_ASSERT_EQUAL_PTR(NULL,nodeVanPersie.right);
       TEST_ASSERT_EQUAL(0,nodeVanPersie.balanceFactor);
   }

   void test_insert_rooney(void)
   {
       initStringNode(&nodeVanPersie,NULL,NULL,0);

       StringNode *root = &nodeVanPersie;
       Try{
       avlAddString(&root,&nodeMessi);
      }
      Catch(ex){
      dumpException(ex);
      }
       TEST_ASSERT_EQUAL_PTR(&nodeVanPersie,root);
       TEST_ASSERT_EQUAL_PTR(&nodeMessi,nodeVanPersie.left);
       TEST_ASSERT_EQUAL_PTR(NULL,nodeVanPersie.right);
       TEST_ASSERT_EQUAL(-1,nodeVanPersie.balanceFactor);
   }
