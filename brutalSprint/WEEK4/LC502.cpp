#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        mat[i] = {capital[i], profits[i]};
    }

    sort(mat.begin(), mat.end());

    priority_queue<int> maxHeap;
    int index = 0;

    while (k--)
    {
        while (index < n && mat[index].first <= w)
        {
            maxHeap.push(mat[index].second);
            index++;
        }

        if (maxHeap.empty())
            break;

        w += maxHeap.top();
        maxHeap.pop();
    }

    return w;
}