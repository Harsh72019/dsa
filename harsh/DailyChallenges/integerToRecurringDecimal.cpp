#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return "0";

    string ans;

    if ((numerator < 0) ^ (denominator < 0))
        ans += "-";

    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    ans += to_string(n / d);
    long long rem = n % d;
    if (rem == 0)
        return ans;

    ans += ".";

    unordered_map<long long, int> remainderIndex;

    while (rem != 0)
    {
        if (remainderIndex.count(rem))
        {
            ans.insert(remainderIndex[rem], "(");
            ans += ")";
            break;
        }

        remainderIndex[rem] = ans.size();

        rem *= 10;
        ans += to_string(rem / d);
        rem %= d;
    }

    return ans;
}