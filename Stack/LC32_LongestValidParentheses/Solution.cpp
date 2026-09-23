/*
    Problem: Longest Valid Parentheses
    LeetCode: 32
    Difficulty: Hard
    Topic: String, Stack, Dynamic Programming

    Problem Statement:
    Given a string s containing just the characters '(' and ')',
    find the length of the longest valid (well-formed) parentheses
    substring.

    Approach:
    Use a stack to store indices.

    - Initially push -1 as a base index.
    - For every '(' push its index onto the stack.
    - For every ')', pop the top index.
    - If the stack becomes empty, push the current index as the
      new base index.
    - Otherwise, the length of the current valid substring is:
          i - st.top()
      Update the maximum length accordingly.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int l = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }else{
                    l = max(l, i-st.top());
                }
            }
        }

        return l;
    }
};

int main() {
    Solution obj;

    string s = ")()())";

    cout << "Longest Valid Parentheses: "
         << obj.longestValidParentheses(s) << endl;

    return 0;
}