#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> nextGreaterElements(vector<int> nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
                st.push(nums[i]);
            }else {
                ans[i] = st.top();
                st.push(nums[i]);
            }
        }
        return ans;
    }
};

int main() {

    vector<int> nums = {1,3,2,4};

    Solution solution;
    vector<int> ans = solution.nextGreaterElements(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}