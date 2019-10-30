//
//  main.cpp
//  pointers
//
//  Created by Spencer on 2/13/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
#define LOG(x) std::cout << x << std::endl

int main() {
    
    float var = 8.56;
    float* ptr = &var;
    *ptr = 10.345;
    LOG(var);
    
    int arr[10];
    int* point = &arr[3];
    *point = 4;
    
    // insert code here...
    return 0;
}
