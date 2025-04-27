#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n <= 2) return 0;  
    
    vector<bool> arr(n, true);  
    arr[0] = arr[1] = false;   
    
    int counter = 0;
    for (int i = 2; i * i < n; i++) { 
        if (arr[i]) {  
            for (int j = i * i; j < n; j += i) {  
                arr[j] = false;  
            }
        }
    }
    
    
    for (int i = 2; i < n; i++) {
        if (arr[i]) {
            counter++;
        }
    }
    
    return counter;
}