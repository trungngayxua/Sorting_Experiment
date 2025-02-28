#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Hàm chọn pivot là median-of-three
int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    return arr[mid];
}

// Hàm partition
int partition(vector<int>& arr, int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1, j = high + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

// Quicksort đệ quy
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int test = 0; test < 10; test++) {
        vector<int> arr(1000000);
        for(int i = 0; i < 1000000; ++i) cin >> arr[i];
        quickSort(arr, 0, arr.size() - 1);
    }
    
    return 0;
}
