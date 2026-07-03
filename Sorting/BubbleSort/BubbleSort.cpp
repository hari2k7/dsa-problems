#include <iostream>
using namespace std;

template <size_t N>

void bubblesort(int (&arr)[N]){
    for(int i=N; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {6,8,1,3,5};
    bubblesort(arr);
    for(int i: arr){
        cout<<i<<" ";
    }
}