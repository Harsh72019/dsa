#include <bits/stdc++.h>
using namespace std;

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> deads(deadends.begin(), deadends.end());
    unordered_set<string> visited;
    queue<pair<string, int>> q;

    if (deads.count("0000"))
        return -1;

    q.push({"0000", 0});
    visited.insert("0000");

    while (!q.empty())
    {
        string lock = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (lock == target)
            return depth;

        for (int i = 0; i < 4; i++)
        {
            char original = lock[i];

            lock[i] = (original == '9') ? '0' : original + 1;
            if (!deads.count(lock) && !visited.count(lock))
            {
                visited.insert(lock);
                q.push({lock, depth + 1});
            }

            lock[i] = (original == '0') ? '9' : original - 1;
            if (!deads.count(lock) && !visited.count(lock))
            {
                visited.insert(lock);
                q.push({lock, depth + 1});
            }

            lock[i] = original;
        }
    }
    return -1;
}