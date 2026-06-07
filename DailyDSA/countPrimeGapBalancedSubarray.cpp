#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<bool> isPrime;

public:
    Solution()
    {
        int N = 50000;

        isPrime.assign(N + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= N; p++)
        {
            if (!isPrime[p])
                continue;

            for (int x = p * p; x <= N; x += p)
                isPrime[x] = false;
        }
    }

    long long primeSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        multiset<int> primes; // prime values in current window
        deque<int> primePos;  // positions of primes in current window

        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++)
        {

            if (isPrime[nums[r]])
            {
                primes.insert(nums[r]);
                primePos.push_back(r);
            }

            while (!primes.empty() &&
                   (*primes.rbegin() - *primes.begin() > k))
            {

                if (isPrime[nums[l]])
                {
                    primes.erase(primes.find(nums[l]));
                    primePos.pop_front();
                }

                l++;
            }

            if (primePos.size() >= 2)
            {
                int secondLastPrimePos =
                    primePos[(int)primePos.size() - 2];

                ans += (long long)(secondLastPrimePos - l + 1);
            }
        }

        return ans;
    }
};