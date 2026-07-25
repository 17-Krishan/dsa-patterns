#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();

    vector<int> output(n);
    vector<int> cnt(10, 0);

    // Count occurrences of current digit
    for (int x : arr) {
        int digit = (x / exp) % 10;
        cnt[digit]++;
    }

    // Prefix sums
    for (int i = 1; i < 10; i++) {
        cnt[i] += cnt[i - 1];
    }

    // Build output array (right to left for stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[cnt[digit] - 1] = arr[i];
        cnt[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    int mx = *max_element(arr.begin(), arr.end());

    for (int exp = 1; mx / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}

// TC: O(n)
// SC: O(n)