#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums) {
    vector<int> ans;
    int mini = nums.size() / 3;
    int cnt0 = 0, cnt1 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt0 == 0 && nums[i] != el2)
        {
            cnt0 = 1;
            el1 = nums[i];
        }
        else if (cnt1 == 0 && nums[i] != el1)
        {
            cnt1 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
        {
            cnt0++;
        }
        else if (nums[i] == el2)
        {
            cnt1++;
        }
        else
        {
            cnt1--;
            cnt0--;
        }
    }
    cnt0 = 0;
    cnt1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
        {
            cnt0++;
        }
        if (nums[i] == el2)
        {
            cnt1++;
        }
    }
    if (cnt0 > mini)
        ans.push_back(el1);
    if (cnt1 > mini)
        ans.push_back(el2);
    return ans;
}