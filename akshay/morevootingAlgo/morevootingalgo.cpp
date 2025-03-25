N/3 Repeat Number
Programming
Arrays
medium
31.6% Success

457

26

Bookmark
Asked In:
Problem Description
 
 

You're given a read-only array of N integers. Find out if any integer occurs more than N/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.



Problem Constraints
1 <= N <= 7*105
1 <= A[i] <= 109


Input Format
The only argument is an integer array A.


Output Format
Return an integer.


Example Input
[1 2 3 1 1]


Example Output
1







int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
 int num1 = 0, num2 = 0;
    int ctn1 = 0, ctn2 = 0;
    int n = A.size();

    // Phase 1: Find potential candidates
    for (int i = 0; i < n; i++) {
        if (ctn1 == 0 && A[i] != num2) {
            num1 = A[i];
            ctn1 = 1;
        } else if (ctn2 == 0 && A[i] != num1) {
            num2 = A[i];
            ctn2 = 1;
        } else if (A[i] == num1) {
            ctn1++;
        } else if (A[i] == num2) {
            ctn2++;
        } else {
            ctn1--;
            ctn2--;
        }
    }

    // Phase 2: Verify counts
    int count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == num1) count1++;
        if (A[i] == num2) count2++;
    }

    // Return the element with the higher count if both are valid
    if (count1 > n / 3 && count1 >= count2) return num1;
    if (count2 > n / 3) return num2;

    return -1; // No majority element found
    
    
    
    
}
