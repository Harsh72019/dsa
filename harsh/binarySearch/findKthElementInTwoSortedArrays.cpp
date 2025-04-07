#include <bits/stdc++.h>
using namespace std;

 int kthElement(vector<int>& a, vector<int>& b, int k) {
        int index1 = 0 ;
        int index2 = 0 ;
        int counter = 0;
        while(index1 < a.size() && index2 < b.size())
        {
            if(a[index1] < b[index2])
            {
                counter++;
                if(counter == k)
                    return a[index1];
                index1++;    
            }
            else
            {
                counter++;
                if(counter == k)
                    return b[index2];
                index2++;
            }
        }
        while(index1  < a.size())
        {
            counter++;
            if(counter == k)
                return a[index1];
            index1++;    
        }
        while(index2 < b.size())
        {
            counter++;
            if(counter == k)
                return b[index2];
            index2++;
        }
        return -1;
    }