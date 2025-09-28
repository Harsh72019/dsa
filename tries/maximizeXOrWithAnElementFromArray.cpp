#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];
    bool flag = false;

    bool containsKey(int n) {
        return (links[n] != NULL);
    }
    void put(int n, Node* node) {
        links[n] = node;
    }
    Node* get(int n) {
        return links[n];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit)) {
                maxNum |= (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        int q = queries.size();
        for (int i = 0; i < q; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());

        vector<int> ans(q, 0);
        int ind = 0;
        int n = nums.size();
        Trie trie;

        for (int i = 0; i < q; i++) {
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;

            while (ind < n && nums[ind] <= ai) {
                trie.insert(nums[ind]);
                ind++;
            }
            if (ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.findMax(xi);
        }
        return ans;
    }
};
