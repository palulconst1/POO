#include <iostream>
#include "stackClass.h"

int main()
{
    Stack a;
    cin>>a>>a;
    a.push('H');
    a.reverseStack();
    cout<<a;
    a.pop();
    cout<<a;
    cout<<a.peek();
    Stack s;
    s.push('P');
    s.push('O');
    s.push('O');
    s.push('L');
    s.push('A');
    s.push('B');
    s.push('O');
    s.push('R');
    s.push('A');
    s.push('T');
    s.push('O');
    s.push('R');

    Stack p;
    p.push('E');
    p.push('X');
    p.push('A');
    p.push('M');
    p.push('E');
    p.push('N');


    Stack sol = s-p;
    sol.reverseStack();
    cout<<"Stiva 1 - Stiva 2 = "<<sol;
    s.~Stack();
    p.~Stack();

}
