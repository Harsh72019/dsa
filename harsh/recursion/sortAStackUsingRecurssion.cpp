#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int element) {
    
    if (s.empty() || element > s.top()) {
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();

    insertSorted(s, element);

    s.push(temp);
}

void sortStack(stack<int> &s) {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s, temp);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original Stack: ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}
