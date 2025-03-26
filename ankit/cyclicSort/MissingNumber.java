// package ankit.cyclicSort;
/**  
 * https://leetcode.com/problems/missing-number/
 */
public  class MissingNumber {
    public int missingNumber(int[] nums) {
        int index = 0;
        while(index < nums.length){
            int correct = nums[index];
            if(nums[index] < nums.length && nums[correct] != nums[index]){
                swap(nums,index,correct);
            }else{
                index++;
            }
        }

        for(int  i =0 ; i<nums.length;i++){
            if(i != nums[i]){
                return i;
            }
        }



        return nums.length;
    }

    public static void swap(int[]arr , int first , int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}


