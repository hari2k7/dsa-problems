/*
    Problem: Asteroid Collision
    LeetCode: 735
    Difficulty: Medium
    Topic: Array, Stack, Simulation

    Problem Statement:
    We are given an array of asteroids moving in a straight line.
    The absolute value represents the size of an asteroid and the
    sign represents its direction.

    Positive -> moving right
    Negative -> moving left

    When two asteroids collide:
    - The smaller asteroid is destroyed.
    - If both have the same size, both are destroyed.
    - Asteroids moving in the same direction never collide.

    Return the state of the asteroids after all collisions.

    Approach:
    Use a stack to simulate asteroid collisions.

    Positive asteroids are directly pushed into the stack.
    For a negative asteroid, compare it with positive asteroids
    at the top of the stack and remove smaller asteroids.
    If both have the same size, both are removed.
    If the negative asteroid survives, push it into the stack.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() && st.top()>0 &&st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i])){
                    st.pop();
                }else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = sol.asteroidCollision(asteroids);

    cout << "[";

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];

        if(i != ans.size() - 1){
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}