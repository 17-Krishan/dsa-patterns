#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = -1;
    int count = 0;

    for (int x : nums) {
        if (count == 0) {
            candidate = x;
            count = 1;
        }
        else if (x == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    count = 0;
    for (int x : nums) {
        if (x == candidate) count++;
    }

    if (count > nums.size() / 2)
        return candidate;

    return -1; // no majority element
}