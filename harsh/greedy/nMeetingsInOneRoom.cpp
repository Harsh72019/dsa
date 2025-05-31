#include<bits/stdc++.h>
using namespace std;

  int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        sort(meetings.begin(), meetings.end());

        int count = 0;
        int currentEnd = 0;

        for (auto &meeting : meetings) {
            if (meeting.second >= currentEnd) {
                count++;
                currentEnd = meeting.first;
            }
        }

        return count;
    }