#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int i = 0;
    int j = 0;
    int lastInsertedElement  = INT_MIN;
    vector<int> ans;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            if(a[i] != lastInsertedElement)
            {
                ans.push_back(a[i]);
                lastInsertedElement = a[i];
            }
            i++;
        }
        else if(b[j] < a[i])
        {
            if(b[j] != lastInsertedElement)
            {
                ans.push_back(b[j]);
                lastInsertedElement = b[j];
            }
            j++;
        }
        else{
             if(a[i] != lastInsertedElement)
            {
                ans.push_back(a[i]);
                lastInsertedElement = a[i];
            }
            i++;
            j++;
        }
    }
    
    while(i < a.size())
    {
        if(a[i] != lastInsertedElement)
        {
            ans.push_back(a[i]);
            lastInsertedElement = a[i];
        }
        i++;
    }
    
    while(j < b.size())
    {
        if(b[j] != lastInsertedElement)
        {
            ans.push_back(b[j]);
            lastInsertedElement = b[j];
        }
        j++;
    }
    return ans;
}