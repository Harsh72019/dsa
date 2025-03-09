// ! When the given number is between the range of 1 to N then always use cyclic sort. Remember there is no values should be skipped between the ranges


//*  eg -  {7,3,5,2,1,4,6} with index 0,1,2,3,4,5,6 :- so number 7 sould be at index 6 and number 3 should be index 2,; Hence we can say that correct place should be at arr[index] -1  */

// package ankit.cyclicSort;

public class CyclicSort {
    public static void main(String[] args) {
        int[] arr = {7,3,5,2,1,4,6};

        int index = 0;
        while(index < arr.length){
            if(index != arr[index] -1){   // If the value of index is not at the right place
                int temp = arr[index];   // Storing the value of index at temp
                arr[index] = arr[temp-1]; // The value of index sould be at temp - 1
                arr[temp -1 ] = temp; // Insert the value at the right place
            }else{
                index++;    // Increment index
            }
        }

        System.out.println("Sorted Array: " + java.util.Arrays.toString(arr));
    }
}
