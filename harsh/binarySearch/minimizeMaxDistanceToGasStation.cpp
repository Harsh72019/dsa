#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(vector<int>& stations, int k, double mid) {
            int count = 0;
            for (int i = 1; i < stations.size(); i++) {
                double gap = stations[i] - stations[i - 1];
                count += (int)(gap / mid);  
            }
            return count <= k;
        }
    
        double minmaxGasDist(vector<int>& stations, int k) {
            double low = 0;
            double high = stations.back() - stations.front();
            double epsilon = 1e-6;
    
            while (high - low > epsilon) {
                double mid = (low + high) / 2.0;
                if (isPossible(stations, k, mid)) {
                    high = mid;  
                } else {
                    low = mid;   
                }
            }
    
            return low;
        }
    };
    