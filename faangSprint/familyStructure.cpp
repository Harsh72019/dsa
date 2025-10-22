#include <bits/stdc++.h>
using namespace std;

char familyStructure(string family, char person1, char person2)
{
    unordered_map<char, vector<char>> parents;

    // Build child -> parents mapping
    for (int i = 1; i < family.size(); i += 2)
    {
        char left = family[i - 1];
        char rel = family[i];
        char right = family[i + 1];

        if (rel == '>') parents[right].push_back(left);  // A>B → A parent of B
        else if (rel == '<') parents[left].push_back(right); // A<B → B parent of A
    }

    // DFS to collect all ancestors (parents upward)
    auto getAncestors = [&](char person)
    {
        unordered_set<char> anc;
        function<void(char)> dfs = [&](char node)
        {
            for (auto p : parents[node])
            {
                if (!anc.count(p))
                {
                    anc.insert(p);
                    dfs(p);
                }
            }
        };
        dfs(person);
        return anc;
    };

    auto anc1 = getAncestors(person1);
    auto anc2 = getAncestors(person2);

    anc1.insert(person1);
    anc2.insert(person2);

    // Find the first common ancestor
    for (char c : anc1)
    {
        if (anc2.count(c))
            return c;
    }

    return '-';
}

int main()
{
    string s = "A>B>C";
    char person1 = 'A';
    char person2 = 'C';

    char yca = familyStructure(s, person1, person2);
    cout << "Youngest Common Ancestor of " << person1 << " and " << person2 << " is: " << yca << endl;

    return 0;
}
