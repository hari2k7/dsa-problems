#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxSubArray(vector<int> nums){
        int sum = 0, i=0, maxSum = INT_MIN,start = 0, ansStart, ansEnd;
        int n = nums.size();

        while(i<n){
            if(sum==0) start = i;
            sum += nums[i];
            if(sum>maxSum){
                maxSum = sum;
                ansStart = start, ansEnd = i;
            }
            if(sum<0) sum=0;
            i++;
        }
        for(int i=ansStart; i<=ansEnd; i++){
            cout<<nums[i]<<" ";
        }
        return maxSum;
    }
};

int main() { 
    vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    Solution obj; 
    int result = obj.maxSubArray(nums); 
    cout << "\nMaximum subarray sum: " << result << endl; 
    return 0; 
}