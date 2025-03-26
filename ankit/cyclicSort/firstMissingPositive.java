// https://leetcode.com/problems/first-missing-positive/

class firstMissingPositive {
    public int missingPositive(int[] nums) {
        int index = 0;
        while(index < nums.length){
            int correct = nums[index] - 1;

            if(nums[index] > 0&& nums[index] <= nums.length  && nums[index] != nums[correct] ){
                swap(nums,index,correct);
            }else{
                index++;
            }
        }
   
        for(int i =0;i<nums.length;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return nums.length+1;
    }

    public static void swap(int[] arr, int start, int end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}