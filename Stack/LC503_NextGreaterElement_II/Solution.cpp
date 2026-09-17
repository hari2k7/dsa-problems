/*
    Problem: Next Greater Element II
    LeetCode: 503
    Difficulty: Medium
    Topic: Array, Stack, Monotonic Stack

    Problem Statement:
    Given a circular integer array nums, return the next greater
    number for every element.

    The next greater number of an element x is the first number
    greater than x that appears while traversing the array circularly.
    If no greater number exists, return -1 for that position.

    Approach:
    Treat the circular array as if it were traversed twice.

    1. Iterate from 2*n - 1 down to 0.
    2. Use i % n to access elements circularly.
    3. Maintain a monotonic decreasing stack of possible next
       greater elements.
    4. Remove all elements from the stack that are less than or
       equal to the current element.
    5. For the first n positions, the top of the stack is the
       next greater element if the stack is not empty.
    6. Push the current element into the stack.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }

            st.push(curr);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> ans = solution.nextGreaterElements(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}