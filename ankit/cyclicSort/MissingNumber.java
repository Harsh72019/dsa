// package ankit.cyclicSort;
/**  
 * https://leetcode.com/problems/missing-number/
 */
public  class MissingNumber {
    public int missingNumber(int[] nums) {
        int index = 0;
        while(index < nums.length){
            if(index != nums[index] && nums[index] < nums.length){
                int temp = nums[index];
                nums[index] = nums[temp];
                nums[temp] = temp;
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
}
