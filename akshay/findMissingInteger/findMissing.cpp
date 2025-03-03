#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    // int n = A.size();
    //  int sumOfn = (n*(n+1))/2;
    //  int innerSum = 0;
    // for(int i=0;i<A.size();i++){
    //      if(A[i]<0){
    //          innerSum+=A[i];
    //      }
    // }
    // int ans = sumOfn-innerSum;
    // return ans;
    // int n = A.size();
    
    // for (int i = 1; i <= n + 1; i++) {  // Check from 1 to n+1
    //     bool found = false;
    //     for (int k = 0; k < n; k++) {
    //         if (A[k] == i) {  // Fix indexing issue (use A[k] instead of A[i])
    //             found = true;
    //             break;
    //         }
    //     }
    //     if (!found) {
    //         return i;  // First missing positive integer found
    //     }
    // }
    
    // return n + 1;
  sort(A.begin(), A.end());
    int check=1;
    if(A.size()==1&&A[0]<0){
        return 1;
    }
    for(int i=0;i<A.size();i++){
        if(A[i]>0){
            if(A[i]==check){
                check++;
            }
            else{
                return check;
            }
        }
    }
    return A.size()+1;
    
}
