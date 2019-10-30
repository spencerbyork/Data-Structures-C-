//
//  main.cpp
//  Arrays
//
//  Created by Spencer on 1/28/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>

#define ARRSIZE 10

unsigned int arr[ARRSIZE];

typedef struct{
    float x;
    float y;
    float z;
    bool viz;
    int value;
} Point3D;

int main() {

    std::cout << "Hello, World!\n";
    
    for(int i=0; i<10; i++){
        arr[i] = 10;
    }
    arr[5] = 100;
    
    Point3D p1;
    
    p1.x = 13;
    p1.y = 100;
    p1.z = 3452.54;
    p1.viz = true;
    p1.value = 101;
    
    
    std::cout << "The size of p1 is: " << sizeof(p1) << " bytes" << std::endl;
    
    return 0;
}
