class StrictSortedMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix .length;
        int cols = matrix[0].length;

        if(target < matrix[0][0] || target > matrix[rows-1][cols-1]){
            return false;
        }

// first and last element
        int start = 0 , end = rows * cols -1;
        while(start <= end){
            int mid = start + (end - start)/2;

            //For 2D array
            int midValue = matrix[mid/cols][mid % cols];

            if(midValue == target){
                return true;
            }else if(midValue < target){
                start = mid +1;
            }else{
                end = mid -1;
            }

        }
        return false;

    }
}