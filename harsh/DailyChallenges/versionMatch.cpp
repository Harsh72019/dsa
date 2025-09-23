#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{
    stringstream ss1(version1);
    stringstream ss2(version2);

    string num1, num2;

    while (true)
    {
        bool has1 = static_cast<bool>(getline(ss1, num1, '.'));
        bool has2 = static_cast<bool>(getline(ss2, num2, '.'));

        if (!has1 && !has2)
            break;

        int v1 = has1 ? stoi(num1) : 0;
        int v2 = has2 ? stoi(num2) : 0;

        if (v1 < v2)
            return -1;
        if (v1 > v2)
            return 1;
    }
    return 0;
}