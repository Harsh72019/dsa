#include<bits/stdc++.h>
using namespace std;






void merger(vector<int> &arr , int low , int mid , int high){
    vector<int> temp(high - low + 1);
    int i = low , j = mid + 1 , k = 0;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    for(int i = low ; i <= high ; i++){
        arr[i] = temp[i - low];
    }
    
}

void mergeSort(vector<int> &arr , int low , int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr , low , mid);
        mergeSort(arr , mid + 1 , high);
        merger(arr , low , mid , high);
    }
}


int main(){
    vector<int> arr = {5 , 4 , 3 , 2 , 1};
    mergeSort(arr , 0 , 4);
    for(auto x : arr){
        cout << x << " ";
    }
    return 0;
}

