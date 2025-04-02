#include<bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
    int counter = 0;
    int currentElement = nums[0];
    for(auto i : nums)
    {
        if(counter == 0)
        {
            currentElement = i;
            
        }
         if(currentElement == i)
        {
            counter++;
        }
        else{
            counter--;
        }
    }
    return currentElement;
}



