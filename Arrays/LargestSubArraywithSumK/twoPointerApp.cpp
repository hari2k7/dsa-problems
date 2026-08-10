#include <bits/stdc++.h>
using namespace std;

int solution(vector<int>& arr, long long k){
    int n = arr.size();
    long long sum = arr[0];
    int left = 0, right = 0;
    int len = 0;

    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            len = max(len, right - left + 1);
        }

        right++;
        if(right < n){
            sum+=arr[right];
        }
    }

    return len;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int result = solution(arr, k);

    cout << "Longest subarray length: " << result << endl;

    return 0;
}