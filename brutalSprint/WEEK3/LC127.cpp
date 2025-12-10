#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
        return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> visited;
    visited.insert(beginWord);

    while (!q.empty())
    {
        auto [word, depth] = q.front();
        q.pop();
        if (word == endWord)
            return depth;

        for (int i = 0; i < (int)word.size(); ++i)
        {
            char orig = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (ch == orig)
                    continue;
                word[i] = ch;
                if (dict.find(word) != dict.end() && visited.find(word) == visited.end())
                {
                    visited.insert(word);
                    q.push({word, depth + 1});
                }
            }
            word[i] = orig;
        }
    }
    return 0;
}