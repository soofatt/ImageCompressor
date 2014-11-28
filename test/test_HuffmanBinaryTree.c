#include "unity.h"
#include "HuffmanBinaryTree.h"

void setUp(void){}

void tearDown(void){}

void test_createNodes_given_a_root_should_create_empty_left_and_right_childs(void){
	HuffmanTree root = {.runAndSize = 0, .leftChild = NULL, .rightChild = NULL};
	HuffmanTree leftNode = {.runAndSize = 0x00, .leftChild = NULL, .rightChild = NULL};
	HuffmanTree rightNode = {.runAndSize = 0x00, .leftChild = NULL, .rightChild = NULL};
	HuffmanTree addNode = {.runAndSize = 0x00, .leftChild = NULL, .rightChild = NULL};
  
  createNodes(&root, &leftNode, &rightNode);
  
  TEST_ASSERT_EQUAL(&leftNode, root.leftChild);
  TEST_ASSERT_EQUAL(&rightNode, root.rightChild);
  TEST_ASSERT_EQUAL(0x00, root.leftChild->runAndSize);
  TEST_ASSERT_EQUAL(0x00, root.rightChild->runAndSize);
  
  createNodes(&leftNode, &addNode, &addNode);
  
  TEST_ASSERT_EQUAL(&addNode, leftNode.leftChild);
  TEST_ASSERT_EQUAL(&addNode, leftNode.rightChild);
  TEST_ASSERT_EQUAL(0x00, leftNode.leftChild->runAndSize);
  TEST_ASSERT_EQUAL(0x00, leftNode.rightChild->runAndSize);
}
