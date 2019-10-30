//
//  main.cpp
//  AVLTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//
#include "AVLTree.h"
#include "BSTreeNode.cpp"
#include "BSTree.cpp"
using namespace std;



int main() {
    
    BSTree<double> doubleTree;
    
    int nums [30] = {77, 29, 23, 19, 37, 43, 26, 55, 36, 16, 21, 23, 24, 7, 51, 20, 2, 9, 13, 87, 52, 86, 21, 15, 29, 6, 54, 55, 77, 88};
    
    for(int i = 0; i < 30; i++){
       doubleTree.Insert(nums[i]);
        }
    cout << "Non-balanced PreOrder:" << endl;
    doubleTree.PrePrint();
    cout << "Non-balanced PreOrder:" << endl;
    doubleTree.PostPrint();
    cout << "Non-balanced InOrder:" << endl;
    doubleTree.Print();

    cout << endl;

    
    avlTree avl;
    for(int i = 0; i < 30; i++){
        root = avl.AVLinsert(root, nums[i]);
    }
    cout << "AVL PreOrder:" << endl;
    avl.AVLpreorder(root);
    cout << endl;
    cout << "AVL PostOrder:" << endl;
    avl.AVLpostorder(root);
    cout << endl;
    cout << "AVL InOrder:" << endl;
    avl.AVLinorder(root);
    cout << endl;
    
    cout << "Non-balanced ComputeACE:" << endl;

    
}


int avlTree::AVLheight(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = AVLheight (temp->left);
        int r_height = AVLheight (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}


// Height Difference

int avlTree::AVLdiff(avl_node *temp)
{
    int l_height = AVLheight (temp->left);
    int r_height = AVLheight (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}


// Right-Right Rotation

avl_node *avlTree::AVLrr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation

avl_node *avlTree::AVLll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


// Left - Right Rotation

avl_node *avlTree::AVLlr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = AVLrr_rotation (temp);
    return AVLll_rotation (parent);
}


// Right- Left Rotation

avl_node *avlTree::AVLrl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = AVLll_rotation (temp);
    return AVLrr_rotation (parent);
}


// Balancing AVL Tree

avl_node *avlTree::AVLbalance(avl_node *temp)
{
    int bal_factor = AVLdiff (temp);
    if (bal_factor > 1)
    {
        if (AVLdiff (temp->left) > 0)
            temp = AVLll_rotation (temp);
        else
            temp = AVLlr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (AVLdiff (temp->right) > 0)
            temp = AVLrl_rotation (temp);
        else
            temp = AVLrr_rotation (temp);
    }
    return temp;
}


// Insert Element into the tree

avl_node *avlTree::AVLinsert(avl_node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = AVLinsert(root->left, value);
        root = AVLbalance (root);
    }
    else if (value >= root->data)
    {
        root->right = AVLinsert(root->right, value);
        root = AVLbalance (root);
    }
    return root;
}


// Display AVL Tree

void avlTree::AVLdisplay(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        AVLdisplay(ptr->right, level + 1);
        printf("n");
        if (ptr == root)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        AVLdisplay(ptr->left, level + 1);
    }
}


// Inorder Traversal of AVL Tree

void avlTree::AVLinorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    AVLinorder (tree->left);
    cout<<tree->data<<"  ";
    AVLinorder (tree->right);
}

// Preorder Traversal of AVL Tree

void avlTree::AVLpreorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    AVLpreorder (tree->left);
    AVLpreorder (tree->right);
    
}


//  Postorder Traversal of AVL Tree

void avlTree::AVLpostorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    AVLpostorder ( tree ->left );
    AVLpostorder ( tree ->right );
    cout<<tree->data<<"  ";
}




