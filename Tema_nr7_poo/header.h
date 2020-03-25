
#ifndef STACKCLASS_H_INCLUDED
#define STACKCLASS_H_INCLUDED

#include <stdexcept> // for std::exception
#include <iostream>

using namespace std;

class Stack;

class Node
{
private:
    int info;
    Node* next;

public:
    friend class Stack; /// Trebuie sa fie prietene pentru ca Stack sa poata modifica nodul top()

    Node(int val, Node* prev)  /// Constructor - CERINTA
    {
        info=val;
        next=prev;
    }

    ~Node() {} /// Destructor gol deoarece se dealoca din stack - CERINTA

    int head() const /// Returneaza head-ul la lista inlantuita
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

    Stack& operator= (const Stack& other) /// Overload la operatorul = ( imi trebuie pentru eventualele copieri. o sa vad )
    {
        if (this == &other)  /// Crash daca asignam aceeasi variabila, gen Stack a = a;
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
                current->next = new Node(*otherNext); // copy the current node
                current = current->tail(); // move to the next node
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

    void push(int); /// CERINTA , FUNCTIE DECLARATA MAI JOS
    int pop();
    int peek() const;
    int getSize() const;
    void reverseStack(Stack&);
    friend ostream& operator<<(ostream& os, const Stack& printStack);
    friend istream& operator >> (istream &in, Stack& readStack);
    friend Stack operator - (Stack const &, Stack const &);

};

Stack operator - (Stack const &s1, Stack const &s2)
{
     Stack tmpResult;
     Stack tmp1 = s1;
     Stack tmp2 = s2;
     while(tmp1.getSize()>0 && tmp1.getSize()>0)
     {
        if(tmp1.peek()>tmp2.peek())
            tmpResult.push(tmp1.peek());
        else
            tmpResult.push(tmp2.peek());
        tmp1.pop();
        tmp2.pop();

     }
     tmpResult.reverseStack(tmpResult); /// asta e in functie de ce ordine vrei rezultatul. Poti sa o comentezi
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

/// O transformi tu pt string;
istream & operator >> (istream &in,  Stack &readStack)
{
    int x;
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

void Stack::push(int value)
{
    Node* currentTop = top;
    top = new Node(value, currentTop);
}

///Retarded design s.reverseStack(s); Face reverse la orice stack,dar trebuie castata pe un obiect. O faci tu bine
void Stack::reverseStack(Stack& toBeReversedStack)
{
    Stack tmpStack;
    while(toBeReversedStack.getSize()>0)
    {
        int tmpValue = toBeReversedStack.peek();
        tmpStack.push(tmpValue);
        toBeReversedStack.pop();
    }
    toBeReversedStack = tmpStack;
}

int Stack::peek() const
{
    if (empty())
    {
        throw std::exception(); /// Daca e goala returneaza exceptie in loc sa dea crash
    }
    return top->head();
}

int Stack::pop()
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
