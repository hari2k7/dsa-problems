#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr, int k){
    int size = arr.size();
    int len = 0;
    map<long long, int> preSum;
    long long sum = 0;

    for(int i=0; i<size; i++){
        sum+=arr[i];

        if(sum == k){
            len = max(len, i+1);
        }

        long long r = sum - k;

        if(preSum.find(r) != preSum.end()){
            len = max(len, i - preSum[r]);
        }

        if (preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
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