#include<bits/stdc++.h>
using namespace std;

   void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited) {
        visited[node] = true;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, st, visited);
            }
        }
        st.push(node);
    }

    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);

        for (int i = 1; i < N; i++) {
            string prev = dict[i - 1];
            string curr = dict[i];
            int len = min(prev.size(), curr.size());
            for (int j = 0; j < len; j++) {
                if (prev[j] != curr[j]) {
                    adj[prev[j] - 'a'].push_back(curr[j] - 'a');
                    break;
                }
            }
        }

        stack<int> st;
        vector<bool> visited(K, false);

        for (int i = 0; i < K; i++) {
            if (!visited[i]) {
                dfs(i, adj, st, visited);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += (char)(st.top() + 'a');
            st.pop();
        }

        return ans;
    }