/*
    Problem: Sum of Subarray Minimums
    LeetCode: 907
    Difficulty: Medium
    Topic: Array, Stack, Monotonic Stack

    Problem Statement:
    Given an array of integers arr, find the sum of the minimum
    value of every subarray of arr.

    Return the sum modulo 10^9 + 7.

    Approach:
    For every element arr[i], calculate how many subarrays have
    arr[i] as their minimum.

    We find:
    1. NSE (Next Smaller Element):
       The first element to the right that is smaller than arr[i].

    2. PSEE (Previous Smaller or Equal Element):
       The first element to the left that is smaller than or equal
       to arr[i].

    If:
        left  = i - PSEE[i]
        right = NSE[i] - i

    Then arr[i] is the minimum in:
        left * right

    subarrays.

    Contribution of arr[i]:
        arr[i] * left * right

    We use a monotonic increasing stack to find NSE and PSEE.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Next Smaller Element
    vector<int> findNSE(vector<int> arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }

    // Previous Smaller or Equal Element
    vector<int> findPSEE(vector<int> arr) {
        int n = arr.size();

        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {

        long long total = 0;
        const long long modulo = 1e9 + 7;

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        for (int i = 0; i < arr.size(); i++) {

            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total +
                     (left * 1LL * right * arr[i]) % modulo)
                    % modulo;
        }

        return total;
    }
};

int main() {

    Solution sol;

    vector<int> arr = {3, 1, 2, 4};

    int ans = sol.sumSubarrayMins(arr);

    cout << "Sum of Subarray Minimums: " << ans << endl;

    return 0;
}