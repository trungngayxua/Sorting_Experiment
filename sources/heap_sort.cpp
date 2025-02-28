#include <bits/stdc++.h>
using namespace std;

// Hàm Heapify để duy trì tính chất của Heap
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Gốc của Heap
    int left = 2 * i + 1;   // Con trái
    int right = 2 * i + 2;  // Con phải

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Xây dựng Max Heap (từ dưới lên)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Trích xuất từng phần tử lớn nhất ra ngoài và Heapify lại
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    for (int test = 0; test < 10; test++) {
        vector<int> arr(1'000'000);
        for (int i = 0; i < 1'000'000; i++) cin >> arr[i];
    
        heapSort(arr);
    }
    return 0;
}
