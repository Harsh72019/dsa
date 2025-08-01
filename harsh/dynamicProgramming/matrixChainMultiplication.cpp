#include<bits/stdc++.h>
using namespace std;


int solver(int i , int j , vector<int>& arr)
{
    if(i == j )
        return 0;
    int ans = INT_MAX;
    for(int k = 0 ; k <= j ; k++)
    {
        int steps = solver(i , k , arr) + solver(k + 1 , j , arr) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans , steps);
    }
    return ans;
}

int mcm(vector<int>& arr)
{
    int n = arr.size() - 1;
    return solver(1 , n , arr);
}