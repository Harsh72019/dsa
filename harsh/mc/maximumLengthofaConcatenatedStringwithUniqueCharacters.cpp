#include<bits/stdc++.h>
using namespace std;

int ans = INT_MIN;

bool checkUnique(string s) {
    vector<int> arr(26, 0);
    for (char i : s) {
        arr[i - 'a']++;
        if (arr[i - 'a'] > 1)
            return false;
    }
    return true;
}

void solve(int index, string currentString, vector<string>& arr, vector<bool>& visited) {
    if (index >= arr.size()) {
        ans = max(ans, (int)currentString.size());
        return;
    }

    string newString = currentString;
    if (!visited[index]) {
        newString += arr[index];
        visited[index] = true;
    }

    bool flag = checkUnique(newString);
    if (flag) {
        solve(index + 1, newString, arr, visited);
    }
    solve(index + 1, currentString, arr, visited);
    
   
    visited[index] = false;
}

int maxLength(vector<string>& arr) {
    string curr = "";
    vector<bool> visited(arr.size(), false);
    solve(0, curr, arr, visited);
    return ans;
}