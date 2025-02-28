// https://leetcode.com/problems/peak-index-in-a-mountain-array/

/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.
Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
*/

public class PeakIndexInMountainArray {
    public int peakIndexInMountainArray(int[] arr) {
        int start = 0 , end = arr.length -1;
        // int ans = -1;
        while(start < end){
            int mid = start + (end - start)/2;
        
            if(arr[mid] > arr[mid + 1]){
                // ans = mid;
                end = mid;  // We are in the descending part, so there are chances that the mid will be the greater number, hence we are not taking -> end = mid -1 
            }else{
                start = mid + 1;
            }
           
        }
        // return ans;
        return start;
    }
}
