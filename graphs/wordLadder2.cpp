#include<bits/stdc++.h>
using namespace std;


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        unordered_set<string> visitedThisLevel;
        
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            
            if (vec.size() > level) {
                level++;
                for (auto& w : usedOnLevel)
                    st.erase(w);
                usedOnLevel.clear();
               
            }

            string word = vec.back();
            if (word == endWord) {
                if (ans.empty())
                {
                   ans.push_back(vec);
                }
                else if(vec.size() ==  ans[0].size())
                   ans.push_back(vec);
               
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }