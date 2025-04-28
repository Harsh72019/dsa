#include<bits/stdc++.h>
using namespace std;

class Stack {
    int * arr;
    int size;
    int top;
    public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if(top == size -1 )
        {
            cout<<"Stack Overflow\n";   
            return;
        }
        arr[++top] = data;
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow\n";   
            return;
        }
        top--;
    }
    int peek()
    {
        if(top == -1)
        {
            cout<<"Stack is empty\n";   
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }

};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element is: " << s.peek() << endl; 
    s.pop();
    cout << "Top element after pop is: " << s.peek() << endl; 
    s.pop();
    s.pop();
    s.pop(); 
    return 0;
}