Perfect Peak of Array
Programming
Arrays
easy
51.1% Success

299

24

Bookmark
Asked In:
Problem Description
 
 

Given an integer array A of size N.

You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.

If it exists return 1 else return 0.

NOTE:

Do not consider the corner elements i.e A[0] and A[N-1] as the answer.
Input 1:

 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:

 A = [5, 1, 4, 4]


Example Output
Output 1:

 1
Output 2:

 0


int Solution::perfectPeak(vector<int> &A) {
    
     int n = A.size();
        if (n < 3) return 0; // Need at least 3 elements to have a peak
    
        vector<int> leftNum(n), RightNum(n);
        
        // Initialize leftNum and RightNum
        leftNum[0] = A[0];
        RightNum[n - 1] = A[n - 1];
    
        // Compute leftNum (stores max from left)
        for (int i = 1; i < n; i++) {
            leftNum[i] = max(A[i], leftNum[i - 1]);
        }
    
        // Compute RightNum (stores min from right)
        for (int i = n - 2; i >= 0; i--) {
            RightNum[i] = min(RightNum[i + 1], A[i]);
        }
    
        // Find valid element
        for (int i = 1; i < n - 1; i++) {
            if (A[i] > leftNum[i - 1] && A[i] < RightNum[i + 1]) {
                return 1; // Found a valid element
            }
        }
    
        return 0; // N

    }