#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLetter(char c)
    {
        return c >= 'a' && c <= 'z';
    }

    string reverseByType(string s)
    {
        vector<char> letters, specials;

        for (char c : s)
        {
            if (isLetter(c))
                letters.push_back(c);
            else
                specials.push_back(c);
        }

        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());

        int i = 0, j = 0;
        for (int k = 0; k < s.size(); k++)
        {
            if (isLetter(s[k]))
            {
                s[k] = letters[i++];
            }
            else
            {
                s[k] = specials[j++];
            }
        }

        return s;
    }
};