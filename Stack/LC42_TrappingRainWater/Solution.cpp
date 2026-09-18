#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 0) {
            return 0;
        }

        int leftMax = 0;
        int rightMax = 0;

        int l = 0;
        int r = n - 1;

        int totalWater = 0;

        while (l < r) {

            if (height[l] <= height[r]) {

                if (leftMax > height[l]) {
                    totalWater += leftMax - height[l];
                } else {
                    leftMax = height[l];
                }

                l++;

            } else {

                if (height[r] < rightMax) {
                    totalWater += rightMax - height[r];
                } else {
                    rightMax = height[r];
                }

                r--;
            }
        }

        return totalWater;
    }
};

int main() {
    Solution solution;

    vector<int> height = {
        0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1
    };

    int result = solution.trap(height);

    cout << "Trapped Rain Water: " << result << endl;

    return 0;
}