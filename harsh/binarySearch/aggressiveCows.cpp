#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& locations, int mid, int cows) {
    int usedCows = 1;  
    int lastPlaced = locations[0];

    for (int i = 1; i < locations.size(); i++) {
        if (locations[i] - lastPlaced >= mid) {
            usedCows++;
            lastPlaced = locations[i];
        }
        if (usedCows == cows) return true;
    }
    return false;
}

int getMiniMax(vector<int>& locations, int cows) {
    int low = 1;  
    int high = locations.back() - locations.front();  
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(locations, mid, cows)) {
            ans = mid;  
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int testCases;
    cout<<"Enter number of test Cases"<<endl;
    cin >> testCases;

    while (testCases--) {
        int locationsCount, cows;
        cout<<"Enter locationCount and cows space seperated"<<endl;
        cin >> locationsCount >> cows;
        vector<int> locations(locationsCount);
        cout<<"Enter "<<locationsCount<<" location points"<<endl;
        for (int i = 0; i < locationsCount; i++)
            cin >> locations[i];

        sort(locations.begin(), locations.end());  
        cout<<"Outpur for test case "<<testCases + 1<<endl;
        int ans = getMiniMax(locations, cows);
        cout << ans << endl;
    }
    return 0;
}
