#include <bits/stdc++.h>
using namespace std;

bool isInt(char c)
{
    return c >= '0' && c <= '9';
}

char kThCharaterOfDecryptedString(string s, long long k)
{
    long long length = 0;
    for (int i = 0; i < s.size();)
    {
        string temp = "";
        while (i < s.size() && !isInt(s[i]))
        {
            temp += s[i];
            i++;
        }

        long long num = 0;
        while (i < s.size() && isInt(s[i]))
        {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        if (num == 0)
            num = 1;

        if (length + (long long)temp.size() * num >= k)
        {
            long long pos = (k - length - 1) % temp.size();
            return temp[pos];
        }

        length += (long long)temp.size() * num;
    }

    return '#';
}
