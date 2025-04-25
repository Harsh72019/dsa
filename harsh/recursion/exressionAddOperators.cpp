#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string> &result, string path, string num, int pos, long currValue, long prevNum, int target)
{
    if (pos == num.size())
    {
        if (currValue == target)
            result.push_back(path);
        return;
    }

    for (int i = pos; i < num.size(); ++i)
    {
        if (i != pos && num[pos] == '0')
            break;

        string currStr = num.substr(pos, i - pos + 1);
        long currNum = stol(currStr);

        if (pos == 0)
        {

            backtrack(result, currStr, num, i + 1, currNum, currNum, target);
        }
        else
        {

            backtrack(result, path + "+" + currStr, num, i + 1, currValue + currNum, currNum, target);

            backtrack(result, path + "-" + currStr, num, i + 1, currValue - currNum, -currNum, target);

            backtrack(result, path + "*" + currStr, num, i + 1,
                      currValue - prevNum + (prevNum * currNum), prevNum * currNum, target);
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    backtrack(result, "", num, 0, 0, 0, target);
    return result;
}
