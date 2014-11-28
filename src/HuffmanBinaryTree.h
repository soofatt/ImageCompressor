#ifndef HuffmanBinaryTree_H
#define HuffmanBinaryTree_H

typedef struct HuffmanTree HuffmanTree;
struct HuffmanTree{
  char runAndSize;
  HuffmanTree *leftChild;
  HuffmanTree *rightChild;
};

void createNodes(HuffmanTree *rootNode, HuffmanTree *nodeAddLeft, HuffmanTree *nodeAddRight);

#endif // HuffmanBianryTree_H
