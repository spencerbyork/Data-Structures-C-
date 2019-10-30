//
//  AVLTreeNode.hpp
//  AVLTree
//
//  Created by Spencer on 3/31/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#ifndef AVLTreeNode_hpp
#define AVLTreeNode_hpp


#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>

#define pow2(n) (1 << (n))

#include <stdio.h>

struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root;

#endif /* AVLTree_hpp */

