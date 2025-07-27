#include<bits/stdc++.h>
using namespace std;

vector<int> reconstructLIS(vector<int> &nums, vector<vector<int>> &dp) {
    int n = nums.size();
    int index = 0, prevIndex = -1;
    vector<int> lis;

    while (index < n) {
        int pick = 0;
        if (prevIndex == -1 || nums[prevIndex] < nums[index]) {
            pick = 1 + dp[index + 1][index + 1];
        }
        int notPick = dp[index + 1][prevIndex + 1];

        if (pick >= notPick) {
            lis.push_back(nums[index]);
            prevIndex = index;
        }
        index++;
    }

    return lis;
}

int solver(int index, int prevIndex, vector<int> &nums, vector<vector<int>> &dp) {
    if (index == nums.size())
        return 0;

    if (dp[index][prevIndex + 1] != -1)
        return dp[index][prevIndex + 1];

    int notPick = solver(index + 1, prevIndex, nums, dp);
    int pick = 0;

    if (prevIndex == -1 || nums[prevIndex] < nums[index])
        pick = 1 + solver(index + 1, index, nums, dp);

    return dp[index][prevIndex + 1] = max(pick, notPick);
}

vector<int> getLIS(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    solver(0, -1, nums, dp);
    return reconstructLIS(nums, dp);
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    vector<int> lis = getLIS(nums);

    cout << "LIS: ";
    for (int num : lis)
        cout << num << " ";
    cout << endl;

    return 0;
}
