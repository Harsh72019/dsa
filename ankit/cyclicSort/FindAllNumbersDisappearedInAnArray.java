// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
import java.util.ArrayList;
import java.util.List;

public class FindAllNumbersDisappearedInAnArray {
     public List<Integer> findDisappearedNumbers(int[] nums) {
        int index = 0;
        while(index < nums.length ){
            int correct = nums[index] -1;
           if(nums[index] != nums[correct]){
            int temp = nums[index];
            nums[index] = nums[correct];
            nums[correct] = temp;
           }else{
            index++;
           }
        }

        List<Integer> ans = new ArrayList();

        for(int i =0 ;i<nums.length;i++){
            if(nums[i] != i+1){
                ans.add(i+1);
            }
        }

        return ans;
    }
}
