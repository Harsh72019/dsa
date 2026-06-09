#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();

        double low = 0.0;
        double high = 1.0;

        while (true)
        {
            double mid = (low + high) / 2.0;

            int count = 0;

            int p = 0;
            int q = 1;

            int i = -1;

            for (int j = 1; j < n; j++)
            {

                while (arr[i + 1] < mid * arr[j])
                    i++;

                count += i + 1;

                if (i >= 0 &&
                    (long long)arr[i] * q >
                        (long long)p * arr[j])
                {

                    p = arr[i];
                    q = arr[j];
                }
            }

            if (count == k)
                return {p, q};

            if (count < k)
                low = mid;
            else
                high = mid;
        }
    }
};