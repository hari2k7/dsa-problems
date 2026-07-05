#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& arr) {
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    int l = 0, r = 0, i = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] < rightArray[r]) {
            arr[i] = leftArray[l];
            l++;
        } else {
            arr[i] = rightArray[r];
            r++;
        }
        i++;
    }

    while (l < leftSize) {
        arr[i] = leftArray[l];
        l++;
        i++;
    }

    while (r < rightSize) {
        arr[i] = rightArray[r];
        r++;
        i++;
    }
}

void mergeSort(vector<int>& arr) {
    int length = arr.size();

    if (length <= 1)
        return;

    int mid = length / 2;

    vector<int> leftArray(mid);
    vector<int> rightArray(length - mid);

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (i < mid)
            leftArray[i] = arr[i];
        else
            rightArray[j++] = arr[i];
    }

    mergeSort(leftArray);
    mergeSort(rightArray);

    merge(leftArray, rightArray, arr);
}

int main() {
    vector<int> arr = {9, 6, 7, 2, 3, 8};

    mergeSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}