/*
Problem:
Find the largest element in an array.

Approach:
- Assume the first element is the largest.
- Traverse the array once.
- Update the largest whenever a greater element is found.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>

int largestNum(int (&arr) [N]){
    int largest = arr[0];
    for(int i=1; i<N; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    return largest;
}

int main(){
    int arr[] = {9,3,8,6,8,6,5};
    cout<< largestNum(arr);
}