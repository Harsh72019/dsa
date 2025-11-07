#include<bits/stdc++.h>
using namespace std;

vector<int> oceanView(vector<int>& heights)
{
    stack<pair<int , int>> st;
    for(int i = 0 ; i < heights.size() ; i++)
    {
        while(!st.empty() && st.top().first <= heights[i])
        {
            st.pop();
        }
        st.push({heights[i] , i});
    }
    vector<int> ans;
    while(!st.empty())
    {
        cout<<st.top().second<<" "<<st.top().first<<endl;
        ans.push_back(st.top().second);
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){
    vector<int> heights = {4,2,3,1};
    vector<int> ans = oceanView(heights);
    cout<<"[ ";
    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout<<" ]";
    return 0;
}