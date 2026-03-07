#include<bits/stdc++.h>
using namespace std;

// Sliding Window

class RateLimiter{
private: 
    int reqPerMin;
    unordered_map<int , queue<int>> requests;

public:

    RateLimiter()
    {
        reqPerMin = 100;
    }

    bool allowRequest(int userId , int timeStamp)
    {
        int minWindowStart = timeStamp - 60;

        queue<int>& allRequest = requests[userId];

        while(!allRequest.empty() && allRequest.front() <= minWindowStart)
        {
            allRequest.pop();
        }

        if(allRequest.size() >= reqPerMin)
            return false;

        allRequest.push(timeStamp);

        return true;
    }
};

// Token Bucket

struct Bucket {
    double tokens;
    long lastRefill;
};

class RateLimiterOptimized {

private:
    unordered_map<int, Bucket> buckets;

    double capacity = 100;
    double refillRate = 100.0 / 60.0; // tokens per second

public:

    bool allow(int userId, long timestamp)
    {
        Bucket &b = buckets[userId];

        double elapsed = timestamp - b.lastRefill;

        b.tokens = min(capacity, b.tokens + elapsed * refillRate);
        b.lastRefill = timestamp;

        if(b.tokens < 1)
            return false;

        b.tokens -= 1;

        return true;
    }
};