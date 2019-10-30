//
//  main.cpp
//  BSTree
//
//  Created by Spencer on 3/10/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#include "BSTreeNode.cpp"
#include "BSTree.cpp"
using namespace std;

int main() {
    
    BSTree<double> doubleTree;

    doubleTree.Insert(77);
    doubleTree.Insert(29);
    doubleTree.Insert(23);
    doubleTree.Insert(19);
    doubleTree.Insert(37);
    doubleTree.Insert(43);
    
    doubleTree.ComputeACE();
    doubleTree.ComputeMAX();
    doubleTree.Clear();
    doubleTree.ComputeMAX();
    doubleTree.Print();
    //add more code here to test tree!!!!
    
}
