/*
LINK :- https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/ 
class SearchInRotatedSortedArrayInDuplicateValue {
    public static void main(String[] args) {
        int[] nums = {4, 5, 6, 7, 0, 1, 2};
        int target = 0;
       boolean result = Search(nums, target);
       if(result)
       {
        System.out.println("Target found");
       }
       else{
        System.out.println("Target not found");
       }
       
    }

    public static boolean  Search(int[] nums, int target) {
        int peak = peakIndex(nums);
        return binarySearch(nums, target, 0, peak) || binarySearch(nums, target, peak + 1, nums.length - 1);
    }

    public static int peakIndex(int[] arr)
    {
        int start = 0 , end = arr.length - 1;
        while(start < end)
        {
            int mid = start + (end - start)/2;

            if(arr[start] == arr[mid] && arr[mid] == arr[end])
            {
                start++;
                end--;
                continue;
            }
            else if(arr[start] > arr[mid]){
                end = mid - 1;
            }
            else if(arr[mid] > arr[mid+1]){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        return start;
    }

    public static boolean binarySearch(int[] arr, int target, int start,int end){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] > target){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
}
