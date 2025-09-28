#include<bits/stdc++.h>
using namespace std;

int solver(string name)
{
    unordered_set<char> s;
    for(int i = 0 ; i < name.size(); i++)
    {
        char c = name[i];
        s.insert(tolower(c));
    }
    return s.size();
}


int main()
{
    int testCases;
    cin >> testCases;
    while(testCases--)
    {
        string name;
        cin >> name;
        int uniqueChars = solver(name);
        // cout<< uniqueChars << " unique characters for " << name << endl;
        int discount = uniqueChars * 5;
        // cout << 100 - discount << " ";
        cout << discount << "%" << endl;
    }
}