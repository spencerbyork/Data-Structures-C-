//
//  BSTree.cpp
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#include "BSTree.h"
using namespace std;

template <typename T>
BSTree<T>::BSTree(){
    myRoot = NULL;
}


template <typename T>
BSTree<T>::~BSTree(){
    delete myRoot;
    myRoot = NULL;
}

template <typename T>
void BSTree<T>::Clear(){
    delete myRoot;
    myRoot = NULL;
    
}

template <typename T>
BSTree<T>::BSTree(const BSTree<T> &rhs) : myRoot(NULL){
    if(!rhs.isEmpty()){
        myRoot = new BSTreeNode<T>(*rhs.myRoot);
    }
}

template <typename T>
bool BSTree<T>::isEmpty(){
    if(myRoot != NULL){
        return false;
    }
    else{
        return true;
    }
}

template <typename T>
void BSTree<T>::Insert(const T &data){
    if(myRoot != NULL){
        myRoot->Insert(data);
    }
    else{
        myRoot = new BSTreeNode<T>(data);
    }
}

template <typename T>
bool BSTree<T>::Search(const T &data){
    if(isEmpty()){
        return false;
    }
    else{
        return myRoot->Search(data);

    }
}

template <typename T>
void BSTree<T>::Print(){
    //This funciton uses InOrder Traversal for printing
                //PreOrder  -> Self, Left, then Right
                //InOrder   -> Left, Self, then Right
                //PostOrder -> Left, Right, then Self
    if(myRoot != NULL){
        myRoot->print();
        //myRoot->Print(INORDER)
    }
}

template <typename T>
double BSTree<T>::ComputeACE(){
    double count = 0;
    int level = 1;
    if(isEmpty()){
        std::cout << count << endl;
        return count;
    }
    else{
        count = 1;
        myRoot->ComputeACE(count, level);
        }
    std::cout << count << endl;
    return count;
};

template <typename T>
int BSTree<T>::ComputeMAX(){
    int level = 0;
    if(isEmpty()){
        std::cout << level << endl;
        return level;
    }
    else{
        myRoot->ComputeMAX(level);
    }
    std::cout << level << endl;
    return level;
};
