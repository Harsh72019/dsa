#include <iostream>
#include <vector>
using namespace std;

// ===== MAX HEAP CLASS =====
class MaxHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
                break;
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top()
    {
        if (!heap.empty())
            return heap[0];
        throw runtime_error("MaxHeap is empty");
    }
    bool empty()
    {
        return heap.empty();
    }
    void print()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

// ===== MIN HEAP CLASS =====
class MinHeap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int index)
    {
        int size = heap.size();
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else
                break;
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top()
    {
        if (!heap.empty())
            return heap[0];
        throw runtime_error("MinHeap is empty");
    }

    bool empty()
    {
        return heap.empty();
    }

    void print()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    MaxHeap maxHeap;
    MinHeap minHeap;

    vector<int> nums = {15, 5, 20, 1, 17};

    for (int num : nums)
    {
        maxHeap.push(num);
        minHeap.push(num);
    }

    cout << "MaxHeap: ";
    maxHeap.print();

    cout << "MinHeap: ";
    minHeap.print();

    cout << "MaxHeap Top: " << maxHeap.top() << endl; 
    cout << "MinHeap Top: " << minHeap.top() << endl; 

    maxHeap.pop();
    minHeap.pop();

    cout << "After popping top:" << endl;
    cout << "MaxHeap Top: " << maxHeap.top() << endl;
    cout << "MinHeap Top: " << minHeap.top() << endl;

    return 0;
}
