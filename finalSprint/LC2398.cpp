#include <bits/stdc++.h>
using namespace std;

int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
{

    deque<int> dq;
    long long runSum = 0;
    int left = 0, ans = 0;

    for (int right = 0; right < chargeTimes.size(); right++)
    {

        while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right])
            dq.pop_back();
        dq.push_back(right);

        runSum += runningCosts[right];

        while (!dq.empty() && chargeTimes[dq.front()] + (right - left + 1) * runSum > budget)
        {

            if (dq.front() == left)
                dq.pop_front();
            runSum -= runningCosts[left];
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    return ans;
}
