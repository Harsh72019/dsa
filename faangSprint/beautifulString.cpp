#include <bits/stdc++.h>
using namespace std;

int makeBeautiful(string str) {
    int n = str.size();

    int changes1 = 0;
    int changes2 = 0; 

    for (int i = 0; i < n; i++) {
        char expected1 = (i % 2 == 0) ? '0' : '1';
        char expected2 = (i % 2 == 0) ? '1' : '0';

        if (str[i] != expected1) changes1++;
        if (str[i] != expected2) changes2++;
    }

    return min(changes1, changes2);
}

int main(){
    string str = "0101010";
    cout<<makeBeautiful(str)<<endl;
    return 0;
}