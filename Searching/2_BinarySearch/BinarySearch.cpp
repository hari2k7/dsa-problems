#include <iostream>
using namespace std;

template <size_t N>

int binarysearch(int (&arr) [N], int key){
    int low = 0;
    int high = N - 1;

    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==key){
            return mid;
        }else if(key<arr[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2,4,6,8,9};
    cout<<binarysearch(arr,9);
}