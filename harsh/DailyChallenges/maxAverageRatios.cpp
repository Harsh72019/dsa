#include <bits/stdc++.h>
using namespace std;

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    auto gain = [](int pass, int total)
    {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    };

    priority_queue<pair<double, pair<int, int>>> pq;

    for (auto &it : classes)
    {
        pq.push({gain(it[0], it[1]), {it[0], it[1]}});
    }

    while (extraStudents--)
    {
        auto [g, cls] = pq.top();
        pq.pop();
        int pass = cls.first, total = cls.second;
        pass++;
        total++;
        pq.push({gain(pass, total), {pass, total}});
    }

    double sum = 0;
    while (!pq.empty())
    {
        auto [g, cls] = pq.top();
        pq.pop();
        sum += (double)cls.first / cls.second;
    }

    return sum / classes.size();
}