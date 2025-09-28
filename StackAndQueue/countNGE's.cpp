#include<bits/stdc++.h>
using namespace std;

  int nextGreaterElements(vector<int>& a, int index){
    int count = 0, N = a.size();
    
    for (int i = index + 1; i < N; i++)
        if (a[i] > a[index])
            count++;
 
    return count;
}

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans;
        for(int i = 0;i<queries;i++){
            ans.push_back(nextGreaterElements(arr,indices[i]));
        }

        return ans;
    }