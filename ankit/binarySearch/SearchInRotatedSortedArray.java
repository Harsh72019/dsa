package ankit.binarySearch;

/*
Link :- https://leetcode.com/problems/search-in-rotated-sorted-array/description/
Problem Statement :- (Leetcode 33)
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 */

 class SearchInRotatedSortedArray {

    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
       int result = search(nums, target);
       System.out.println("Final result is::"+result);
    }
    public static int search(int[] nums, int target) {
        int peak = peakIndex(nums);
        int ans = binarySearch(nums,target,0,peak);
        if(ans == -1){
          ans =  binarySearch(nums, target,peak+1,nums.length-1);
        }
        return ans;
    }

    public static int peakIndex(int[] arr) {
        int start = 0, end = arr.length - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[start] > arr[mid]) {
                //Means mid is not the peak index as mid is less than start(decreasing) so there must be a peak value before mid
                end = mid - 1;
            } else if (arr[mid] > arr[mid + 1]) {
                //  mid is greater than mid+1(increasing) so there may be a chance that end is the peak value.
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;  // Ceiling of a number
    }

    public static int binarySearch(int[] arr, int target, int start,int end){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[mid]>target){
                // target is in left side
                end = mid - 1;
            }else{
                // target is in right side
                start = mid + 1;
            }
        }
        return -1;
    }
}
