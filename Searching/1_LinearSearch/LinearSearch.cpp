#include <iostream>
using namespace std;

template <size_t N>

int linearsearch(int (&arr)[N], int key){
    for(int i=0; i<sizeof(arr); i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5,6,8,2,3};
    cout<<linearsearch(arr,8);
}