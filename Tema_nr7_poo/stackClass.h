#ifndef STACKCLASS_H_INCLUDED
#define STACKCLASS_H_INCLUDED

#include <stdexcept> // pt std::exception
#include <iostream>

using namespace std;

class Stack;

class Node
{
private:
    char info;
    Node* next;

public:
    friend class Stack; /// Trebuie sa fie friend pentru ca Stack sa poata modifica nodul top()

    Node(char val, Node* prev)  /// Constructor - CERINTA
    {
        info=val;
        next=prev;
    }

    ~Node() {} /// Destructor gol deoarece se dealoca din stack - CERINTA

    char head() const /// Returneaza head-ul la lista inlantuita
    {
        return info;
    }

    Node* tail() const
    {
        return next;
    }


};

class Stack
{
private:
    Node* top; /// Cerinta: " membru privat, un "Nod*" (varful stivei); "

    bool empty() const
    {
        return top == NULL; /// Daca elementul de sus al stivel e nul , se returneaza true
    }

    void freeNodes() /// Dezaloca noduri pt Destructorul de mai jos
    {
        while (empty()==false)
        {
            pop(); /// Scoatem dinamic elementul din stiva
        }
    }

public:
    Stack() : top() {} /// Constructor ce initializeaza nodul top

    ~Stack() /// Destructor / Sterge stiva si dezaloca memoria
    {
        freeNodes();
    }

    Stack(const Stack& other) : top()   /// Constructor de copiere
    {
        if (other.empty())
        {
            return;
        }

        top = new Node(*other.top);

        Node* otherNext = other.top->tail();
        Node* current = top;

        while (otherNext != NULL)
        {
            current->next = new Node(*otherNext);
            current = current->tail();
            otherNext = otherNext->tail();
        }
    }

    Stack& operator= (const Stack& other) /// Overload la operatorul = ( imi trebuie pentru eventualele copieri.)
    {
        if (this == &other)  /// Crash daca asignam aceeasi variabila: Stack a = a;
        {
            return *this;
        }

        try
        {
            if (other.empty())
            {
                freeNodes();
                top = NULL;
                return *this;
            }

            Node* newTop = new Node(*other.top);
            Node* otherNext = other.top->tail();
            Node* current = newTop;

            while (otherNext != NULL)
            {
                current->next = new Node(*otherNext); /// copiem nodul curent
                current = current->tail(); /// trecem la urmatorul nod
                otherNext = otherNext->tail();
            }
            freeNodes();
            top = newTop;
            return *this;
        }
        catch (...)
        {
            throw;
        }
    }

    void push(char); /// CERINTA , FUNCTIE DECLARATA MAI JOS
    char pop();
    char peek() const;
    int getSize() const;
    void reverseStack();
    friend ostream& operator<<(ostream& os, const Stack& printStack);
    friend istream& operator >> (istream &in, Stack& readStack);
    friend Stack operator - (Stack const &, Stack const &);

};

Stack operator - (Stack const &s1, Stack const &s2)
{
     Stack tmpResult;
     Stack tmp1 = s1;
     Stack tmp2 = s2;
     while(tmp1.getSize()>0 && tmp2.getSize()>0)
     {
        if((int)tmp1.peek()>(int)tmp2.peek())
            tmpResult.push(tmp1.peek());
        else
            tmpResult.push(tmp2.peek());
        tmp1.pop();
        tmp2.pop();

     }

     return tmpResult;
}

 ostream& operator<<(ostream& os, const Stack& printStack)
{

        Stack tmpStack = printStack;
        int tmpSize = printStack.getSize();
        for (int i=0; i < tmpSize; i ++)
        {
            os<<tmpStack.peek();
            tmpStack.pop();
        }
        os << "\n";
        return os;
}

istream & operator >> (istream &in,  Stack &readStack)
{
    char x;
    cin>>x;
    readStack.push(x);
}

int Stack::getSize() const
{
    if (empty())
    {
        return 0;
    }
    int i = 0;
    for (Node* cur = top; cur != NULL; cur = cur->next, ++i) {}
    return i;
}

void Stack::push(char value)
{
    Node* currentTop = top;
    top = new Node(value, currentTop);
}


void Stack::reverseStack()
{

    Stack tmpStack;
    while((*this).getSize()>0)
    {
        char tmpValue = (*this).peek();
        tmpStack.push(tmpValue);
        (*this).pop();
    }

   (*this) = tmpStack;
}

char Stack::peek() const
{
    if (empty())
    {
        throw std::exception(); /// Daca e goala returneaza exceptie in loc sa dea crash
    }
    return top->head();
}

char Stack::pop()
{
    if (empty())
    {

        throw std::exception(); /// Daca e goala returneaza exceptie in loc sa dea crash
    }

    Node* tail = top->tail();
    int result = top->head();
    delete top;
    top = tail;
    return result;
}


#endif // STACKCLASS_H_INCLUDED
