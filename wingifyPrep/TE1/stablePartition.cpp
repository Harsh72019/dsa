#include <bits/stdc++.h>

using namespace std;


void reverse(vector<int>& arr, int l, int r) {
    while (l < r) {
        swap(arr[l++], arr[r--]);
    }
}

// The "In-Place" merge that swaps internal blocks
void merge(vector<int>& arr, int l, int mid, int r) {
    int i = l;
    // 1. Find the first negative in the left half
    while (i <= mid && arr[i] >= 0) i++;
    
    int j = mid + 1;
    // 2. Find the first negative in the right half
    while (j <= r && arr[j] >= 0) j++;

    reverse(arr, i, mid);
    reverse(arr, mid + 1, j - 1);
    reverse(arr, i, j - 1);
}

void divideAndConquer(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;
    divideAndConquer(arr, l, mid);
    divideAndConquer(arr, mid + 1, r);
    
    merge(arr, l, mid, r);
}

int main() {
    vector<int> question = {2, -3, 4, -1, 6, -9};
    
    divideAndConquer(question, 0, question.size() - 1);
    
    for (int x : question) cout << x << " ";
    return 0;
}