#include <iostream>
#include "p2stack1.h"
using namespace std;

int main()
{
    cout << "** DYNAMIC (char) STACK! **\n\n";
    
    Stack<char> s;
    initialize(s);
    
    string command;
    char value;
    while(true)
    {
        cin >> command;
        
        if( command == "Quit" )
            break;
        
        if( command == "Push" )
        {
            cin >> value;
            push(s,value);
        }
        
        if( command == "Pop" )
        {
            if( isEmpty(s) )
                cout << "Stack empty\n";
            else
                cout << ">> " << pop(s) << endl;
        }
        if( command == "Print" )
        {
            if( isEmpty(s) )
                cout << "Stack empty\n";
            else
                printStack(s);
        }
    }
    destroy(s);
}
