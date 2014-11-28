#include "HuffmanBinaryTree.h"

void createNodes(HuffmanTree *rootNode, HuffmanTree *nodeAddLeft, HuffmanTree *nodeAddRight){
  rootNode->leftChild = nodeAddLeft;
  rootNode->rightChild = nodeAddRight;
  
}