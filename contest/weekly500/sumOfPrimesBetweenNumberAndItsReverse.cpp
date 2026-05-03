#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rev(int n){
        int x = 0;
        while(n > 0){
            x = x * 10 + (n % 10);
            n /= 10;
        }
        return x;
    }
    
    int sumOfPrimesInRange(int n) {
        int r = rev(n);

        int mini = min(n, r);
        int maxi = max(n, r);

        if(maxi < 2) return 0;

        vector<bool> prime(maxi + 1, true);
        prime[0] = prime[1] = false;

        for(int i = 2; i * i <= maxi; i++){
            if(prime[i]){
                for(int j = i * i; j <= maxi; j += i){
                    prime[j] = false;
                }
            }
        }

        int sum = 0;

        for(int i = mini; i <= maxi; i++){
            if(prime[i]){
                sum += i;
            }
        }

        return sum;
    }
};