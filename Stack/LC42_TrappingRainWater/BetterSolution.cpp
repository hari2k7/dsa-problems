#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prefixMax(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n);

        pre[0] = height[0];

        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], height[i]);
        }

        return pre;
    }

    vector<int> suffixMax(vector<int>& height) {
        int n = height.size();
        vector<int> suf(n);

        suf[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], height[i]);
        }

        return suf;
    }

    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 0) {
            return 0;
        }

        vector<int> leftMax = prefixMax(height);
        vector<int> rightMax = suffixMax(height);

        int totalWater = 0;

        for (int i = 0; i < n; i++) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution solution;

    int result = solution.trap(height);

    cout << "Trapped water: " << result << endl;

    return 0;
}