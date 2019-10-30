//
//  p2stack1.h
//  Stack
//
//  Created by Spencer on 2/13/19.
//  Copyright © 2019 Spencer. All rights reserved.
//

#ifndef p2stack1_h
#define p2stack1_h
#include <iostream>
#include <string>
#include<cstddef>
using namespace std;


template<class T>
struct Stack
{
    T* data;
    int top;
    int size;

};

                    //INITIALIZE
template <class T>
    void initialize(Stack<T>& Stack)
    {
        Stack.size = 2;
        Stack.data = new T[Stack.size];
        Stack.top = 0;
    }
                    //PUSH FUNCTION
template <class T>
    void push(Stack<T>& Stack,T item)
    {
        if(Stack.top >= Stack.size)
        {
            Stack.size = Stack.size * 2;

            T* temp = new T[Stack.size];
            for(int i = 0; i < Stack.size/2; i++){
                temp[i] = Stack.data[i];
            }
            delete[] Stack.data;
            Stack.data = temp;
            Stack.data[Stack.top] = item;
            Stack.top++;
        }
        else{
        Stack.data[Stack.top] = item;
        Stack.top++;

        }
    }

                    //POP FUNCTION
template <class T>
    T pop(Stack<T>& Stack)
    {
        
        T temp = Stack.data[Stack.top-1];

        Stack.top--;
        
        return temp;
    }

                    //DESTROY FUNCTION
template <class T>
void destroy(Stack<T>& Stack)
{

    delete[] Stack.data;
    Stack.data = NULL;
    Stack.size = 0;
    Stack.top = 0;

}

template <class T>
bool isEmpty(Stack<T> Stack)
{
    if(Stack.top == 0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void printStack(Stack<T>& Stack)
{
    for (int count = 0; count < Stack.size; count++)
        cout << Stack.data[count];
}



#endif /* p2stack1_h */
