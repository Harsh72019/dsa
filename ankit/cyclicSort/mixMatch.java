
public class mixMatch {
    public int[] findErrorNums(int[] nums) {
        int index = 0;

        while (index < nums.length) {
            int correct = nums[index] - 1;
            if (nums[index] != nums[correct]) {
                swap(nums, index, correct);
            } else {
                index++;
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return new int[]{nums[i], i + 1};
            }
        }

        return new int[]{-1, -1};
    }

    public static void swap(int[] arr, int start, int end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
}
