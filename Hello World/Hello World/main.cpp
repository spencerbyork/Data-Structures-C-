//
//  main.cpp
//  Hello World
//
//  Created by Spencer on 1/11/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
int add2numbers(int a, int b);

int main(int argc, const char * argv[]) {

    int a;
    int b = 10;
    
    int c;
    c = a + b;
    
    c = add2numbers(a,b);
    
    
    std::cout << "Value of variable named c is " << c << std::endl;
    return 0;
}

int add2numbers(int a, int b)
{
    return a + b;
}

