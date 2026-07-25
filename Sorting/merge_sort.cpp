#include <bits/stdc++.h>
using namespace std;

// time complexity : O(nlogn)

// space complexity
// Auxiliary Array : O(n)
// Recursion Stack : O(log n)
// Overall : O(n)

void merge(vector<int>& arr, int low, int mid, int high) {

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {

        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {

    if(low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main() {

    vector<int> arr = {7, 3, 5, 2, 9, 1, 6, 4};

    mergeSort(arr, 0, arr.size() - 1);

    for(int x : arr)
        cout << x << " ";

    return 0;
}