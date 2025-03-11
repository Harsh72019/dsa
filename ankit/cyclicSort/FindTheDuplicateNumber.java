public class FindTheDuplicateNumber {
    public int findDuplicate(int[] nums) {
        int index = 0;

        while(index < nums.length){

            if(nums[index] != index+1){
                // value is not at correct place,  sort needed
                int correct = nums[index]-1;

                if(nums[index] == nums[correct]){
                    //Correct value is alraedy present at that index, means that particular value is repeated.
                    return nums[index];
                }
                else{
                    //Swap it
                    int temp = nums[index];
                    nums[index] = nums[correct];
                    nums[correct] = temp;
                }

            }else{
                // value is at correct place, no sort needed
                index++;
            }
        }
        return -1;
    }
}
