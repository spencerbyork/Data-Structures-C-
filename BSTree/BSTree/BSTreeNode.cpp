//
//  BSTreeNode.cpp
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#include "BSTree.h"
#include "BSTreeNode.h"
using namespace std;

//Constructor
template<typename T>
BSTreeNode<T>::BSTreeNode(const T& item) : data(item), left(NULL), right(NULL){
    
}

template<typename T>
BSTreeNode<T>::BSTreeNode(const BSTreeNode<T> &rhs) : data(rhs.data), left(NULL), right(NULL){
    if(rhs.left!=NULL){
        left = new BSTreeNode<T>(*rhs.left);
    }
    if(rhs.right!=NULL){
        right = new BSTreeNode<T>(*rhs.right);
    }
}

template<typename T>
BSTreeNode<T>::~BSTreeNode(){
    delete left;
    delete right;
}

template <typename T>
void BSTreeNode<T>::Insert(const T& item){
    if (data == item){
        //do nothing
    }
    else{
        if (item < data){ //insert to the left
            if(left == NULL){
                left = new BSTreeNode<T>(item);
                left->parent = this;
            }
            else{
                left->Insert(item);
            }
        }
        else{ //Insert to the right
            if(right == NULL){
                right = new BSTreeNode<T>(item);
            }
            else{
                right->Insert(item);
            }
        }
    }
};

template <typename T>
bool BSTreeNode<T>::Search(const T& item){
    if(item==data){
        return true;
    }
    else if(data < item && left!= NULL){
        return left->Search(data); //recursion
    }
    else if(data > item && right!=NULL){
        return right->Search(data);
    }
    else{
        return false;
    }
};

template <typename T>
const BSTreeNode<T>& BSTreeNode<T>::operator=(const BSTreeNode<T> &rhs){
    
    //always check to make sure rhs is not this
    if(this != &rhs){
        //copy-swap idiom
        BSTreeNode<T> tmp(rhs);
        swap(data, tmp.data);
        swap(left, tmp.left);
        swap(right, tmp.right);
    }
    return *this;
};

template <typename T>
void BSTreeNode<T>::print(){
    //InOrder traversal
    
    //print left
    if (left != NULL){
        left->print();
    }
    
    //print self
    std::cout << data << " ";
    
    //print right
    if(right != NULL){
        right->print();
    }
};

template <typename T>
void remove(const T& item){
    
};

template <typename T>
void BSTreeNode<T>::ComputeACE(double &count, int level){
    if (left != NULL){
        count += level + 1;
    }
    if (right != NULL){
        count += level + 1;
    }
    if (left != NULL || right != NULL){
        if (left != NULL){
            int tmp = level+1;
            left->ComputeACE(count, tmp);
        }
        if (right != NULL){
            int tmp = level+1;
            right->ComputeACE(count, tmp);
        }
    }
};


template <typename T>
int BSTreeNode<T>::ComputeMAX(int &level){
    if (left != NULL && right != NULL){
            left->ComputeMAX(level);
            right->ComputeMAX(level);
        level++;
    }
    else if (left != NULL && right == NULL){
            left->ComputeMAX(level);
            level++;
    }
    else if (left == NULL && right != NULL){
        right->ComputeMAX(level);
        level++;
    }
    return 0.0;
};

