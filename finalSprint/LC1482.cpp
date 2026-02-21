#include<bits/stdc++.h>
using namespace std;

 bool check(int days, vector<int>& bloomDay, int m, int k)
    {
        int consecutive = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= days)
            {
                consecutive++;
                if (consecutive == k)
                {
                    bouquets++;
                    consecutive = 0;
                }
            }
            else
            {
                consecutive = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if ((long long)m * k > n)
            return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (check(mid, bloomDay, m, k))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }