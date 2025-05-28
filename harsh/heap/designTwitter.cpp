#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> userFollows;

public:
    Twitter()
    {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        userTweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> feed;

        userFollows[userId].insert(userId);
        for (int followeeId : userFollows[userId])
        {
            auto &twts = userTweets[followeeId];
            for (int i = max(0, (int)twts.size() - 10); i < twts.size(); ++i)
            {
                feed.push(twts[i]);
            }
        }

        vector<int> result;
        while (!feed.empty() && result.size() < 10)
        {
            result.push_back(feed.top().second);
            feed.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId)
    {
        userFollows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        userFollows[followerId].erase(followeeId);
    }
};
