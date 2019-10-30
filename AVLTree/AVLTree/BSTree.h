//
//  BSTree.h
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h
#include <iostream>
#include "BSTreeNode.h"
using namespace std;

template <typename T>
class BSTree{
private:
    BSTreeNode<T> *myRoot;
public:
    BSTree();
    ~BSTree();
    BSTree(const BSTree<T> &rhs);
    const BSTree<T> &operator = (const BSTree<T> &rhs);
    
    bool isEmpty();
    void Insert(const T& data);
    bool Search(const T& data);
    void Clear();
    double ComputeACE();
    int ComputeMAX();
    int height();
    int diff();
    
    void Print(); //InOrder, PreOrder, or PostOrder
    void PrePrint();
    void PostPrint();
    void printDOT();
    
 
};

#endif /* BSTree_h */
