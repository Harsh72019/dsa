#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {
        int n = favoriteCompanies.size();

        vector<unordered_set<string>> companySets(n);
        for (int i = 0; i < n; ++i)
        {
            companySets[i] = unordered_set<string>(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }

        vector<int> result;

        for (int i = 0; i < n; ++i)
        {
            bool isSubset = false;

            for (int j = 0; j < n; ++j)
            {
                if (i == j || favoriteCompanies[i].size() > favoriteCompanies[j].size())
                {
                    continue;
                }

                bool allFound = true;
                for (const string &company : favoriteCompanies[i])
                {
                    if (companySets[j].find(company) == companySets[j].end())
                    {
                        allFound = false;
                        break;
                    }
                }

                if (allFound)
                {
                    isSubset = true;
                    break;
                }
            }

            if (!isSubset)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};