// https://leetcode.com/problems/guess-number-higher-or-lower/submissions/1557447800/

public class GuessNumberHigherOrLower {
    /** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int start = 0 , end = n;

        while( start <= end){
            int mid = start + (end - start)/2;
            int ans = guess(mid);
            System.out.println(mid);
            if(ans == 0){
                return mid;
            }
            else if(ans == -1){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
  return -1;
    }
}