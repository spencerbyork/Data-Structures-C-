//
//  AVLTree.hpp
//  AVLTree
//
//  Created by Spencer on 3/31/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "AVLTreeNode.hpp"

#define pow2(n) (1 << (n))

#include <stdio.h>


// Class Declaration

class avlTree
{
public:
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node* balance(avl_node *);
    avl_node* insert(avl_node *, int );
    void display(avl_node *, int);
    void inorder(avl_node *);
    void preorder(avl_node *);
    void postorder(avl_node *);
    int computeACE(avl_node *, double &count, int level);
    int computeMax(avl_node *);
    avlTree()
    {
        root = NULL;
    }
};
#endif /* AVLTree_hpp */
