#include <bits/stdc++.h>
using namespace std;

bool canSplit(int m , int work , vector<int>& jobs)
{
    int currentWork = 0;
    int workersUsed = 1;
    for(int i = 0 ; i < jobs.size() ;i++ )
    {
        if(currentWork + jobs[i] > work)
        {
            currentWork = jobs[i];
            workersUsed++;
        }
        else
            currentWork += jobs[i];
    }
    return workersUsed <= m;
}

int minLoad(vector<int> jobs, int m)
{
    int minLoad = *min_element(jobs.begin(), jobs.end());
    int maxLoad = accumulate(jobs.begin() , jobs.end() , 0);
    while(minLoad <= maxLoad)
    {
        int expectedLoad = minLoad + ((maxLoad - minLoad) / 2);
        if(canSplit(m , expectedLoad , jobs))
        {
            maxLoad = expectedLoad - 1;
        }
        else    
            minLoad = expectedLoad + 1;
    }
    return minLoad;
}

int main()
{
    vector<int> loads = {7 , 2 , 5 , 10 , 8};
    cout<<minLoad( loads , 2);
    return 1;
}