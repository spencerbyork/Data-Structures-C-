//
//  BSTree.cpp
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include "BSTree.h"
using namespace std;

//Constructor Function
template <typename T>
BSTree<T>::BSTree(){
    myRoot = NULL;
}

//Destructor Function
template <typename T>
BSTree<T>::~BSTree(){
    delete myRoot;
    myRoot = NULL;
}

//Clear Function (same as Destructor)
template <typename T>
void BSTree<T>::Clear(){
    delete myRoot;
    myRoot = NULL;
    
}

//Honestly Not sure what this does
template <typename T>
BSTree<T>::BSTree(const BSTree<T> &rhs) : myRoot(NULL){
    if(!rhs.isEmpty()){
        myRoot = new BSTreeNode<T>(*rhs.myRoot);
    }
}

//IsEmpty Function
template <typename T>
bool BSTree<T>::isEmpty(){
    if(myRoot != NULL){
        return false;
    }
    else{
        return true;
    }
}

//Insert Function
template <typename T>
void BSTree<T>::Insert(const T &data){
    if(myRoot != NULL){
        myRoot->Insert(data);
    }
    else{
        myRoot = new BSTreeNode<T>(data);
    }
}

//Search Function
template <typename T>
bool BSTree<T>::Search(const T &data){
    if(isEmpty()){
        return false;
    }
    else{
        return myRoot->Search(data);
        
    }
}

//InOrder Print Function
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
    std::cout << endl;
}

//ComputeACE Function
template <typename T>
double BSTree<T>::ComputeACE(){
    double count = 0;
    int nodes = 0;
    int level = 1;
    if(isEmpty()){
        std::cout << count << endl;
        return count;
    }
    else{
        count = 1;
        nodes++;
        myRoot->ComputeACE(count, level, nodes);
    }
    count = count/nodes;
    std::cout << count << endl;
    return count;
};

//ComputeMAX Function
template <typename T>
int BSTree<T>::ComputeMAX(){
    int h = 0;
    h = myRoot->Height();
    std::cout << h << endl;
    return h;
};

//Height Function
template <typename T>
int BSTree<T>::height(){
    int h = 0;
    h = myRoot->Height();
    std::cout << h << endl;
    return h;
};

//Difference Function
template <typename T>
int BSTree<T>::diff(){
    int b_factor = 0;
    b_factor = myRoot->Diff();
    std::cout << b_factor << endl;
    return b_factor;
};

template <typename T>
void BSTree<T>::printDOT(){
    std::cout << std::endl;
    std::cout << std::endl;
    if(myRoot == NULL){
        std::cout << "digraph myGraph {}";
    }
    else{
        std::cout << "digraph myGraph {";
        myRoot->printDOT();
        std::cout << "}" << std::endl;
        
    }
};

//PreOrder Print Function
template <typename T>
void BSTree<T>::PrePrint(){
    //This funciton uses InOrder Traversal for printing
    //PreOrder  -> Self, Left, then Right
    //InOrder   -> Left, Self, then Right
    //PostOrder -> Left, Right, then Self
    if(myRoot != NULL){
        myRoot->prePrint();
        //myRoot->Print(INORDER)
    }
    std::cout << endl;
};

//PreOrder Print Function
template <typename T>
void BSTree<T>::PostPrint(){
    //This funciton uses InOrder Traversal for printing
    //PreOrder  -> Self, Left, then Right
    //InOrder   -> Left, Self, then Right
    //PostOrder -> Left, Right, then Self
    if(myRoot != NULL){
        myRoot->postPrint();
        //myRoot->Print(INORDER)
    }
    std::cout << endl;
};

//Balance Function

