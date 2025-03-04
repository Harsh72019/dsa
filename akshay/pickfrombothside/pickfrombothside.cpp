// Pick from both sides!
// Programming
// Arrays
// very easy
// 51.5% Success

// 822

// 150

// Bookmark
// Asked In:
// Problem Description
 
 

// Given an integer array A of size N.

// You have to pick exactly B elements from either left or right end of the array A to get the maximum sum.

// Find and return this maximum possible sum.

// NOTE: Suppose B = 4 and array A contains 10 elements then

// You can pick the first four elements or can pick the last four elements or can pick 1 from the front and 3 from the back etc. you need to return the maximum possible sum of elements you can pick.


int Solution::solve(vector<int> &A, int B) {
    int currSum = 0;
    for(int i=0;i<B;i++){
        currSum+=A[i];
    }
    int i=B-1;
    int j = A.size()-1;
    int newSum = currSum;
    while(i>=0){
        newSum = newSum-A[i];
        newSum = newSum+A[j];
        currSum = max(newSum,currSum);
        i--;
        j--;
    }
    return currSum;
}
