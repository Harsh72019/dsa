#include<bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    vector<pair<int , int>> trains;

    for(int i = 0 ; i < Arrival.size() ; i++) {
        trains.push_back({Arrival[i] , Departure[i]});  
    }

    sort(trains.begin(), trains.end());  
    unordered_map<int , int> um;
    
    int platforms = 1;
    um[platforms] = trains[0].second;

    for(int i = 1 ; i < trains.size() ; i++) {
        auto& train = trains[i];
        bool trainSettled = false;

        for(int j = 1 ; j <= platforms ; j++) {
            if(um[j] < train.first) {
                um[j] = train.second;
                trainSettled = true;
                break; 
            }
        }

        if(!trainSettled) {
            um[++platforms] = train.second;
           
        }
    }

    return platforms;
}

// optimized find platform

int findPlatformOptimized(vector<int>& Arrival, vector<int>& Departure) {
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());
    int platforms = 1, n = Arrival.size();
    int i = 1, j = 0;
    while (i < n && j < n) {
        if (Arrival[i] < Departure[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    return platforms;
}

int main() {
    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};
    cout << findPlatform(Arrival , Departure) << endl;
    return 0;
}
