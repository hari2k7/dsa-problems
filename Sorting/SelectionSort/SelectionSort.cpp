#include<iostream>
using namespace std;

template <size_t N>

void Selectionsort(int (&arr)[N]){
    for(int i=0; i<N-1; i++){
        int min = i;
        for(int j=i+1; j<N; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[] = {4,9,1,8,3,6};
    Selectionsort(arr);

    for(int i: arr){
        cout<<i<<" ";
    }

    return 0;
}