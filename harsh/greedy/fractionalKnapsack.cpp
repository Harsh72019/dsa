#include<bits/stdc++.h>
using namespace std;


double fractionalKnapsack(vector<pair<int , int>> items , int weight)
{
    sort(items.begin() , items.end() , [&](pair<int , int> &a , pair<int , int> &b){
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;
        return r1 > r2;
    });    
    double maximumValue = 0.0;
    for(auto i :  items)
    {
        if(weight >= i.second)
        {
            weight -= i.second;
            maximumValue += i.first;
        }
        else{
            maximumValue += ((double)i.first / i.second) * weight;
            break;
        }
    }
    return maximumValue;
}

int main()
{
    vector<pair<int , int>> items = {{100 , 20} , {60 , 10} , {100 , 50} , {200 , 50}};
    int weight = 90;
    cout<<fractionalKnapsack(items , weight)<<endl;
    return 0;
}