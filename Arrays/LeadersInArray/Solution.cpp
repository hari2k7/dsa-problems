#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> LeadersInArray(vector<int>& nums) {
        
        vector<int> ans;
        int maximum = INT_MIN;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]>maximum){
                maximum = nums[i];
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    Solution obj;

    vector<int> result = obj.LeadersInArray(nums);

    cout << "Leaders: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
