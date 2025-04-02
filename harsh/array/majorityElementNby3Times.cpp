#include<bits/stdc++.h>
using namespace std;


vector<int> majorityElement(vector<int>& nums) {
    int element1 = 0 , element2 = 0;
    int count1 = 0 , count2 = 0;
    for(auto i : nums)
    {
        if(i == element1)
        {
            count1++;
        }
        else if(i == element2)
        {
            count2++;
        }
        else if(count1 == 0)
        {
            element1 = i;
            count1= 1;
        }
        else if(count2 == 0 && i != element1)
        {
            element2 = i;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1  = 0;
    count2 = 0;
    for(auto i : nums)
    {
        if(i == element1)
            count1++;
        else if(i == element2 )
            count2++;
    }
    if(count1 > nums.size() / 3) ans.push_back(element1);
    if(count2 > nums.size() / 3) ans.push_back(element2);
    return ans; 
}