//
//  BSTreeNode.h
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#ifndef BSTreeNode_h
#define BSTreeNode_h
#include <iostream>
using namespace std;

template <typename T>
class BSTreeNode{
private:
    T data;
    BSTreeNode<T> *left;
    BSTreeNode<T> *right;
    BSTreeNode<T> *parent; //not really needed, but useful maybe
public:
    BSTreeNode(const T &item); //custom ctor
    BSTreeNode(const BSTreeNode<T> &rhs);

    ~BSTreeNode();
    const BSTreeNode<T>& operator =(const BSTreeNode<T> &rhs);
    void Insert(const T &item);
    void InsertAVL(const T &item);
    bool Search(const T &item);
    void Remove(const T &item);
    //BSTreeNode<T> * search(const T &data);
    void print();
    void ComputeACE(double &count, int level);
    int ComputeMAX(int &level);

    
};

#endif /* BSTreeNode_h */
