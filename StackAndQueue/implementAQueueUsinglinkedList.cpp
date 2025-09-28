#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    // Enqueue operation
    void push(int value) {
        Node* newNode = new Node(value);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Dequeue operation
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;

        // If front becomes null, update rear to null too
        if (frontNode == nullptr)
            rearNode = nullptr;

        delete temp;
    }

    // Get the front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return frontNode->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Queue q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front element: " << q.front() << endl;  // 10
    q.pop();

    cout << "Front element after pop: " << q.front() << endl;  // 20
    q.pop();
    q.pop();

    q.pop();  // Queue is empty
 
    return 0;
}
