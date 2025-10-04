#include <bits/stdc++.h>
using namespace std;

string nextPalindrome(string num)
{
    int n = num.size();

    if (all_of(num.begin(), num.end(), [](char c)
               { return c == '9'; }))
    {
        string res = "1";
        res.append(n - 1, '0');
        res.push_back('1');
        return res;
    }

    string left = num.substr(0, n / 2);
    string middle = (n % 2 == 0) ? "" : num.substr(n / 2, 1);
    string right = num.substr((n + 1) / 2);

    // First candidate: mirror left
    string mirrored = left + middle;
    string revLeft = left;
    reverse(revLeft.begin(), revLeft.end());
    mirrored += revLeft;

    if (mirrored > num)
        return mirrored;

    if (n % 2 == 0)
    {
        string incrementPart = left;
        int i = incrementPart.size() - 1;
        while (i >= 0 && incrementPart[i] == '9')
        {
            incrementPart[i] = '0';
            i--;
        }
        if (i >= 0)
            incrementPart[i]++;
        else
            incrementPart = "1" + incrementPart;

        left = incrementPart;
        string rev = left;
        reverse(rev.begin(), rev.end());
        return left + rev;
    }
    else
    {
        string incrementPart = left + middle;
        int i = incrementPart.size() - 1;
        while (i >= 0 && incrementPart[i] == '9')
        {
            incrementPart[i] = '0';
            i--;
        }
        if (i >= 0)
            incrementPart[i]++;
        else
            incrementPart = "1" + incrementPart;

        left = incrementPart.substr(0, incrementPart.size() - 1);
        middle = incrementPart.substr(incrementPart.size() - 1);
        string rev = left;
        reverse(rev.begin(), rev.end());
        return left + middle + rev;
    }
}

int main()
{
    vector<string> tests = {"1234", "999", "808", "2133", "12932"};
    for (auto &num : tests)
    {
        cout << "Next palindrome after " << num << " = " << nextPalindrome(num) << endl;
    }
}
