#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    Stack<Integer> first;
    Stack<Integer> second;
    public MyQueue() {
        first = new Stack<>();
        second = new Stack<>();
    }
    
    public void push(int x) {
        while(!first.isEmpty())
        {
            second.push(first.peek());
            first.pop();

        }
        first.push(x);
        while(!second.isEmpty())
        {
            first.push(second.peek());
            second.pop();
        }
    }
    
    public int pop() {
        int popped = first.peek();
        first.pop();
        return popped;
    }
    
    public int peek() {
        return first.peek();
    }
    
    public boolean empty() {
        return first.isEmpty();
    }
}

