#ifndef HuffmanBinaryTree_H
#define HuffmanBinaryTree_H

typedef struct HuffmanTree HuffmanTree;
struct HuffmanTree{
  char runAndCategory;
  HuffmanTree *leftChild;
  HuffmanTree *rightChild;
};

HuffmanTree createNodes(HuffmanTree *rootNode, HuffmanTree *nodeAddLeft, HuffmanTree *nodeAddRight);

#endif // HuffmanBianryTree_H
