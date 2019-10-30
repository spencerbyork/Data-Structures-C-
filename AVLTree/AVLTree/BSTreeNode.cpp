//
//  BSTreeNode.cpp
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

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

//Insert Function
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

//Search Function
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

//I honestly don't know what this is for -- (Class work)
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

//Print Function
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


//ComputeACE Function
template <typename T>
void BSTreeNode<T>::ComputeACE(double &count, int level, int &nodes){
    if (left != NULL){
        count += level + 1;
        nodes++;
    }
    if (right != NULL){
        count += level + 1;
        nodes++;
    }
    if (left != NULL || right != NULL){
        if (left != NULL){
            int tmp = level+1;
            left->ComputeACE(count, tmp, nodes);
        }
        if (right != NULL){
            int tmp = level+1;
            right->ComputeACE(count, tmp, nodes);
        }
    }
};

//ComputeMax Function
template <typename T>
int BSTreeNode<T>::ComputeMAX(int &level){
    int l_height = 0;
    int r_height = 0;
    int h = 0;
    if (left != NULL){
        l_height = left->Height();
    }
    if(right != NULL){
        r_height = right->Height();
    }
    int max_height = max(l_height, r_height);
    h = max_height + 1;
    return h;
};

//Height Function
template <typename T>
int BSTreeNode<T>::Height(){
    int l_height = 0;
    int r_height = 0;
    int h = 0;
    if (left != NULL){
        l_height = left->Height();
    }
    if(right != NULL){
        r_height = right->Height();
    }
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    return h;
};

//Difference Function
template <typename T>
int BSTreeNode<T>::Diff(){
    int l_height = 0;
    int r_height = 0;
    if (left != NULL){
        l_height = left->Height();
    }
    if(right != NULL){
        r_height = right->Height();
    }
    int b_factor = (l_height - r_height);
    return b_factor;
};

//Print DOT Function
template <typename T>
void BSTreeNode<T>::printDOT(){
    if(left != NULL){
        std::cout << "\"" << data << "\" -> \"" << left->data << "\"";
        std::cout << std::endl;
        left->printDOT();
        
    }
    if(right != NULL){
        std::cout << "\"" << data << "\" -> \"" << right->data << "\"";
        std::cout << std::endl;
        right->printDOT();
        
    }
};

//PrePrint Function
template <typename T>
void BSTreeNode<T>::prePrint(){
    //PreOrder traversal
    
    //print self
    std::cout << data << " ";
    
    //print left
    if (left != NULL){
        left->prePrint();
    }
    
    //print right
    if(right != NULL){
        right->postPrint();
    }
};

//PostPrint Function
template <typename T>
void BSTreeNode<T>::postPrint(){
    //PostOrder traversal
    
    //print left
    if (left != NULL){
        left->postPrint();
    }
    //print right
    if(right != NULL){
        right->postPrint();
    }
    //print self
    std::cout << data << " ";
};


