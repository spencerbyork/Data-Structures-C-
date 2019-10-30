//
//  main.cpp
//  pointers
//
//  Created by Spencer on 2/13/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#define LOG(x) std::cout << x << std::endl

void IncrementByPoint(int* value){
    (*value)++;
}

void IncrementByRef(int& value){
    value++;
}
int main() {
    
    int a = 5;
    int& ref = a;
    ref = 7;
    int* ptr = &a;
    IncrementByPoint(ptr);
    IncrementByRef(a);

    LOG(a);
    
    // insert code here...
    return 0;
}
