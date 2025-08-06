#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',') continue;

            if (ch != ')') {
                st.push(ch);
            } else {
                unordered_set<char> seen;
                while (st.top() != '(') {
                    seen.insert(st.top());
                    st.pop();
                }
                st.pop(); 
                char op = st.top(); st.pop();

                if (op == '!') {
                    st.push(seen.count('t') ? 'f' : 't');
                } else if (op == '&') {
                    st.push(seen.count('f') ? 'f' : 't');
                } else if (op == '|') {
                    st.push(seen.count('t') ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};
