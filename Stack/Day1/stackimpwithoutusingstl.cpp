#include <iostream>
using namespace std;
class stack
{

    int *arr;
    int size;
    int top;
    public:
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    // void push function implementation
    void push(int data)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "stack is overflow " << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {

            top--;
        }
        else
        {
            cout << "stack is underflow" << endl;
        }
    }

    int gettop()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Not possible to prrint " << endl;
            return 0;
        }
    }

    bool empty()
    {
        if (top >= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int getsize()
    {
        return top + 1;
    }
};
int main()
{

    stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Printing the size of the stack " << s.getsize() << endl;

    cout << "Printing that stack is empty or not " << s.empty();

    cout << "printing the top ele of the stack " << s.gettop() << endl;

    cout << " printing that stack element " << endl;
    
    while (!s.empty())
    {
        cout << s.gettop() << " ";
        s.pop();
    }
    cout<<endl<<s.gettop();
}