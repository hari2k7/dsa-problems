#include <iostream>
using namespace std;

template <size_t N>

void insertionsort(int (&arr)[N]){
    for(size_t i=1; i<N; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main(){
    int arr[] = {8,6,4,7,5,1,3};
    insertionsort(arr);
    
    for(int i : arr){
        cout<<i<<" ";
    }
}