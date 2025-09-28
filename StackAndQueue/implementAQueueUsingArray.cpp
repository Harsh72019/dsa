#include<bits/stdc++.h>
using namespace std;

class Queue {
    int * arr;
    int size;
    int front;
    int rear;
    public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if(rear == size -1 )
        {
            cout<<"Queue Overflow\n";   
            return;
        }
        if(front == -1)
            front = 0;
        arr[++rear] = data;
    }
    void dequeue()
    {
        if(front == -1 || front > rear)
        {
            cout<<"Queue Underflow\n";   
            return;
        }
        front++;
    }
    int peek()
    {
        if(front == -1 || front > rear)
        {
            cout<<"Queue is empty\n";   
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element is: " << q.peek() << endl; 
    q.dequeue();
    cout << "Front element after dequeue is: " << q.peek() << endl; 
    q.dequeue();
    q.dequeue();
    q.dequeue(); 
    return 0;
}
