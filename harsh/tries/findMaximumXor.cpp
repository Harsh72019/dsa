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

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Node* root = new Node();

        for (int i = 0; i < n; i++) {
            Node* temp = root;
            int num = nums[i];
            for (int bit = 31; bit >= 0; bit--) {
                int current = (num >> bit) & 1; 
                if (!temp->containsKey(current)) {
                    temp->put(current, new Node());
                }
                temp = temp->get(current);
            }
            temp->setEnd();
        }

        int maxXor = 0;

        for (int i = 0; i < n; i++) {
            Node* temp = root;
            int num = nums[i];
            int currXor = 0;
            for (int bit = 31; bit >= 0; bit--) {
                int current = (num >> bit) & 1;
                int opposite = 1 - current;
                if (temp->containsKey(opposite)) {
                    currXor |= (1 << bit);
                    temp = temp->get(opposite);
                } else {
                    temp = temp->get(current);
                }
            }
            maxXor = max(maxXor, currXor);
        }

        return maxXor;
    }
};
