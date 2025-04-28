#include<bits/stdc++.h>
using namespace std;

double solver(double x , long long nn , double ans )
    {
        if(nn <= 0)
            return ans;
        if(nn % 2 == 1)
        {
            return solver(x , nn -1 , ans * x);
        }
        else
        {
            return solver(x*x , nn /2 , ans);
        }
    }
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; 
        if (nn < 0) nn = -1 * nn;
        ans  = solver(x , nn , ans);

        if (n < 0) ans = 1.0 / ans;  
        return ans;
    }