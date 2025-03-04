// Occurence of Each Number
// Programming
// Arrays
// medium
// 62.3% Success

// 139

// 59

// Bookmark
// Asked In: Paytm
// Problem Description
 
 

// You are given an integer array A.

// You have to find the number of occurences of each number.

// Return an array containing only the occurences with the smallest value's occurence first.

// For example, A = [4, 3, 3], you have to return an array [2, 1], where 2 is the number of occurences for element 3, 
// and 1 is the number of occurences for element 4. But, 2 comes first because 3 is smaller than 4.







vector<int> Solution::findOccurences(vector<int> &A) {
    
    vector<int> ans;
 map<int, int> mp;
 
 for (int i = 0; i < A.size(); i++) {
     mp[A[i]]++;
 }
 for (auto it : mp) {
     ans.push_back(it.second); 
 }
 
 return ans; 
     
     
     
     
 }
 