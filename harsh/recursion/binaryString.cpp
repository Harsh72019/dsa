#include<bits/stdc++.h>
using namespace std;


void solver(int index , int num , vector<string>& st , string s)
    {
        if(index == num)
        {
            st.push_back(s);
            return;
        }
        s += '0';
        index++;
        solver(index , num , st , s );
        s.pop_back();
        index--;
        if(index  >= 0 && s[index - 1] != '1')
        {
            s += '1';
            index++;
            solver(index , num , st, s);
        }
    }
    vector<string> generateBinaryStrings(int num){
        vector<string> ans;
        solver(0 , num , ans , "");
        return ans;
    }