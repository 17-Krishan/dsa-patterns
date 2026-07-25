#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> freq(mx + 1, 0);

    for(int x : arr)
        freq[x]++;

    int idx = 0;

    for(int val = 0; val <= mx; val++) {
        while(freq[val]--) {
            arr[idx++] = val;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    for(int x : arr)
        cout << x << " ";
}


// stable version code..
// void countingSort(vector<int>& arr) {
//     int mx = *max_element(arr.begin(), arr.end());

//     vector<int> cnt(mx + 1, 0);

//     for(int x : arr)
//         cnt[x]++;

//     for(int i = 1; i <= mx; i++)
//         cnt[i] += cnt[i - 1];

//     vector<int> output(arr.size());

//     for(int i = arr.size() - 1; i >= 0; i--) {
//         output[cnt[arr[i]] - 1] = arr[i];
//         cnt[arr[i]]--;
//     }

//     arr = output;
// }

// Complexity

// Let:

// n = number of elements
// k = maximum value
// Time:O(n+k)
// Space:O(k)

// For stable version:

// Space:O(n+k)
// because of the output array.