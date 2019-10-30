//
//  main.cpp
//  Triangle
//
//  Created by Spencer on 1/20/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>

int main() {
    // insert code here...
    using namespace std;
    double base, height, area;
    cout << "This program computes the area of a triangle." << endl << endl;
    cout << "Enter the base of the triangle: "; cin >> base;
    cout << "Enter the height of the triangle: "; cin >> height;
    cout << std::endl;

    area = (base * height)/2;
    cout << "The area is " << area << std::endl;
    
    return 0;
}

