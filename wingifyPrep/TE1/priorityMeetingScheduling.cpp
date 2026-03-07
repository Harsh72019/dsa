#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Job {
    int start, end, profit;
};

struct Result {
    int profit;
    int count;
};

class Solution {
    vector<Result> memo;

    Result solve(int i, int n, vector<Job>& jobs, vector<int>& startTimes) {
        if (i >= n) return {0, 0};

        if (memo[i].profit != -1) return memo[i];

        Result skip = solve(i + 1, n, jobs, startTimes);

        auto it = lower_bound(startTimes.begin() + i + 1, startTimes.end(), jobs[i].end);
        int nextIdx = distance(startTimes.begin(), it);
        
        Result pick = solve(nextIdx, n, jobs, startTimes);
        pick.profit += jobs[i].profit;
        pick.count += 1;

        if (pick.profit > skip.profit) {
            return memo[i] = pick;
        } else if (skip.profit > pick.profit) {
            return memo[i] = skip;
        } else {
            return memo[i] = (pick.count > skip.count) ? pick : skip;
        }
    }

public:
    Result jobSchedulingWithCount(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.start < b.start;
        });

        vector<int> startTimes;
        for (const auto& job : jobs) startTimes.push_back(job.start);

        memo.assign(n, {-1, 0});
        return solve(0, n, jobs, startTimes);
    }
};