#include<bits/stdc++.h>

using namespace std;

int minPalindromeRemovals(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) { 
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1; 
            
            if (arr[i] == arr[j]) {
                dp[i][j] = (len == 2) ? 1 : dp[i+1][j-1];
            } else {
               
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
    }
    cout<<endl;
    for(int i = 0 ; i < dp.size() ; i++)
    {
        for(int j = 0 ; j < dp.size() ; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];  
}

int main() {
    vector<int> arr = {1, 3, 4, 1, 5, 4, 3, 1};
    cout << "Minimum removals: " << minPalindromeRemovals(arr) << endl;
    return 0;
}
