#include<bits/stdc++.h>
using namespace std;


bool checkValid(string&small, string&large){
        int ns = small.size(), nl = large.size();
        if(nl - ns != 1) return false;
        int is = 0, il = 0;
        while(is<ns && il<nl){
            if(small[is] == large[il]) is += 1;
            il += 1;
        }
        if(is >= ns) return true;
        return false;
    }
    static bool StringComparator(string&s1, string&s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), StringComparator);
        int n = words.size();
        vector<int> size(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(checkValid(words[j], words[i]) &&
                1+size[j] > size[i]) 
                    size[i] = 1 + size[j];
            }
        }
        return * max_element(size.begin(), size.end());
    }