#include<iostream>
using namespace std;

void mergeSort(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1];
    int right[n2];
    for(int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for(int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }
    int I = 0, j = 0, k = low;
    while(I < n1 && j < n2) {
        if(left[I] <= right[j]) { // Corrected condition
            arr[k] = left[I]; I++; k++;
        } else {
            arr[k] = right[j]; j++; k++; 
        }
    }
    while(I < n1) {
        arr[k] = left[I]; I++; k++;
    }
    while(j < n2) {
        arr[k] = right[j]; j++; k++;
    }
}

int main() {
    int arr[] = {1, 3, 9, 7, 8, 14, 20};
    int low = 0, mid = 2, high = 6; // Corrected high value
    mergeSort(arr, low, mid, high);
    for(int I = 0; I < 7; I++) { // Corrected loop size and variable
        cout << arr[I] << " "; // Corrected variable name
    }
    return 0;
}