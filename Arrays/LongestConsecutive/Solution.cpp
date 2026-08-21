#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c=0, lastsmall = INT_MIN, longest=1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]-1 == lastsmall){
                c++;
                lastsmall = nums[i];
            }else if(nums[i]!=lastsmall){
                c=1;
                lastsmall = nums[i];
            }
            longest = max(longest, c);
        }

        return longest;
    }
};

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    Solution obj;

    cout << "Longest consecutive sequence: "<<obj.longestConsecutive(nums);

    return 0;
}
