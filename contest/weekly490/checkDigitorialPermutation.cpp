#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<long long> facts;

public:
    Solution()
    {
        facts.assign(10, 0);
        facts[0] = 1;
        long long prefixMul = 1;
        for (int i = 1; i <= 9; i++)
        {
            prefixMul *= i;
            facts[i] = prefixMul;
        }
    }

    bool isDigitorialPermutation(int n)
    {

        int temp = n;
        long long sum = 0;

        vector<int> freqN(10, 0);

        while (n)
        {
            int rem = n % 10;
            n /= 10;
            sum += facts[rem];
            freqN[rem]++;
        }

        vector<int> freqS(10, 0);

        while (sum)
        {
            int rem = sum % 10;
            sum /= 10;
            freqS[rem]++;
        }

        return freqN == freqS;
    }
};