#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr int LIMIT = 1e6;
    static constexpr int MAXREACH = 20000;

    long long encode(int x, int y) {
        return (long long)x * LIMIT + y;
    }

    bool bfs(vector<int>& start,
             vector<int>& finish,
             unordered_set<long long>& blocked) {

        unordered_set<long long> visited;
        queue<pair<int,int>> q;

        q.push({start[0], start[1]});
        visited.insert(encode(start[0], start[1]));

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= LIMIT || ny < 0 || ny >= LIMIT)
                    continue;

                long long key = encode(nx, ny);
                if (blocked.count(key) || visited.count(key))
                    continue;

                if (nx == finish[0] && ny == finish[1])
                    return true;

                visited.insert(key);
                q.push({nx, ny});

                if (visited.size() > MAXREACH)
                    return true;
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {

        if (blocked.size() < 2)
            return true;

        unordered_set<long long> blocks;
        for (auto& b : blocked)
            blocks.insert(encode(b[0], b[1]));

        return bfs(source, target, blocks) &&
               bfs(target, source, blocks);
    }
};
