#include<bits/stdc++.h>
using namespace std;
// s = "aaabbbcdd"
// k = 3
int solve(string s , int k )
{
    int left = 0;
    unordered_map<char ,int> count;
    for(char c : s)
    {
        count[c]++;
    }
    unordered_set<char> st;
    int ans = 0;
    for(auto it : count)
    {
        if(it.second < k)
            st.insert(it.first);
    }
    int currAtLeastK = 0;
    unordered_map<char , int> arr;
    for(int right = 0 ; right < s.size() ; right++)
    {
        arr[s[right]]++;
            cout<<s[right]<<"->"<<arr[s[right]]<<endl;
        if(st.find(s[right]) != st.end())
        {
            right++;
            while(left < s.size() && left < right)
            {
                arr[s[left]]--;
                left++;
            }
            currAtLeastK = 0;
            continue;
        }
        // cout<<s[right]<<"->"<<arr[s[right]];
        cout<<currAtLeastK<<endl;
        if(arr[s[right]] >= k)
            currAtLeastK++;
        if(currAtLeastK == arr.size())
            ans = max(ans , right - left + 1);
    }
    return ans;
}

int main()
{
    string s = "aaabbbcdd";
    int ans = solve(s , 3);
    cout<<ans;
    return 1;
}