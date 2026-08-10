#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, i=0 , maxsum = INT_MIN;
        int n = nums.size();
        while(i<n){
            sum += nums[i];
            maxsum = max(maxsum,sum);
            if(sum<0) sum =0;
            i++;
        }
        return maxsum;
    }
};

int main() { 
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    Solution obj; 
    int result = obj.maxSubArray(nums); 
    cout << "Maximum subarray sum: " << result << endl; 
    return 0; 
}