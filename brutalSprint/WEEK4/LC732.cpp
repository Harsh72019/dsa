#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
public:
    map<int, int> m;
    int maxCount;
    MyCalendarThree()
    {
        maxCount = 0;
    }

    int book(int startTime, int endTime)
    {
        m[startTime]++;
        m[endTime]--;
        int count = 0;
        for (auto it : m)
        {
            count += it.second;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
