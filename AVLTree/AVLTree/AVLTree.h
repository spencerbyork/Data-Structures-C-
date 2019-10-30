//
//  AVLTree.h
//  AVLTree
//
//  Created by Spencer on 4/1/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h
#include <iostream>
struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
}*root;


// Class Declaration

class avlTree
{
public:
    int AVLheight(avl_node *);
    int AVLdiff(avl_node *);
    avl_node *AVLrr_rotation(avl_node *);
    avl_node *AVLll_rotation(avl_node *);
    avl_node *AVLlr_rotation(avl_node *);
    avl_node *AVLrl_rotation(avl_node *);
    avl_node* AVLbalance(avl_node *);
    avl_node* AVLinsert(avl_node *, int );
    void AVLdisplay(avl_node *, int);
    void AVLinorder(avl_node *);
    void AVLpreorder(avl_node *);
    void AVLpostorder(avl_node *);
    avlTree()
    {
        root = NULL;
    }
};

#endif /* AVLTree_h */
