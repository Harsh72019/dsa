#include<bits/stdc++.h>
using namespace std;

  int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);
        for(char t : tasks)
            freq[t - 'A']++;

        priority_queue<int> maxHeap;
        for(int f : freq)
            if(f > 0)
                maxHeap.push(f);

        int time = 0;

        while(!maxHeap.empty()) {

            int cycle = n + 1;
            vector<int> temp;
            int tasksDone = 0;

            while(cycle > 0 && !maxHeap.empty()) {
                int f = maxHeap.top(); maxHeap.pop();
                if(f - 1 > 0)
                    temp.push_back(f - 1);
                tasksDone++;
                cycle--;
            }

            for(int f : temp)
                maxHeap.push(f);

            if(maxHeap.empty())
                time += tasksDone;
            else
                time += (n + 1);
        }

        return time;
    }