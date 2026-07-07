#include <bits/stdc++.h>
using namespace std;

template <size_t N>

int SecondLargest(int (&arr) [N]){
    int largest = arr[0];
    int second_largest = INT_MIN;
    
    for(int i=0; i<N; i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest =  arr[i];
        }else if(arr[i] > second_largest && arr[i] != largest){
            second_largest = arr[i];
        }
    }

    return second_largest;
}

int main(){
    int arr[] = {9,3,8,6,8,6,5};
    cout<<SecondLargest(arr);
}