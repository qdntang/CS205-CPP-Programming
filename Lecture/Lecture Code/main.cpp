//====================================================
//====================================================
//====================================================
//Program example 3

// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_

template <class Type>

class Stack
{
    private:
    enum {MAX = 10}; // constant specific to class
    Type items[MAX]; // holds stack items
    int top; // index for top stack item
    
    public:
    Stack();
    
    bool isempty();
    bool isfull();
    bool push(const Type & item); // add item to stack
    bool pop(Type & item); // pop top into item
};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;    
}

template <class Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}
#endif

//------------------------------------------------------------

// stacktem.cpp -- testing the template stack class
#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;

int main()
{
    Stack<std::string> st; // create an empty stack
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"<< "P to process a PO, or Q to quit.\n";
    
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        
        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': 
                cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);
                break;
            case 'P':
            case 'p': 
                if (st.isempty())
                    cout << "stack already empty\n";
                else 
                {
                    st.pop(po);
                    cout << "PO #" << po << " popped\n";
                    break;
                }
        }
        
        cout << "Please enter A to add a purchase order,\n"<< "P to process a PO, or Q to quit.\n";
    }
    
    cout << "Bye\n";
    return 0;
}


