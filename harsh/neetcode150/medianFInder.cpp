#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
public:
    vector<int> arr;
    int currentSize;

    MedianFinder()
    {
        currentSize = 0;
    }

    void addNum(int num)
    {
        arr.insert(lower_bound(arr.begin(), arr.end(), num), num);
        currentSize++;
    }

    double findMedian()
    {
        if (currentSize % 2 == 0)
        {
            return (arr[currentSize / 2 - 1] + arr[currentSize / 2]) / 2.0;
        }
        else
        {
            return arr[currentSize / 2];
        }
    }
};
