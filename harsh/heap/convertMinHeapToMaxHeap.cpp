#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
vector<int> minToMaxHeap(vector<int> nums)
{
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        maxHeapify(nums, n, i);
    }
    return nums;
}