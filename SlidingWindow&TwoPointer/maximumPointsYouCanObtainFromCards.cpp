#include<bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    if (n == k)
    {
        return accumulate(cardPoints.begin() , cardPoints.end() , 0);
    }      

    int currentSum = 0;
    
    for(int i = n - k ; i < n ; i++){
        currentSum += cardPoints[i];
    }

    int maxSum = currentSum;

    for(int i = n - k ; i < n ; i++)
    {
        currentSum += cardPoints[i - (n - k)] - cardPoints[i];
        maxSum = max(maxSum , currentSum);
    }

    return maxSum;
}