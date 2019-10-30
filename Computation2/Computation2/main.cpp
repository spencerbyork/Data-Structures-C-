//
//  main.cpp
//  Computation2
//
//  Created by Spencer on 1/23/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#include <iostream>
using namespace std;

int flip(int num){
    int temp = num;
    int flipped = 0;
    int rem = 1;
    
    while (temp!=0){
        rem = temp%10;
        flipped = (flipped*10) + rem;
        temp = temp/10;
    }
    
    return flipped;
}

int main() {
    int num;
    cout << "This program reverses the digits of an integer." << endl;
    cout << endl;
    
    cout << "Enter an integer: ";
    cin >> num;
    cout << endl;

    num = flip(num);

    cout << "The reversed number is " << num << ".";

    return 0;
}

