// https://leetcode.com/problems/sqrtx/
public class sqrt {
    public int mySqrt(int x) {
        long start = 0, end = x/2;
        if(x == 1){
            return x;
        }

        while(start <= end) {
        long mid = start + (end - start)/2;
           if(mid * mid == x){
            
            return Math.toIntExact(mid);
           }
            if(mid * mid > x){
                end = mid - 1;
            }else{
               start = mid+1;
            }
        }
        return Math.toIntExact(end);
    }
}
